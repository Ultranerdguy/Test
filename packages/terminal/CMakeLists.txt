cmake_minimum_required(VERSION 3.14)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(Terminal_include "${CMAKE_CURRENT_LIST_DIR}/include/")
message(STATUS "Terminal include directory: " ${Terminal_include})
add_library(Terminal_libs STATIC
  src/identifier.c
  src/io.c
  src/screen.c
)
target_include_directories(Terminal_libs PUBLIC ${Terminal_include})