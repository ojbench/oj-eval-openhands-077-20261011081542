cmake_minimum_required(VERSION 3.10)
project(CrossArray)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Create a simple test to verify compilation
add_executable(code test.cpp)

# Set compiler flags
target_compile_options(code PRIVATE -Wall -Wextra -O2)