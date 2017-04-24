cmake_minimum_required(VERSION 3.7)
project(cpp)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -O")

set(SOURCE_FILES
        all_tests.cpp
        all_tests.hpp
        tennis1.cc
        #         tennis2.cc
        #         tennis3.cc
        test_suite.tests.cpp
        tennis.h ScoreFormatter.cpp ScoreFormatter.h EqualScoreFormatter.cpp EqualScoreFormatter.h WinFormatter.cpp WinFormatter.h AdvantageFormatter.cpp AdvantageFormatter.h Player.cpp Player.h)

add_executable(run.tests ${SOURCE_FILES})
add_custom_target(runAllTests ALL COMMAND run.tests)
