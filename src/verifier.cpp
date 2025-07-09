#include "verifier.h"
#include <iostream>
#include <filesystem>
#include <unordered_set>


Verifier::Verifier(const std::string& path, bool is_recursive) {
    this->start_path = path;
    this->recursive = is_recursive;
    this->valid_pairs = 0;
    this->orphan_images = 0;
    this->directories_scanned = 0;
}


void Verifier::scan() {
    std::unordered_set<std::string> valid_extensions = {".png", ".jpg", ".webp", ".jpeg"};

    auto process_entry = [&](const std::filesystem::directory_entry& entry) {
        if (entry.is_regular_file() && valid_extensions.count(entry.path().extension().string())) {
            std::filesystem::path image_path = entry.path();
            std::filesystem::path txt_path = image_path;
            txt_path.replace_extension(".txt");

            if (std::filesystem::exists(txt_path)) {
                // This now increments the member variable.
                this->valid_pairs++;
            } else {
                // This now increments the member variable.
                this->orphan_images++;
                std::cout << "[ERROR] Orphan image found: " << image_path.string() << std::endl;
            }
        }
    };

    // The scan now uses the member variables set in the constructor.
    if (this->recursive) {
        for (const auto& entry : std::filesystem::recursive_directory_iterator(this->start_path)) {
            if (entry.is_directory()) {
                this->directories_scanned++;
            } else if (entry.is_regular_file()) {
                process_file(entry);
            }
        }
    } else {
        for (const auto& entry : std::filesystem::directory_iterator(this->start_path)) {
             if (entry.is_directory()) {
                this->directories_scanned++;
            } else if (entry.is_regular_file()) {
                process_file(entry);
            }
        }
    }
}


int Verifier::get_valid_pairs() const {
    return this->valid_pairs;
}

int Verifier::get_orphan_images() const {
    return this->orphan_images;
}