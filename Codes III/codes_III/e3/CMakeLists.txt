cmake_minimum_required (VERSION 3.10)
project (e3)

# Añade un subdirectorio donde habrá otro CMakeLists.txt
# con instrucciones de compilación
add_subdirectory (estudiante)

# Se debe incluir siempre las carpetas donde se encuentran
# los .hpp
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/estudiante/include
                   )

add_executable(e3 inherintance.cpp)

target_link_libraries (e3 LINK_PUBLIC estudiante)
