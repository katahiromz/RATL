# RATL --- ReactOS ATL
##############################################################################

# CMake minimum version
cmake_minimum_required(VERSION 3.0)

# enable testing
enable_testing()

# project name and languages
project(RATL C CXX)

##############################################################################

set(RATL_DEFINITIONS -DINITGUID -DWINETEST_USE_DBGSTR_LONGLONG -DHAVE_APITEST -D_USE_PSEH3)
set(RATL_INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/atl ${CMAKE_CURRENT_SOURCE_DIR}/common)
set(RATL_LIBRARIES uuid rpcrt4 ole32 shlwapi oleaut32 msimg32 gdiplus gdi32 advapi32 user32 msvcrt kernel32)

##############################################################################

add_subdirectory(atltests)
