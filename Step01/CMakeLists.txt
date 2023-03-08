cmake_minimum_required(VERSION 3.10)

project(step1 VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

configure_file(step.h.in step.h)

add_executable(step1 step.cpp)

target_include_directories(step1 PUBLIC "${PROJECT_BINARY_DIR}")
