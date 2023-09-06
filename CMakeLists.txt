# RATL --- ReactOS ATL
##############################################################################

# CMake minimum version
cmake_minimum_required(VERSION 3.5)

# enable testing
enable_testing()

# project name and languages
project(RATL C CXX RC)

include(CheckIncludeFileCXX)

# check <sal.h> existence
check_include_file_cxx(sal.h HAVE_SAL_H)

# check <excpt.h> existence
check_include_file_cxx(excpt.h HAVE_EXCPT_H)

if (DBG)
    add_definitions(-DDBG=1 -D_DEBUG=1)
endif()

##############################################################################
# Architecture

if (MSVC)
    if (CMAKE_SYSTEM_PROCESSOR MATCHES "(x86)|(X86)")
        add_definitions(-D_X86_)
    elseif (CMAKE_SYSTEM_PROCESSOR MATCHES "(amd64)|(AMD64)")
        add_definitions(-D_AMD64_)
    else()
        message(FATAL_ERROR "Unsupportet platform")
    endif()
endif()

##############################################################################

add_library(crtcompat STATIC compat/crtcompat.c)

##############################################################################
# RATL settings

# RATL_DEFINITIONS
set(RATL_DEFINITIONS -DINITGUID -DWINETEST_USE_DBGSTR_LONGLONG -DHAVE_APITEST -D_USE_PSEH3 )
set(RATL_DEFINITIONS ${RATL_DEFINITIONS} -D__RATL__ -D_CRT_NON_CONFORMING_SWPRINTFS)
if(MSVC)
    set(RATL_DEFINITIONS ${RATL_DEFINITIONS} -D__MINGW_ATTRIB_UNUSED= -D_CRT_SECURE_NO_WARNINGS -D_NEW=)
else()
    set(RATL_DEFINITIONS ${RATL_DEFINITIONS})
endif()

# RATL_INCLUDE_DIRS
set(RATL_INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/include ${CMAKE_CURRENT_SOURCE_DIR}/include/atl ${CMAKE_CURRENT_SOURCE_DIR}/compat)
if(NOT(HAVE_SAL_H))
    set(RATL_INCLUDE_DIRS ${RATL_INCLUDE_DIRS} ${CMAKE_CURRENT_SOURCE_DIR}/compat/sal)
endif()
if(NOT(HAVE_EXCPT_H))
    set(RATL_INCLUDE_DIRS ${RATL_INCLUDE_DIRS} ${CMAKE_CURRENT_SOURCE_DIR}/compat/excpt)
endif()

# RATL_LIBRARIES
set(RATL_LIBRARIES crtcompat uuid rpcrt4 ole32 shlwapi oleaut32 msimg32 gdiplus gdi32 advapi32 user32 msvcrt kernel32)

##############################################################################

add_subdirectory(atltests)
