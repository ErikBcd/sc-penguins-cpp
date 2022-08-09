project (SC_2022_LIB)

include(sourcelist.cmake)

add_library(${PROJECT_NAME} ${sources})

add_library(SC ALIAS ${PROJECT_NAME})

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