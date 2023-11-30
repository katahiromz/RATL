
# CMake minimum version
cmake_minimum_required(VERSION 3.5)

# Set policy
cmake_policy(SET CMP0079 NEW)

# project name and languages
project(AtlWindowApp C CXX RC)

# Read RATL if any
add_subdirectory(RATL)
get_directory_property(RATL_DEFINITIONS DIRECTORY RATL DEFINITION RATL_DEFINITIONS)
get_directory_property(RATL_INCLUDE_DIRS DIRECTORY RATL DEFINITION RATL_INCLUDE_DIRS)
get_directory_property(RATL_LIBRARIES DIRECTORY RATL DEFINITION RATL_LIBRARIES)

# AtlWindowApp.exe
add_executable(AtlWindowApp WIN32 main.cpp main_res.rc)
target_compile_definitions(AtlWindowApp PRIVATE ${RATL_DEFINITIONS})
target_include_directories(AtlWindowApp PRIVATE ${RATL_INCLUDE_DIRS})
target_link_libraries(AtlWindowApp PRIVATE ${RATL_LIBRARIES} comctl32)
if(MSVC)
    target_link_options(AtlWindowApp PRIVATE /MANIFEST:NO)
endif()
