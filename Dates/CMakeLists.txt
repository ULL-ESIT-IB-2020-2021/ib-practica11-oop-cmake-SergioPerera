
cmake_minimum_required(VERSION 3.1)  # Mandatory

# set the project name 
project(compiled_dates                # Mandatory
    VERSION 1.0
    DESCRIPTION "Program to store dates"
    LANGUAGES CXX)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 14) 						# Use c++14
set(CMAKE_CXX_STANDARD_REQUIRED True)

# tell cmake to output binaries here:
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

# Debug and release flags
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

# tell cmake where to look for *.h files
include_directories(${PROJECT_SOURCE_DIR}/src)

# create library " libtools "
add_library(tools src/tools.cc)

# Adds an executable target called "compiled_dates" to be built from the source files listed in the command invocation.
add_executable(compiled_dates
    src/dates.cc
    src/dates.h
    src/tools.cc
    src/tools.h)

# tell the linker to bind these objects together
# It's important to place target_link_libraries after the add_executable and find_package lines, so all linked components are known.
target_link_libraries(compiled_dates tools)

# Add expected compiler features to a target.
target_compile_features(compiled_dates PRIVATE cxx_std_14)

# Add compile options to a target.
target_compile_options(compiled_dates PRIVATE -Wall -Wextra -Wpedantic)
