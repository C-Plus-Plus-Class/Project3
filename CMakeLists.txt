cmake_minimum_required(VERSION 3.15)
project(410Project3)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

add_executable(410Project3 main.cpp print_ts.h tester.h print_ts.cpp tester.cpp)