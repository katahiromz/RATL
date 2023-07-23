# RATL --- ReactOS ATL
##############################################################################

# CMake minimum version
cmake_minimum_required(VERSION 3.0)

# enable testing
enable_testing()

# project name and languages
project(RATL C CXX RC)

##############################################################################
# RATL settings

# RATL_DEFINITIONS
set(RATL_DEFINITIONS -DINITGUID -DWINETEST_USE_DBGSTR_LONGLONG -DHAVE_APITEST -D_USE_PSEH3)
if(MSVC)
    set(RATL_DEFINITIONS ${RATL_DEFINITIONS} -D__REACTOS__)
    if (CMAKE_SYSTEM_PROCESSOR MATCHES "(amd64)|(AMD64)")
        set(RATL_DEFINITIONS ${RATL_DEFINITIONS} -D_AMD64_ -D_M_AMD64)
    elseif (CMAKE_SYSTEM_PROCESSOR MATCHES "(x86)|(X86)")
        set(RATL_DEFINITIONS ${RATL_DEFINITIONS} -D_X86_)
    endif()
endif()

# RATL_INCLUDE_DIRS
set(RATL_INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/atl ${CMAKE_CURRENT_SOURCE_DIR}/common)
if(MSVC)
    set(RATL_INCLUDE_DIRS ${RATL_INCLUDE_DIRS} ${CMAKE_CURRENT_SOURCE_DIR}/common/msvc)
else()
    set(RATL_INCLUDE_DIRS ${RATL_INCLUDE_DIRS} ${CMAKE_CURRENT_SOURCE_DIR}/common/gcc)
endif()

# RATL_LIBRARIES
set(RATL_LIBRARIES uuid rpcrt4 ole32 shlwapi oleaut32 msimg32 gdiplus gdi32 advapi32 user32 msvcrt kernel32)

##############################################################################

add_subdirectory(atltests)
