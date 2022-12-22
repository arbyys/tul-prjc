cmake_minimum_required(VERSION 3.23)
project(RuleOfFiveAndThree)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(RuleOfFiveAndThree
        MainDriver.cpp
        RuleOfThreeAndFive.cpp
        RuleOfThreeAndFive.h)
