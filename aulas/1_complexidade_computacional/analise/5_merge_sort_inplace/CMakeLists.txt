cmake_minimum_required(VERSION 2.8.12)
     
project(mergesortinplace)
 
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -pedantic -std=c++14" CACHE STRING "compile flags" FORCE)
 
file(GLOB SRC_FILES "*.cpp")
file(GLOB HDR_FILES "*.hpp")
file(GLOB SRC_BENCHMARK "../benchmark/*.cpp")
file(GLOB HDR_BENCHMARK "../benchmark/*.hpp")
file(GLOB UTIL_SRC_BENCHMARK "../utils/*.cpp")
file(GLOB UTIL_HDR_BENCHMARK "../utils/*.hpp") 

add_executable(mergesortinplace ${SRC_FILES} ${HDR_FILES} ${SRC_BENCHMARK} ${HDR_BENCHMARK}
                                ${UTIL_SRC_BENCHMARK} ${UTIL_HDR_BENCHMARK})
