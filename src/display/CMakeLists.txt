
add_library(display PpmDisplayer.cpp PpmDisplayer.h)

target_include_directories(display PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})