cmake_minimum_required(VERSION 3.13)
project(RayTracing)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(src)
include_directories(src/display)
include_directories(src/geometry)

add_executable(RayTracing
        src/display/PpmDisplayer.cpp src/display/PpmDisplayer.h
        src/geometry/Vector3D.cpp src/geometry/Vector3D.h
        src/geometry/RGB.cpp src/geometry/RGB.h
        src/main.cpp
        src/geometry/Ray.cpp src/geometry/Ray.h src/geometry/Shapes/Sphere.cpp src/geometry/Shapes/Sphere.h src/geometry/Shapes/Collidable.h src/geometry/Shapes/Collidable.cpp src/display/Model.cpp src/display/Model.h)
