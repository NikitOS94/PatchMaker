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

# Test 1
add_test (Test_1_Encrypt PatchMaker tests/test1/i1.txt tests/test1/i2.txt tests/test1/patch.txt)
set_tests_properties( Test_1_Encrypt PROPERTIES LABEL "TEST#1" )
add_test (Test_1_Decrypt PatchMaker tests/test1/i1.txt tests/test1/patch.txt tests/test1/output.txt)
set_tests_properties( Test_1_Decrypt PROPERTIES LABEL "TEST#1" )
add_test (Test_1_Compare_Outputs PatchMaker tests/test1/i2.txt tests/test1/output.txt)
set_tests_properties( Test_1_Decrypt PROPERTIES LABEL "TEST#1" )
# Test 2
add_test (Test_2_Encrypt PatchMaker tests/test2/i1.txt tests/test2/i2.txt tests/test2/patch.txt)
set_tests_properties( Test_2_Encrypt PROPERTIES LABEL "TEST#2" )
add_test (Test_2_Decrypt PatchMaker tests/test2/i1.txt tests/test2/patch.txt tests/test2/output.txt)
set_tests_properties( Test_2_Decrypt PROPERTIES LABEL "TEST#2" )
add_test (Test_2_Compare_Outputs PatchMaker tests/test2/i2.txt tests/test2/output.txt)
set_tests_properties( Test_2_Decrypt PROPERTIES LABEL "TEST#2" )
# Test 3
add_test (Test_3_Encrypt PatchMaker tests/test3/i1.txt tests/test3/i2.txt tests/test3/patch.txt)
set_tests_properties( Test_3_Encrypt PROPERTIES LABEL "TEST#3" )
add_test (Test_3_Decrypt PatchMaker tests/test3/i1.txt tests/test3/patch.txt tests/test3/output.txt)
set_tests_properties( Test_3_Decrypt PROPERTIES LABEL "TEST#3" )
add_test (Test_3_Compare_Outputs PatchMaker tests/test3/i2.txt tests/test3/output.txt)
set_tests_properties( Test_3_Decrypt PROPERTIES LABEL "TEST#3" )
# Test 4
add_test (Test_4_Encrypt PatchMaker tests/test4/i1.txt tests/test4/i2.txt tests/test4/patch.txt)
set_tests_properties( Test_4_Encrypt PROPERTIES LABEL "TEST#4" )
add_test (Test_4_Decrypt PatchMaker tests/test4/i1.txt tests/test4/patch.txt tests/test4/output.txt)
set_tests_properties( Test_4_Decrypt PROPERTIES LABEL "TEST#4" )
add_test (Test_4_Compare_Outputs PatchMaker tests/test4/i2.txt tests/test4/output.txt)
set_tests_properties( Test_4_Decrypt PROPERTIES LABEL "TEST#4" )
# Test 5
add_test (Test_5_Encrypt PatchMaker tests/test5/i1.txt tests/test5/i2.txt tests/test5/patch.txt)
set_tests_properties( Test_5_Encrypt PROPERTIES LABEL "TEST#5" )
add_test (Test_5_Decrypt PatchMaker tests/test5/i1.txt tests/test5/patch.txt tests/test5/output.txt)
set_tests_properties( Test_5_Decrypt PROPERTIES LABEL "TEST#5" )
add_test (Test_5_Compare_Outputs PatchMaker tests/test5/i2.txt tests/test5/output.txt)
set_tests_properties( Test_5_Decrypt PROPERTIES LABEL "TEST#5" )