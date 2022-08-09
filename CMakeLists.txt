cmake_minimum_required (VERSION 3.8)

project(SC_2022_CPP)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)

add_subdirectory(sc_library)
add_subdirectory(starter)