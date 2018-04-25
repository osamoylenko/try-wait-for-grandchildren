cmake_minimum_required(VERSION 3.8)
project(try_fork_wait_grandchild)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        main.cpp)

add_executable(try_fork_wait_grandchild ${SOURCE_FILES})