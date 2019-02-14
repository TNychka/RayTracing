cmake_minimum_required(VERSION 3.13)

project(RayTracing)

set(CMAKE_CXX_STANDARD 17)
ADD_DEFINITIONS(-std=c++1y -Wall -Wfloat-conversion)

add_subdirectory(src)
