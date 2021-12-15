cmake_minimum_required(VERSION 3.20)

# Engine Build Options
set(ENGINE_BUILD_TESTS ON)

# Set Include and Linking Directories
link_directories(${CMAKE_BINARY_DIR}/bin)

include_directories(
    external/include
)

file(COPY "external/lib/" DESTINATION "bin/")

# Project Settings
project(Project)

set(CMAKE_CXX_STANDARD 17)

set(ENGINE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${ENGINE_OUTPUT_DIRECTORY})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${ENGINE_OUTPUT_DIRECTORY})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${ENGINE_OUTPUT_DIRECTORY})

# Source
link_libraries(
    glfw3dll # Version: 3.3.5
    assimp # Version: 5.1.3
    glad # Version: 0.1.34
)

add_subdirectory(source)

# Tests
if (ENGINE_BUILD_TESTS)
    include_directories(PUBLIC .)

    link_libraries(OpenGLProject)

    file(COPY "tests/assets/" DESTINATION "bin/assets/")

    add_subdirectory(tests)
endif()