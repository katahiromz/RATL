
# AtlDialogApp.exe
add_executable(AtlDialogApp WIN32 main.cpp main_res.rc)
target_compile_definitions(AtlDialogApp PRIVATE ${RATL_DEFINITIONS})
target_include_directories(AtlDialogApp PRIVATE ${RATL_INCLUDE_DIRS})
target_link_libraries(AtlDialogApp PRIVATE ${RATL_LIBRARIES} comctl32)
if(MSVC)
    target_link_options(AtlDialogApp PRIVATE /MANIFEST:NO)
endif()
