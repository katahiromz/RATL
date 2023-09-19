add_executable(AtlWindowApp WIN32 main.cpp)
target_compile_definitions(AtlWindowApp PRIVATE ${RATL_DEFINITIONS})
target_include_directories(AtlWindowApp PRIVATE ${RATL_INCLUDE_DIRS})
target_link_libraries(AtlWindowApp PRIVATE ${RATL_LIBRARIES} comctl32)
