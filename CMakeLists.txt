cmake_minimum_required(VERSION 3.30)

# `import std;` is not supported yet by libstdc++
set(CMAKE_CXX_COMPILER clang++)
set(CMAKE_C_COMPILER clang)

project(sonar_scanner_example LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_MODULE_STD 1)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror -Wpedantic")

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(sonar_scanner_example src/main.cpp)
target_compile_features(sonar_scanner_example
        INTERFACE cxx_std_20)
target_sources(sonar_scanner_example
        PRIVATE
        FILE_SET CXX_MODULES FILES src/args.cppm
)
