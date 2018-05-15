cmake_minimum_required(VERSION 2.8)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/modules/")

add_definitions(-std=c++11)

option(BUILD_EXAMPLE "Build example" ON)

add_subdirectory(src)

