cmake_minimum_required(VERSION 3.8)
project(graphics)

file(GLOB graphics "${CMAKE_CURRENT_SOURCE_DIR}/*/*")

add_library(graphics SHARED ${graphics})

target_link_libraries (graphics PRIVATE glfw libglew_static glm)