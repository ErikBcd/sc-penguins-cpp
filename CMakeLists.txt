cmake_minimum_required (VERSION 3.18)

project(SC_PENGUINS_CPP)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_SHARED_MODULE_PREFIX "")

add_subdirectory(sc_library)


add_subdirectory(starter)
