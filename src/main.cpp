#include <iostream>
#include "cli/CLI11.hpp"

int main(int argc, char** argv) {
    CLI::App app{"A command-line tool to verify dataset integrity."};

    std::string path;

    bool recursive = false;

    CLI11::App* scan_subcommand = app.add_subcommand("scan", "Scan a directory for asset pairs");

    scan_subcommand -> add_flag("-r, --recursive", recursive, "Scan subdirectories recursively");
    scan_subcommand -> add_option("path", path, "Path to the dataset directory.")->required();

    CLI11_PARSE(app, argc, argv);

    std::cout << "Program setup complete. Ready for logic." << std::endl;

    return 0;
}