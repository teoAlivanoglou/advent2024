cmake_minimum_required(VERSION 3.28)
project(advent)

set(CMAKE_CXX_STANDARD 17)

add_executable(advent main.cpp
        main.cpp
        days/day1.h
        days/day2.h
        AdventDays.h
        days/Common.h
)

configure_file (input.txt ${CMAKE_BINARY_DIR}/input.txt COPYONLY)
configure_file (input_2.txt ${CMAKE_BINARY_DIR}/input_2.txt COPYONLY)
