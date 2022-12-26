cmake_minimum_required(VERSION 3.18)

project(Test_Throw)

add_library(LibraryCode LibraryCode.cpp)

add_executable(testRunner testRunner.cpp)
target_link_libraries(testRunner LibraryCode gtest pthread)
