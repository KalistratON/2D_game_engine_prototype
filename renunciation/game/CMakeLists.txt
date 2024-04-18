cmake_minimum_required(VERSION 3.8)

add_executable (renunciation "main.cpp")

#set_target_properties( renunciation PROPERTIES RUNTIME_OUTPUT_DIRECTORY 
#   ${CMAKE_CURRENT_SOURCE_DIR}/build_results/bin )

target_link_libraries (renunciation PRIVATE window graphics)