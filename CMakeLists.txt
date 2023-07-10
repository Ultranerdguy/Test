cmake_minimum_required(VERSION 3.14)
project(TestProj)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(CTest)

# Project files (include and source)
include_directories(include)
include_directories(${CMAKE_CURRENT_BINARY_DIR})
add_executable(TestProj app/main.cpp)

# Add source code and link
add_subdirectory(src)
target_link_libraries(TestProj TEST_SRC)

# All "packages" consumed
add_subdirectory(packages)

# Link packages into main project
target_link_libraries(TestProj Util_libs Terminal_libs)
target_include_directories(TestProj PRIVATE Util_include Terminal_include)