cmake_minimum_required(VERSION 3.26)
project(mega_horosh_decimal C)

set(CMAKE_C_STANDARD 11)

file(GLOB SOURCE_FILES "src/s21_matrix_lib/*.c")

add_executable(mega_horosh_matrix ${SOURCE_FILES})
