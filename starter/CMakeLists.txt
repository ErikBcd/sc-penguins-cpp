project(SC_2022_STARTER)

add_executable(${PROJECT_NAME} custom_logic.cpp starter.cpp )

target_link_libraries(${PROJECT_NAME}
    SC
)