cmake_minimum_required(VERSION 3.10)
project(rootExample02)

find_package(Boost COMPONENTS program_options REQUIRED)

find_package(ROOT REQUIRED)


include_directories(  ${Boost_INCLUDE_DIR}
                      ${ROOT_INCLUDE_DIRS}
                    )

add_executable(example02 example02.cpp)
target_link_libraries(example02 LINK_PUBLIC ${Boost_PROGRAM_OPTIONS_LIBRARIES} ${ROOT_LIBRARIES} )




