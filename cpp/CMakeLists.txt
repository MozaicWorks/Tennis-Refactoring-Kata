cmake_minimum_required(VERSION 3.7)
project(cpp)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        all_tests.cpp
        all_tests.hpp
        generate_tests.py
        makefile
        tennis1.cc
        tennis2.cc
        tennis3.cc
        test_suite.tests.cpp)

add_executable(cpp ${SOURCE_FILES})