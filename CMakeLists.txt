cmake_minimum_required(VERSION 3.16)
project(p1 C)

set(CMAKE_C_STANDARD 99)

add_executable(p1 main.c parse.c parse.h built_in.c built_in.h execute.c execute.h)