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
# Architecture

if (MSVC)
    if(CMAKE_SIZEOF_VOID_P EQUAL 8)
        add_definitions(-D_AMD64_ -D_M_AMD64)
    else()
        add_definitions(-D_X86_ -D_M_IX86)
    endif()
endif()

##############################################################################
# RATL options

option(RATL_BUILD_SAMPLES "Build RATL samples" ON)

##############################################################################
# RATL settings

if(MSVC)
    # RATL_DEFINITIONS
    set(RATL_DEFINITIONS "")

    # RATL_INCLUDE_DIRS
    set(RATL_INCLUDE_DIRS "")

    # RATL_LIBRARIES
    set(RATL_LIBRARIES crtcompat uuid rpcrt4 ole32 shlwapi oleaut32 msimg32 gdiplus gdi32 advapi32 user32 msvcrtd vcruntimed ucrtd kernel32)
else()
    # RATL_DEFINITIONS
    set(RATL_DEFINITIONS -D__RATL__ -DINITGUID -D_USE_PSEH3 -D_CRT_NON_CONFORMING_SWPRINTFS)

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
    set(RATL_LIBRARIES crtcompat uuid rpcrt4 ole32 shlwapi oleaut32 msimg32 gdiplus gdi32 advapi32 user32 msvcrt kernel32)
endif()

message(STATUS "RATL_BUILD_SAMPLES: ${RATL_BUILD_SAMPLES}")
message(STATUS "RATL_DEFINITIONS: ${RATL_DEFINITIONS}")
message(STATUS "RATL_INCLUDE_DIRS: ${RATL_INCLUDE_DIRS}")
message(STATUS "RATL_LIBRARIES: ${RATL_LIBRARIES}")

##############################################################################

add_library(crtcompat STATIC compat/crtcompat.cpp)

if(NOT(MSVC))
    # FIXME: ok macro is duplicated
    add_subdirectory(atltests)
endif()

if(RATL_BUILD_SAMPLES)
    add_subdirectory(samples)
endif()
