#include <iostream>
#include <string>
#include "cli/CLI11.hpp"
#include "verifier.h"

int main(int argc, char** argv) {
    CLI::App app{"A command-line tool to verify dataset integrity."};

    std::string path;

    bool recursive = false;

    CLI11::App* scan_subcommand = app.add_subcommand("scan", "Scan a directory for asset pairs");

    scan_subcommand -> add_flag("-r, --recursive", recursive, "Scan subdirectories recursively");
    scan_subcommand -> add_option("path", path, "Path to the dataset directory.")->required();

    CLI11_PARSE(app, argc, argv);

    if (scan_subcommand->parsed()) {
        
        auto start_time = std::chrono::high_resolution_clock::now();

        Verifier verifier(path, recursive);

        verifier.scan();

        auto end_time = std::chrono::high_resolution_clock::now();

        auto duration = std::chrono::duration_cast<std::milliseconds>(end_time-start_time);

        std::cout << "\n================================" << std::endl;
        std::cout << "      Validation Summary" << std::endl;
        std::cout << "================================" << std::endl;
        std::cout << "Valid Asset Pairs:    " << verifier.get_valid_pairs() << std::endl;
        std::cout << "Orphan Images Found:  " << verifier.get_orphan_images() << std::endl;
        std::cout << "================================" << std::endl;
        std::cout << "Total Scan Time:     " << duration.count() << " ms" << std::endl;

    }


    return 0;
}