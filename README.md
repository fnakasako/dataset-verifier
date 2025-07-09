The Asset Ingestion & Validation CLI 🗂️

This initial project is designed to be a significant first step away from Python scripting and into the world of professional C++ application development. You will build a tangible, useful tool that solves a real-world problem in your future LoRA workflows, all while mastering the foundational C++ toolchain.

Philosophy & Educational Goals

The primary goal here is to shift your mindset from being a user of tools to a builder of tools. In Python, you might write a quick script to check a dataset. In C++, you will build a robust, high-performance, and distributable command-line application.

This project is designed to teach you:

The "Why" of Native Code: You will immediately feel the speed difference between a C++ program that can iterate through tens of thousands of files in a second and an equivalent Python script. This builds an intuitive appreciation for systems programming.

Self-Sufficiency: By the end, you will have a tool you built that you can use for every subsequent project. This creates a powerful feedback loop and sense of ownership.

Professional Workflow: You won't just write code in a single file. You will learn the professional software engineering loop: defining requirements, structuring a project, managing dependencies, compiling, debugging, and testing.

Core Technical Concepts Covered

C++ Standard Library: iostream for printing, string for text manipulation, vector for dynamic arrays, and especially <filesystem> for modern, object-oriented file I/O.

Application Lifecycle: The full cycle from writing .cpp source files to producing a runnable binary.

Build Systems (CMake): Defining executable targets, managing C++ standards (C++17), and—critically—finding and linking against a third-party library.

Dependency Management: Integrating an external library (CLI11) into your project, a universal task in software development.

Debugging (GDB): Learning how to diagnose a program that has crashed or is behaving incorrectly, a non-negotiable skill for C++.

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

Debug with GDB: Intentionally introduce a logic error (e.g., mishandle a path string). Compile the code with debug flags (-g in CMake) and use gdb ./dataset-verifier to run your program, set breakpoints in your validation logic, and inspect the state of your variables to find the bug.

Measuring Success & Portfolio Value

You'll know this project is successful when you can point it at a dataset of thousands of images and it provides an accurate report in milliseconds.

When you show this project, you're not just showing a simple program. You're demonstrating that you can:

Architect a Solution: You identified a workflow bottleneck and engineered a robust tool to solve it.

Manage Dependencies: You professionally integrated a third-party library into a compiled application.

Write Performant Code: You can articulate why this C++ tool is fundamentally more efficient than a script for this I/O-bound task.

This project becomes the first entry in your portfolio, telling a clear story: "I build my own high-performance tools."