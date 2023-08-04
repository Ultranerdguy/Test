cmake_minimum_required(VERSION 3.14)

add_library(TEST_SRC App.cpp
  CommandManager.cpp
  Commands/Report.cpp
  Commands/Exit.cpp
  Commands/Clear.cpp
  Commands/Notify.cpp)