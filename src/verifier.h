#pragma once

#include <string>
#include <vector>

class Verifier {
public:
    Verifier(const std::string& path, bool is_recursive);

    // Main function that runs the scan.
    void scan();

    // These hold the results after the scan.
    int get_valid_pairs() const;
    int get_orphan_images() const;

private:
    // Internal variables to store the state and results.
    std::string start_path;
    bool recursive;
    int valid_pairs;
    int orphan_images;
    int directories_scanned;
}