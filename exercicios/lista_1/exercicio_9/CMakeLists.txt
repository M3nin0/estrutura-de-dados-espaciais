cmake_minimum_required(VERSION 2.8.12)
     
project(exe9)
 
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -pedantic -std=c++14" CACHE STRING "compile flags" FORCE)
 
file(GLOB SRC_FILES "*.cpp")
file(GLOB HDR_FILES "*.hpp")
file(GLOB THDR_FILES "../exercicio_8/*.hpp")

add_executable(exe9 ${SRC_FILES} ${HDR_FILES} ${THDR_FILES})
