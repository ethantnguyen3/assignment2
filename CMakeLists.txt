cmake_minimum_required(VERSION 3.29)
project(assignment2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(assignment2
    assignment.cpp
    assignment.h
    main.cpp
        stack.h
)
