cmake_minimum_required(VERSION 3.14)
project(TestProj)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(CTest)

include_directories(include)
include_directories(${CMAKE_CURRENT_BINARY_DIR})
add_executable(TestProj app/main.cpp)
add_subdirectory(src)
target_link_libraries(TestProj TestSrc)