cmake_minimum_required(VERSION 3.10)
project(rootExample01)

# Ahora se va requerir que cmake encuentre las
# librerias de ROOT
find_package(ROOT REQUIRED)

# Ademas de solo encontrar las librerías,
# se definen algunas variables de entorno
# que indican su ubicación. En este caso
# se utiliza ROOT_INCLUDE_DIRS que indica
# donde estan los headers (.h)
include_directories(${ROOT_INCLUDE_DIRS})

add_executable(example01 example01.cpp)

# Para finalizar el ejecutable, hay que e
# enlazarlo con las librerías de ROOT.
target_link_libraries(example01 ${ROOT_LIBRARIES} )

