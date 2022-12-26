cmake_minimum_required(VERSION 3.18)

project(Count_Positive)

add_library(LibraryCode STATIC LibraryCode.cpp)

add_executable(testRunner testRunner.cpp)
target_link_libraries(testRunner LibraryCode gtest pthread)