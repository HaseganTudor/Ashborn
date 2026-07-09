cmake_minimum_required(VERSION 3.20)

project(Ashborn LANGUAGES C CXX)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(external/glfw)

add_library(glad
    external/glad/src/glad.c
)

target_include_directories(glad PUBLIC
    external/glad/include
)

find_package(OpenGL REQUIRED)

add_executable(Ashborn
    src/main.cpp
)

target_include_directories(Ashborn PRIVATE
    external/glad/include
    external/glm
    external/stb
)

target_link_libraries(Ashborn
    glfw
    glad
    OpenGL::GL
)

if(WIN32)
    target_link_libraries(Ashborn opengl32)
endif()
