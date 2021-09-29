cmake_minimum_required(VERSION 3.20)
project(OpenGLProject)

set(CMAKE_CXX_STANDARD 17)

#set output directory as project directory - allows file reading from project directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

#create executable
add_executable(${PROJECT_NAME} source/main.cpp external/glad/src/glad.c source/components/ShaderProgram.cpp source/components/ShaderProgram.h source/helpers/FileIO.h source/helpers/FileIO.cpp source/components/Window.cpp source/components/Window.h)

#include GLFW
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory(external/glfw-3.3.4)
target_link_libraries(${PROJECT_NAME} glfw)

#include OpenGL
find_package(OpenGL REQUIRED)
target_link_libraries(${PROJECT_NAME} OpenGL::GL)

#include Glad
target_include_directories(${PROJECT_NAME} PUBLIC external/glad/include)

#include GLM
target_include_directories(${PROJECT_NAME} PUBLIC external/glm-0.9.9.8)