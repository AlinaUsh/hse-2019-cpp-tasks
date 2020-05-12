cmake_minimum_required(VERSION 3.10)
project(lab_15)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(lab_15 include/linq.h src/smoke_test.cpp)