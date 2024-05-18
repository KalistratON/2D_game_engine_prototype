cmake_minimum_required(VERSION 3.8)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

add_subdirectory (engine)
add_subdirectory (game)

set_target_properties(graphics PROPERTIES FOLDER "engine/baselibrary/graphics")
set_target_properties(renunciation PROPERTIES FOLDER "renunciation")