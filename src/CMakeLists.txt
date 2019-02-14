add_subdirectory(display)

add_executable(RayTracer main.cpp)

target_link_libraries(RayTracer display)