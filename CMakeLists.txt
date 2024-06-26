cmake_minimum_required(VERSION 3.10)
project(csapp)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED on)
set(CMAKE_CXX_EXTENSIONS off)
if(CMAKE_BUILD_TYPE STREQUAL Debug)
    add_definitions(-DDEBUG)
endif()

add_compile_options(-Wall -Wextra -Wpedantic -Wno-unused-parameter -g)

add_subdirectory(chapter_02)
