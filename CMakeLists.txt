# RATL --- ReactOS ATL
##############################################################################

# CMake minimum version
cmake_minimum_required(VERSION 2.4)

# enable testing
enable_testing()

# project name and language
project(RATL CXX)

##############################################################################

# libratl.a
add_library(RATL STATIC atlcore.cpp atlbase.cpp)

##############################################################################
