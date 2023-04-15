cmake_minimum_required(VERSION 3.14)

# Utility library
set(Util_include "${CMAKE_CURRENT_LIST_DIR}/util/include/")
message(STATUS "Util include directory: " ${Util_include})
add_library(Util_libs STATIC
  util/src/filewatcher.cpp
)
target_include_directories(Util_libs PUBLIC ${Util_include})

# Terminal library
add_subdirectory(terminal)