cmake_minimum_required(VERSION 3.19)

project(file_ini)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_subdirectory(test)

set(SOURCE_FILES ReadFileIni.cpp ReadFileIni.h version.h)
add_executable(file_ini main.cpp)
add_library(core ${SOURCE_FILES})
target_link_libraries(file_ini core)