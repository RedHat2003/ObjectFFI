# CMake minimum version requirement
cmake_minimum_required(VERSION 3.10)

# Project name and language
project(PyTypeObjectProject C)

# Specify the C standard
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)

# Include directories
include_directories(include)

# Source files
set(SOURCES
    include/object.c
    main.c
)

# Define the executable
add_executable(main ${SOURCES})

