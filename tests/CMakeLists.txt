cmake_minimum_required(VERSION 2.6)
project(type_extractor_test CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(usage ../usage.cpp)
enable_testing()
add_test(usage usage)
