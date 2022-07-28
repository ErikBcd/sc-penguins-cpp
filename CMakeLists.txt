# CMakeList.txt : CMake project for SC_2022_cpp, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("SC_2022_cpp")

# Add source to this project's executable.
add_executable (SC_2022_cpp "starter.cpp" "starter.h" "include/game/gameState.h" "include/communication/message_handler.h" "include/helpers/game_helpers.h" "include/game/board.h" "include/logic/logic.h" "include/game/field.h" "include/game/move.h")
file(STRINGS "includelist.cmake" includes)

include_directories(${includes})
include(sourcelist.cmake)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET SC_2022_cpp PROPERTY CXX_STANDARD 20)
endif()

