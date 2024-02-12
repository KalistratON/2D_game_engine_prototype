cmake_minimum_required(VERSION 3.8)
project(window)

file(GLOB window "${CMAKE_CURRENT_SOURCE_DIR}/*/*")

add_library(window SHARED ${window})

target_link_libraries (window PRIVATE glfw libglew_static glm)