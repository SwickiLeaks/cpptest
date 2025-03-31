cmake_minimum_required(VERSION 3.20)
project(MyProject VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(cpptest src/main.cpp)

# Include directories
target_include_directories(cpptest PRIVATE include)

# Enable warnings
if (CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(cpptest PRIVATE -Wall -Wextra -Wpedantic)
endif()
