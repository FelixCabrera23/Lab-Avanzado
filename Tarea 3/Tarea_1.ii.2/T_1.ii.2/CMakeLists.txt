# Cmake list para tarea 1.ii.2
# Esto compila la clase persona y su ejemplo

# minima versión de cmake
cmake_minimum_required(VERSION 3.10)

# Nombre del proyecto
project(tarea1.ii.2)

# header y recursos
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

file(GLOB t_2_sources ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

add_executable(tarea1.ii.2 tarea1ii1_class02.cpp ${t_2_sources})
