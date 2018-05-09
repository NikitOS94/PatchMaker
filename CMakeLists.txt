cmake_minimum_required(VERSION 3.9)
project(PatchMaker)

# Version of program
set (PatchMaker_VERSION_MAJOR 1)
set (PatchMaker_VERSION_MINOR 0)

set(CMAKE_CXX_STANDARD 14)

# Files for building program
set(SOURCES main.cpp picosha2.h)

add_executable(PatchMaker ${SOURCES})

include(CTest)
enable_testing()

# test with empty first file
add_test (TestWithEmptyFilesEncrypt PatchMaker tests/test1/i1.txt tests/test1/i2.txt tests/test1/patch.txt GROUP test1)
set_tests_properties( TestWithEmptyFilesEncrypt PROPERTIES LABEL "TEST#1" )
add_test (TestWithEmptyFilesDecrypt PatchMaker tests/test1/i1.txt tests/test1/patch.txt tests/test1/output.txt)
set_tests_properties( TestWithEmptyFilesDecrypt PROPERTIES LABEL "TEST#1" )

# does it handle negative numbers
#add_test (TutorialNegative Tutorial -25)
#set_tests_properties (TutorialNegative PROPERTIES PASS_REGULAR_EXPRESSION "-25 is 0")
# does it handle small numbers
#add_test (TutorialSmall Tutorial 0.0001)
#set_tests_properties (TutorialSmall PROPERTIES PASS_REGULAR_EXPRESSION "0.0001 is 0.01")
# does the usage message work?
#add_test (TutorialUsage Tutorial)
#set_tests_properties (TutorialUsage PROPERTIES PASS_REGULAR_EXPRESSION "Usage:.*number")