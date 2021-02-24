include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include
                    )

file(GLOB estudiante_sources ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

add_library (estudiante SHARED ${estudiante_sources})

