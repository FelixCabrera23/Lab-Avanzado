# Cmake lists para tarea 1.ii.3
# Esto compila las clases vec3

# minima versión de cmake
cmake_minimum_required(VERSION 3.10)

# incluimos los headers
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include_vec)

file(GLOB vec_sources ${CMAKE_CURRENT_SOURCE_DIR}/src_vec/*.cpp)

add_library(vector SHARED ${vec_sources})
