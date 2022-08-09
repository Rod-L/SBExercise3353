cmake_minimum_required(VERSION 3.22)
project(SBExercise3353)

set(CMAKE_CXX_STANDARD 14)

add_executable(SBExercise3353 include/IntFloatStringDB.h src/main.cpp)

target_include_directories(SBExercise3353 PUBLIC include)
