The Asset Ingestion & Validation CLI 🗂️


Project Specification

Functional Requirements

The dataset-verifier tool must perform the following actions:

Scan a Directory: Accept a path to a directory as a primary input.

Recursive Search: Optionally, scan all subdirectories within the target directory.

Asset Pairing: For every image file (with extensions .png, .jpg, .jpeg, .webp), the tool must verify that a corresponding text file (.txt) with the exact same base name exists.

Error Reporting: The tool must report all "orphan" image files that are missing a caption file.

Summary Statistics: Upon completion, the tool must print a summary including:

Total directories scanned.

Total valid image assets found.

Total orphan images found.

Total processing time.

Command-Line Interface (CLI) Design

You will use the CLI11 library to create a professional and user-friendly CLI. The target interface should look like this:

Bash



# Scan a single directory

./dataset-verifier scan ./my_lora_dataset# Scan a directory and all its sub-folders

./dataset-verifier scan ./my_lora_dataset --recursive# Display help message

./dataset-verifier --help

The output should be clear and informative:

Scanning directory: ./my_lora_dataset...



[ERROR] Orphan image found: ./my_lora_dataset/images/001.png (missing .txt file)

[ERROR] Orphan image found: ./my_lora_dataset/images/007.webp (missing .txt file)



================================

Validation Summary

================================

Directories Scanned: 5

Valid Asset Pairs: 1,250

Orphan Images Found: 2

Total Scan Time: 52 ms

================================

Technical Requirements

Language: C++17 (to ensure availability of <filesystem>)

Build System: CMake (version 3.15+)

External Libraries:

CLI11: For command-line argument parsing.

Suggested Project Directory Structure

dataset-verifier/

├── CMakeLists.txt # Main CMake file

├── README.md # Project documentation

├── external/ # For external libraries

│ └── cli/ # CLI11 can be added as a submodule or downloaded here

└── src/

├── main.cpp # Main application entry point

└── verifier.cpp # Core verification logic

└── verifier.h # Header file for the verifier class

Step-by-Step Implementation Guide

Project Setup: Create the directory structure. Write your initial CMakeLists.txt file. Define your executable target and set the C++ standard to 17.

Integrate CLI11: Add CLI11 to your external directory. Modify your CMakeLists.txt to add its directory (add_subdirectory(external/cli)) and link it to your executable (target_link_libraries(dataset-verifier PRIVATE CLI11::CLI11)).

Build the CLI: In main.cpp, use CLI11 to set up the scan command, the positional <path> argument, and the optional --recursive flag.

Implement the Scanner: Create a Verifier class. In verifier.cpp, write the core scanning logic using std::filesystem::directory_iterator or recursive_directory_iterator.

Add Validation Logic: For each file found, check its extension. If it's an image, construct the expected .txt filename and use std::filesystem::exists() to check for it. Store any orphans in a std::vector<std::string>.

Generate the Report: After the scan is complete, print the formatted summary statistics to the console.

