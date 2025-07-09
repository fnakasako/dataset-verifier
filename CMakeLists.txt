cmake_minimum_required(VERSION 3.15)

project(DatasetVerifier LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

ADD_EXECUTABLE(dataset_verifier src/main.cpp;
src/verifier.cpp)

target_include_directories(dataset_verifier external)