# RATL --- ReactOS ATL
##############################################################################

# CMake minimum version
cmake_minimum_required(VERSION 2.4)

# enable testing
enable_testing()

# project name and languages
project(RATL C CXX)

##############################################################################

include_directories(atl common)

subdirs(atltests)

##############################################################################
