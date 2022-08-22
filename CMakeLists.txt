cmake_minimum_required (VERSION 3.18)

project(SC_2022_CPP)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)

option(BUILD_PYTHON "BUILD_PYTHON" OFF)

add_subdirectory(sc_library)

if (BUILD_PYTHON)
    add_subdirectory(python_starter)
else()
    add_subdirectory(starter)
endif()