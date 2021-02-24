# Se especifica la versión de cmake que se necesita para
# utilizar este script
cmake_minimum_required(VERSION 3.10)

# Aquí se especifica el nombre del proyecto
project(e0)

# Se indica que se construya un ejecutable e0
# cuyo código fuente es pointer.cpp.
# Notese que cmake detecta automáticamente que
# debe utilizar c++ para compilar este código
# y detecta el compilador instalado en el sistema.
add_executable(e0 pointer.cpp)
