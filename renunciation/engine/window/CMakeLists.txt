cmake_minimum_required(VERSION 3.8)
project(window)

file(GLOB window "${CMAKE_CURRENT_SOURCE_DIR}/*/*")

add_library(window SHARED ${window})

#set_target_properties( window PROPERTIES LIBRARY_OUTPUT_DIRECTORY
#   ${CMAKE_CURRENT_SOURCE_DIR}/build_results/bin )

target_link_libraries (window PUBLIC glfw libglew_static glm)