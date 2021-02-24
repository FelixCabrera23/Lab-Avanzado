# Cmake lists para tarea 1.ii.3
# Esto compila las clases vec2 y vec3 y su ejecutable

# minima versión de cmake
cmake_minimum_required(VERSION 3.10)

project(T_1.ii.3)

add_subdirectory(vector)

file(GLOB sources ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/vector/include_vec)

add_executable(tarea1.ii.3 tarea1ii2_class03_R3.cpp ${sources})

target_link_libraries(tarea1.ii.3 LINK_PUBLIC  vector)
