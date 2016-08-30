cmake_minimum_required(VERSION 3.5)
project(FaceBomber)

# path to folder containing dlib
include(../../lib/dlib/dlib/cmake)

find_package( OpenCV REQUIRED )
if( OpenCV_FOUND )
    include_directories( ${OpenCV_INCLUDE_DIRS} )
endif( OpenCV_FOUND )

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(SOURCE_FILES
        src/faceBomber.cpp src/faceBomber.h src/main.cpp)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} dlib)
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})