cmake_minimum_required(VERSION 3.10)
project(02)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

add_executable(integer_compute integer_compute.c)
add_executable(show_bytes show_bytes.c)
add_executable(inplace_swape inplace_swape.c)
add_executable(integer_limit integer_limit.c)
add_executable(sum_elements sum_elements.c)
