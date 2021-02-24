#Cmake list para tarea 1.ii.1
# Esto compila la clase simple y su ejecutable da un ejemplo

# minima versión de cmake
cmake_minimum_required(VERSION 3.10)

# Nombre del proyecto
project(tarea1.ii.1)

# headers y recursos
file(GLOB tarea1_sources ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

add_executable(tarea1.ii.1 tarea1ii1_class01.cpp ${tarea1_sources})

# para generar el make faile usar:
# $ cmake T_1.ii.1/
# Desde la carpeta superior
# Para generar el ejecutable usar
# $ make
