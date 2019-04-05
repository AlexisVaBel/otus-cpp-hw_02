cmake_minimum_required(VERSION 3.5)

project(02.cpp14)

include_directories(".")
add_executable(ip_filter ip_filter.cpp)

set_target_properties(ip_filter PROPERTIES
        CXX_STANDARD 14
        CXX_STANDARD_REQUIRED ON
        COMPILE_OPTIONS "-Wpedantic;-Wall;-Wextra"
        )
