cmake_minimum_required(VERSION 3.9)
project(Comparator)

# Version of program
set (PatchMaker_VERSION_MAJOR 1)
set (PatchMaker_VERSION_MINOR 0)

set(CMAKE_CXX_STANDARD 14)

# Files for building program
set(SOURCES comparator.cpp)

add_executable(Comparator ${SOURCES})