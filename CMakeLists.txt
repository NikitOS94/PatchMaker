cmake_minimum_required(VERSION 3.9)
project(PatchMaker)

# Version of program
set(PatchMaker_VERSION_MAJOR 1)
set(PatchMaker_VERSION_MINOR 0)

set(CMAKE_CXX_STANDARD 14)

# Files for building program
set(SOURCES main.cpp)

add_executable(PatchMaker ${SOURCES})

add_subdirectory(tests)

include(CTest)
enable_testing()

#define a macro to simplify adding tests
macro(SimpleTest testID)
    add_test(Test_${testID}_Generate_Patch PatchMaker tests/test${testID}/i1.txt tests/test${testID}/i2.txt tests/test${testID}/patch.txt)
    add_test(Test_${testID}_Applying_Patch PatchMaker tests/test${testID}/i1.txt tests/test${testID}/patch.txt tests/test${testID}/output.txt)
    add_test(Test_${testID}_Compare_Outputs tests/Comparator tests/test${testID}/i2.txt tests/test${testID}/output.txt)
    add_test(Test_${testID}_Generate_Patch_With_Another_First_File PatchMaker tests/test${testID}/i3.txt tests/test${testID}/i2.txt tests/test${testID}/patch2.txt)
    add_test(Test_${testID}_Applying_Patch2 PatchMaker tests/test${testID}/i1.txt tests/test${testID}/patch2.txt tests/test${testID}/output2.txt)
    add_test(Test_${testID}_Compare_Two_Different_Outputs tests/Comparator tests/test${testID}/output.txt tests/test${testID}/output2.txt)
    set_tests_properties(Test_${testID}_Compare_Two_Different_Outputs PROPERTIES WILL_FAIL TRUE)
endmacro(SimpleTest)

SimpleTest("1")
SimpleTest("2")
SimpleTest("3")
SimpleTest("4")
SimpleTest("5")
SimpleTest("6")
SimpleTest("7")