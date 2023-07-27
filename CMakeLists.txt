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

##############################################################################
# RATL settings

# RATL_DEFINITIONS
set(RATL_DEFINITIONS -DINITGUID -DWINETEST_USE_DBGSTR_LONGLONG -DHAVE_APITEST -D_USE_PSEH3 )
set(RATL_DEFINITIONS ${RATL_DEFINITIONS} -D__RATL__ -D_CRT_NON_CONFORMING_SWPRINTFS)
if(MSVC)
    set(RATL_DEFINITIONS ${RATL_DEFINITIONS} -D__MINGW_ATTRIB_UNUSED= -D_CRT_SECURE_NO_WARNINGS -D_NEW=)
else()
    set(RATL_DEFINITIONS ${RATL_DEFINITIONS} -D_Post_z_=)
endif()

# RATL_INCLUDE_DIRS
set(RATL_INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/include ${CMAKE_CURRENT_SOURCE_DIR}/include/atl)
if(NOT(HAVE_SAL_H))
    set(RATL_INCLUDE_DIRS ${RATL_INCLUDE_DIRS} ${CMAKE_CURRENT_SOURCE_DIR}/include/sal)
endif()
if(NOT(HAVE_EXCPT_H))
    set(RATL_INCLUDE_DIRS ${RATL_INCLUDE_DIRS} ${CMAKE_CURRENT_SOURCE_DIR}/include/excpt)
endif()

# RATL_LIBRARIES
set(RATL_LIBRARIES uuid rpcrt4 ole32 shlwapi oleaut32 msimg32 gdiplus gdi32 advapi32 user32 msvcrt kernel32)

##############################################################################

add_subdirectory(atltests)
