project (SC_2022_LIB)

include(sourcelist.cmake)

add_library(${PROJECT_NAME} SHARED ${sources})

add_library(SC ALIAS ${PROJECT_NAME})

if(MSVC)
  target_compile_options(SC_2022_LIB PRIVATE /W4)
else()
  target_compile_options(SC_2022_LIB PRIVATE -Wall -Wextra -Wpedantic)
endif()

target_include_directories( ${PROJECT_NAME}
    PUBLIC 
    "${PROJECT_SOURCE_DIR}/externals/pugixml"
    "${PROJECT_SOURCE_DIR}/include/client"
    "${PROJECT_SOURCE_DIR}/include/communication"
    "${PROJECT_SOURCE_DIR}/include/game"
    "${PROJECT_SOURCE_DIR}/include/game/util"
    "${PROJECT_SOURCE_DIR}/include/helpers"
    "${PROJECT_SOURCE_DIR}/include/logic"
)

find_package(Boost COMPONENTS system thread)
target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES})