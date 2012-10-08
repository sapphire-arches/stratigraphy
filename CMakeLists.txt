cmake_minimum_required(VERSION 2.8)

if (${CMAKE_BINARY_DIR} STREQUAL ${CMAKE_SOURCE_DIR})
    message(FATAL_ERROR, "In source build")
endif()

project(libStratigraphy)

find_library(Boost 1.40)
include_directories(${Boost_INCLUDE_DIR})

add_subdirectory(stratigraphy)
