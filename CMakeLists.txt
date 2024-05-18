cmake_minimum_required (VERSION 3.8)

project ("renunciation")

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/build/project_bin_files")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/build/project_bin_files")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/build/project_bin_files")

add_subdirectory (glfw)
add_subdirectory (glew)
add_subdirectory (glm-all)
add_subdirectory ("renunciation")

target_include_directories (graphics PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/glfw/include)
target_include_directories (graphics PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/glew/include)
target_include_directories (graphics PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/glm-all)

target_include_directories (renunciation PRIVATE ${renunciation_SOURCE_DIR}/renunciation/engine/basic/graphics/inc)

file(COPY resources/ DESTINATION ${PROJECT_BINARY_DIR}/resources/)
