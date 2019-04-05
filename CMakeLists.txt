# RATL --- ReactOS ATL
##############################################################################

# CMake minimum version
cmake_minimum_required(VERSION 2.4)

# enable testing
enable_testing()

# project name and language
project(RATL CXX)

##############################################################################

include_directories(atl)

# libratl.a
add_library(ratl STATIC atl/atlcore.cpp atl/atlbase.cpp)

##############################################################################
