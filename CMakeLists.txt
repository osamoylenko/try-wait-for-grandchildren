cmake_minimum_required(VERSION 3.8)
project(try_wait_for_grandchildren)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        main.cpp)

add_executable(try_wait_for_grandchildren ${SOURCE_FILES})
