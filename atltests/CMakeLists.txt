
add_executable(atl_apitest
    atlconv.cpp
    atltypes.cpp
    CAtlFileMapping.cpp
    AtlObjMap.cpp
    CAtlList.cpp
    CComBSTR.cpp
    CComHeapPtr.cpp
    CComObject.cpp
    CComQIPtr.cpp
    CComVariant.cpp
    CHeapPtrList.cpp
    CImage.cpp
    CPath.cpp
    CRegKey.cpp
    CSimpleArray.cpp
    CSimpleMap.cpp
    CString.cpp
    SubclassWindow.cpp
    testlist.c
    atl_apitest.rc)

if(MSVC)
    set(RATLTEST_DEFINITIONS -DHAVE_APITEST -DWINETEST_USE_DBGSTR_LONGLONG)
    set(RATLTEST_INCLUDES ${CMAKE_CURRENT_SOURCE_DIR}/../compat)
endif()

target_compile_definitions(atl_apitest PRIVATE ${RATL_DEFINITIONS} ${RATLTEST_DEFINITIONS})
target_include_directories(atl_apitest PRIVATE ${RATL_INCLUDE_DIRS} ${RATLTEST_INCLUDES})
target_link_libraries(atl_apitest PRIVATE ${RATL_LIBRARIES})

add_test(NAME atlconv COMMAND $<TARGET_FILE:atl_apitest> atlconv WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/atltests)
add_test(NAME atltypes COMMAND $<TARGET_FILE:atl_apitest> atltypes WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/atltests)
add_test(NAME CAtlFileMapping COMMAND $<TARGET_FILE:atl_apitest> CAtlFileMapping WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/atltests)
add_test(NAME AtlObjMap COMMAND $<TARGET_FILE:atl_apitest> AtlObjMap WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/atltests)
add_test(NAME CAtlList COMMAND $<TARGET_FILE:atl_apitest> CAtlList WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/atltests)
add_test(NAME CComBSTR COMMAND $<TARGET_FILE:atl_apitest> CComBSTR WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/atltests)
add_test(NAME CComHeapPtr COMMAND $<TARGET_FILE:atl_apitest> CComHeapPtr WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/atltests)
add_test(NAME CComObject COMMAND $<TARGET_FILE:atl_apitest> CComObject WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/atltests)
add_test(NAME CComQIPtr COMMAND $<TARGET_FILE:atl_apitest> CComQIPtr WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/atltests)
add_test(NAME CComVariant COMMAND $<TARGET_FILE:atl_apitest> CComVariant WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/atltests)
add_test(NAME CHeapPtrList COMMAND $<TARGET_FILE:atl_apitest> CHeapPtrList WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/atltests)
add_test(NAME CImage COMMAND $<TARGET_FILE:atl_apitest> CImage WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/atltests)
add_test(NAME CPath COMMAND $<TARGET_FILE:atl_apitest> CPath WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/atltests)
add_test(NAME CRegKey COMMAND $<TARGET_FILE:atl_apitest> CRegKey WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/atltests)
add_test(NAME CSimpleArray COMMAND $<TARGET_FILE:atl_apitest> CSimpleArray WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/atltests)
add_test(NAME CSimpleMap COMMAND $<TARGET_FILE:atl_apitest> CSimpleMap WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/atltests)
add_test(NAME CString COMMAND $<TARGET_FILE:atl_apitest> CString WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/atltests)
add_test(NAME SubclassWindow COMMAND $<TARGET_FILE:atl_apitest> SubclassWindow WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/atltests)
