cmake_minimum_required(VERSION 3.23)
project(leetcode)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(${PROJECT_NAME}
        ./include/util.h
        ./src/509_fibonacci_number.cpp)

target_include_directories(${PROJECT_NAME} PRIVATE ./include)
