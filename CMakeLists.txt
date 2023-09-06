# RATL --- ReactOS ATL
##############################################################################

# CMake minimum version
cmake_minimum_required(VERSION 3.5)

# enable testing
enable_testing()

# project name and languages
project(RATL C CXX RC)

##############################################################################
# Checking

include(CheckIncludeFileCXX)

# check <sal.h> existence
check_include_file_cxx(sal.h HAVE_SAL_H)

# check <excpt.h> existence
check_include_file_cxx(excpt.h HAVE_EXCPT_H)

##############################################################################
# Debugging

if (DBG)
    add_definitions(-DDBG=1 -D_DEBUG=1)
endif()

if (DBG)
    message(FATAL_ERROR "Sorry, RATL doesn't support debugging yet.")
endif()

##############################################################################
# Architecture

if (MSVC)
    if(CMAKE_SIZEOF_VOID_P EQUAL 8)
        add_definitions(-D_AMD64_ -D_M_AMD64)
    else()
        add_definitions(-D_X86_ -D_M_IX86)
    endif()
endif()

##############################################################################

add_library(crtcompat STATIC compat/crtcompat.cpp)

##############################################################################
# RATL settings

# RATL_DEFINITIONS
set(RATL_DEFINITIONS -DINITGUID -DWINETEST_USE_DBGSTR_LONGLONG -DHAVE_APITEST -D_USE_PSEH3)
set(RATL_DEFINITIONS ${RATL_DEFINITIONS} -D__RATL__ -D_CRT_NON_CONFORMING_SWPRINTFS)
if(MSVC)
    set(RATL_DEFINITIONS ${RATL_DEFINITIONS} -D__MINGW_ATTRIB_UNUSED= -D_CRT_SECURE_NO_WARNINGS)
    set(RATL_DEFINITIONS ${RATL_DEFINITIONS} -D_NEW)
endif()

# RATL_INCLUDE_DIRS
set(RATL_INCLUDE_DIRS
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/include/atl
    ${CMAKE_CURRENT_SOURCE_DIR}/compat)
if(NOT(HAVE_SAL_H))
    set(RATL_INCLUDE_DIRS ${RATL_INCLUDE_DIRS} ${CMAKE_CURRENT_SOURCE_DIR}/compat/sal)
endif()
if(NOT(HAVE_EXCPT_H))
    set(RATL_INCLUDE_DIRS ${RATL_INCLUDE_DIRS} ${CMAKE_CURRENT_SOURCE_DIR}/compat/excpt)
endif()

# RATL_LIBRARIES
if (MSVC AND DBG)
    set(RATL_LIBRARIES crtcompat uuid rpcrt4 ole32 shlwapi oleaut32 msimg32 gdiplus gdi32 advapi32 user32 msvcrtd kernel32)
else()
    set(RATL_LIBRARIES crtcompat uuid rpcrt4 ole32 shlwapi oleaut32 msimg32 gdiplus gdi32 advapi32 user32 msvcrt kernel32)
endif()

##############################################################################

add_subdirectory(atltests)
