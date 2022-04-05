cmake_minimum_required(VERSION 3.19)
project(file_ini)

set(CMAKE_CXX_STANDARD 14)

add_executable(file_ini main.cpp ReadFileIni.cpp ReadFileIni.h version.h)