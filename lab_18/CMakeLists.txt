cmake_minimum_required(VERSION 3.10)
project(lab_18)

set(CMAKE_CXX_STANDARD 17)

SET(CMAKE_CXX_FLAGS -Werror=reorder)

include_directories(include)

add_executable(lab_18 src/doctest_main.cpp include/format.hpp src/smoke_test.cpp)