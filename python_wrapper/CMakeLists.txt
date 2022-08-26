project(SC_PY_WRAPPER)

add_library(SC_PY_WRAPPER MODULE wrapper.cpp)

target_link_libraries(${PROJECT_NAME}
SC
)
find_package(PythonLibs REQUIRED)

include_directories(${PYTHON_INCLUDE_DIRS})

find_package(Boost COMPONENTS python)

target_link_libraries(SC_PY_WRAPPER ${Boost_LIBRARIES})
target_link_libraries(SC_PY_WRAPPER ${PythonLibs})

add_custom_command(
    TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/python_starter
    ${EXECUTABLE_OUTPUT_PATH}/python_wrapper
)

add_custom_command(
    TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
    ${CMAKE_BINARY_DIR}/python_wrapper/SC_PY_WRAPPER.so
    ${EXECUTABLE_OUTPUT_PATH}/python_wrapper/SC_PY_WRAPPER.so
)