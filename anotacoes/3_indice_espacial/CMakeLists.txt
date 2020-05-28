cmake_minimum_required(VERSION 2.8.12)
     
project(kdtree)
 
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -pedantic -std=c++14" CACHE STRING "compile flags" FORCE)
 
file(GLOB SRC_FILES "src/*.cpp")
file(GLOB HDR_FILES "src/*.hpp")

add_executable(kdtree ${SRC_FILES} ${HDR_FILES})
