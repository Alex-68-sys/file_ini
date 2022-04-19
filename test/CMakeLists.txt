cmake_minimum_required(VERSION 3.5)

add_subdirectory(./lib/)
set(gtest_SOURCE_DIR, ./lib/)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(TEST_SOURCE_FILES runAllTest.cpp readFileiniTest.cpp)
add_executable(runreadFileiniTests ${TEST_SOURCE_FILES})
target_link_libraries(runreadFileiniTests gtest gtest_main core)