
add_definitions(-DINITGUID -DWINETEST_USE_DBGSTR_LONGLONG)

include_directories(../atl ../common)

add_executable(atl_apitest
    atltypes.cpp
    CAtlFileMapping.cpp
    CComBSTR.cpp
    CComHeapPtr.cpp
    CComObject.cpp
    CComQIPtr.cpp
    CImage.cpp
    CRegKey.cpp
    CSimpleArray.cpp
    CSimpleMap.cpp
    CString.cpp
    CComVariant.cpp
    testlist.c
    atl_apitest.rc)

target_link_libraries(atl_apitest uuid rpcrt4 ole32 oleaut32 msimg32 gdiplus gdi32 advapi32 user32 msvcrt kernel32)

add_test(NAME atltypes COMMAND $<TARGET_FILE:atl_apitest> atltypes WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/atltests)
add_test(NAME CAtlFileMapping COMMAND $<TARGET_FILE:atl_apitest> CAtlFileMapping WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/atltests)
add_test(NAME CComBSTR COMMAND $<TARGET_FILE:atl_apitest> CComBSTR WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/atltests)
add_test(NAME CComHeapPtr COMMAND $<TARGET_FILE:atl_apitest> CComHeapPtr WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/atltests)
add_test(NAME CComObject COMMAND $<TARGET_FILE:atl_apitest> CComObject WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/atltests)
add_test(NAME CComQIPtr COMMAND $<TARGET_FILE:atl_apitest> CComQIPtr WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/atltests)
add_test(NAME CImage COMMAND $<TARGET_FILE:atl_apitest> CImage WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/atltests)
add_test(NAME CRegKey COMMAND $<TARGET_FILE:atl_apitest> CRegKey WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/atltests)
add_test(NAME CSimpleArray COMMAND $<TARGET_FILE:atl_apitest> CSimpleArray WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/atltests)
add_test(NAME CSimpleMap COMMAND $<TARGET_FILE:atl_apitest> CSimpleMap WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/atltests)
add_test(NAME CString COMMAND $<TARGET_FILE:atl_apitest> CString WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/atltests)
add_test(NAME CComVariant COMMAND $<TARGET_FILE:atl_apitest> CComVariant WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/atltests)
