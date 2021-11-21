cmake_minimum_required(VERSION 3.20)
project(OpenGLProject)

set(CMAKE_CXX_STANDARD 17)

#set output directory as project directory - allows file reading from project directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

#create executable
add_executable(${PROJECT_NAME} source/main.cpp external/glad/src/glad.c source/components/ShaderProgram.cpp source/components/ShaderProgram.h source/helpers/FileIO.h source/helpers/FileIO.cpp source/components/Window.cpp source/components/Window.h source/components/objects/textures/Texture.cpp source/components/objects/textures/Texture.h source/components/objects/raw/VAO.cpp source/components/objects/raw/VAO.h source/components/objects/raw/EBO.cpp source/components/objects/raw/EBO.h source/components/objects/raw/VBO.cpp source/components/objects/raw/VBO.h source/components/Camera.cpp source/components/Camera.h source/components/objects/Object.cpp source/components/objects/Object.h source/components/objects/lighting/LightSource.cpp source/components/objects/lighting/LightSource.h source/components/objects/RawObject.cpp source/components/objects/RawObject.h source/RenderEngine.cpp source/RenderEngine.h source/components/ShaderManager.cpp source/components/ShaderManager.h "source/components/model loading/Mesh.cpp" "source/components/model loading/Mesh.h" "source/components/model loading/Model.cpp" "source/components/model loading/Model.h" "source/components/model loading/StructData.h")

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

#include stb
target_include_directories(${PROJECT_NAME} PUBLIC external/stb/include)

#include assimp
set(BUILD_SHARED_LIBS OFF CACHE BOOL "" FORCE)
set(ASSIMP_BUILD_ASSIMP_TOOLS OFF CACHE BOOL "" FORCE)
set(ASSIMP_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(INJECT_DEBUG_POSTFIX OFF CACHE BOOL "" FORCE)

add_subdirectory(external/assimp-5.0.1)
target_link_libraries(${PROJECT_NAME} assimp)