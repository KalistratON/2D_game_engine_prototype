cmake_minimum_required(VERSION 3.8)
project(graphics)

file(GLOB graphics "${CMAKE_CURRENT_SOURCE_DIR}/*/*")

add_library(graphics SHARED ${graphics})

#set_target_properties( graphics PROPERTIES LIBRARY_OUTPUT_DIRECTORY
#   ${CMAKE_CURRENT_SOURCE_DIR}/build_results/bin )

target_link_libraries (graphics PUBLIC glfw libglew_static glm)