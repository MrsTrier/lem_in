cmake_minimum_required(VERSION 3.15)
project(Visualisation_lem_in C)

set(CMAKE_C_STANDARD 99)

include_directories(~/Library/Frameworks/SDL2.framework/Headers)
include_directories(~/Library/Frameworks/SDL2_image.framework/Headers)


add_executable(Visualisation_lem_in main.c)

target_link_libraries(Visualisation_lem_in "-framework SDL2")
target_link_libraries(Visualisation_lem_in "-framework SDL2_image")

set_target_properties(Visualisation_lem_in PROPERTIES LINK_FLAGS "-F /Users/$ENV{USER}/Library/Frameworks")
