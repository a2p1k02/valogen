cmake_minimum_required(VERSION 3.8)

set(PROJECT_NAME valogen)

set(PROJECT_FILES
        src/main.cpp
        src/engine/valowin.h
        src/engine/valowin.cpp
        src/engine/valoengine.h
        src/engine/valoengine.cpp
        src/engine/valoshader.h
        src/engine/valoshader.cpp
)

project(${PROJECT_NAME})

add_executable(${PROJECT_NAME} ${PROJECT_FILES})

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_INSTALL OFF CACHE BOOL "" FORCE)

target_link_libraries(${PROJECT_NAME} glfw vulkan)