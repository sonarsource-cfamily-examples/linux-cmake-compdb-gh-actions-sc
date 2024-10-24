cmake_minimum_required(VERSION 3.30)

project(sonar_scanner_example LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(sonar_scanner_example src/main.cpp)
target_sources(sonar_scanner_example
        PRIVATE
        FILE_SET CXX_MODULES FILES src/args.cppm
)
