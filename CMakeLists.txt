cmake_minimum_required(VERSION 3.20)
project(OpenGLProject)

set(CMAKE_CXX_STANDARD 17)

#choose libs from these directories
link_directories(external/assimp-5.1.2/lib external/glfw-3.3.5/lib)

#create executable
add_executable(${PROJECT_NAME} source/main.cpp external/glad/src/glad.c source/components/ShaderProgram.cpp source/components/ShaderProgram.h source/helpers/FileIO.h source/helpers/FileIO.cpp source/components/Window.cpp source/components/Window.h source/components/objects/textures/Texture.cpp source/components/objects/textures/Texture.h source/components/objects/raw/VAO.cpp source/components/objects/raw/VAO.h source/components/objects/raw/EBO.cpp source/components/objects/raw/EBO.h source/components/objects/raw/VBO.cpp source/components/objects/raw/VBO.h source/components/Camera.cpp source/components/Camera.h source/components/objects/Object.cpp source/components/objects/Object.h source/components/objects/lighting/LightSource.cpp source/components/objects/lighting/LightSource.h source/components/objects/RawObject.cpp source/components/objects/RawObject.h source/RenderEngine.cpp source/RenderEngine.h source/components/ShaderManager.cpp source/components/ShaderManager.h source/scenes/Scene1.cpp source/scenes/Scene1.h source/scenes/cube.h)

#copy assets to build
file(COPY "source/assets/" DESTINATION "assets/")

#include GLFW
target_link_libraries(${PROJECT_NAME} glfw3dll)
file(COPY "external/glfw-3.3.5/lib/glfw3.dll" DESTINATION "/")
target_include_directories(${PROJECT_NAME} PUBLIC external/glfw-3.3.5/include)

#include OpenGL
find_package(OpenGL REQUIRED)
target_link_libraries(${PROJECT_NAME} OpenGL::GL)

#include Glad
target_include_directories(${PROJECT_NAME} PUBLIC external/glad/include)

#include GLM
target_include_directories(${PROJECT_NAME} PUBLIC external/glm-0.9.9.8/include)

#include stb
target_include_directories(${PROJECT_NAME} PUBLIC external/stb/include)

#include assimp
target_link_libraries(${PROJECT_NAME} assimp)
file(COPY "external/assimp-5.1.2/lib/libassimp-5.dll" DESTINATION "/")
target_include_directories(${PROJECT_NAME} PUBLIC external/assimp-5.1.2/include)