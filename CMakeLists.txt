cmake_minimum_required(VERSION 3.5)
project(FaceBomber)

# path to folder containing dlib
include(../../lib/dlib/dlib/cmake)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
        src/faceBomber.cpp src/faceBomber.h src/main.cpp)

add_executable(FaceBomber ${SOURCE_FILES})