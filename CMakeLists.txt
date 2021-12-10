cmake_minimum_required(VERSION 3.20)
project(OpenGLProject)

set(CMAKE_CXX_STANDARD 17)

#set directory to store libraries
link_directories(external/lib)

#create executable
add_executable(${PROJECT_NAME} source/main.cpp source/components/ShaderProgram.cpp source/components/ShaderProgram.h source/helpers/FileIO.h source/helpers/FileIO.cpp source/components/Window.cpp source/components/Window.h source/components/objects/textures/Texture.cpp source/components/objects/textures/Texture.h source/components/objects/raw/VAO.cpp source/components/objects/raw/VAO.h source/components/objects/raw/EBO.cpp source/components/objects/raw/EBO.h source/components/objects/raw/VBO.cpp source/components/objects/raw/VBO.h source/components/Camera.cpp source/components/Camera.h source/components/objects/Object.cpp source/components/objects/Object.h source/components/objects/RawObject.cpp source/components/objects/RawObject.h source/RenderEngine.cpp source/RenderEngine.h source/components/ShaderManager.cpp source/components/ShaderManager.h source/scenes/LightingScene.cpp source/scenes/LightingScene.h source/components/lighting/sources/LightSource.cpp source/components/lighting/sources/LightSource.h)

#copy assets to build
file(COPY "source/assets/" DESTINATION "assets/")

#add include directories
target_include_directories(${PROJECT_NAME} PUBLIC external/include)

#include GLFW, VERSION: 3.3.5
target_link_libraries(${PROJECT_NAME} glfw3dll)
file(COPY "external/lib/glfw3.dll" DESTINATION "/")

#include assimp, VERSION: 5.1.3
target_link_libraries(${PROJECT_NAME} assimp)
file(COPY "external/lib/libassimp-5.dll" DESTINATION "/")

#include GLAD, VERSION: 0.1.34
target_link_libraries(${PROJECT_NAME} glad)