cmake_minimum_required(VERSION 3.13)
project(RayTracing)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(src)
include_directories(src/display)
include_directories(src/geometry)

add_executable(RayTracing
        src/display/PpmDisplayer.cpp src/display/PpmDisplayer.h
        src/geometry/primitives/Vector3D.cpp src/geometry/primitives/Vector3D.h
        src/geometry/primitives/RGB.cpp src/geometry/primitives/RGB.h
        src/main.cpp
        src/geometry/primitives/Ray.cpp src/geometry/primitives/Ray.h
        src/geometry/Shapes/Sphere.cpp src/geometry/Shapes/Sphere.h
        src/geometry/Shapes/Collidable.cpp src/geometry/Shapes/Collidable.h
        src/display/Model.cpp src/display/Model.h
        src/display/Camera.cpp src/display/Camera.h src/geometry/materials/Metals.cpp src/geometry/materials/Metals.h src/geometry/materials/Material.cpp src/geometry/materials/Material.h src/geometry/materials/Lambertian.cpp src/geometry/materials/Lambertian.h src/geometry/materials/Dielectric.cpp src/geometry/materials/Dielectric.h src/CONFIG.h src/geometry/primitives/HitRecord.cpp src/geometry/primitives/HitRecord.h)
