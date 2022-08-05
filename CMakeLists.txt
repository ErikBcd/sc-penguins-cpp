# CMakeList.txt : CMake project for SC_2022_cpp, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project (SC_2022_cpp)

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build)
set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -g -fPIC -Bstatic -static-libgcc -static-libstdc++")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_DEBUG} -Wall -Ofast -fPIC -Bstatic -static-libgcc -static-libstdc++")

# Add source to this project's executable.
file(STRINGS "includelist.cmake" includes)

include_directories(${includes})
include(sourcelist.cmake)

add_library(SC_2022_CPP SHARED ${sources})

#if (CMAKE_VERSION VERSION_GREATER 3.12)
#  set_property(TARGET SC_2022_cpp PROPERTY CXX_STANDARD 20)
#endif()

