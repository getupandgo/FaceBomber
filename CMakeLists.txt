cmake_minimum_required(VERSION 3.5)
project(FaceSwapper)

# path to folder containing dlib
include(../../lib/dlib/dlib/cmake)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
        src/faceSwapper.cpp src/faceSwapper.h)

add_executable(FaceSwapper ${SOURCE_FILES})