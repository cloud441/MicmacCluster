cmake_minimum_required(VERSION 2.8)
project( MicmacCluster )
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS}
                     src/)
add_executable( clusterizer
                src/clusterizer.cpp)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

target_link_libraries( clusterizer ${OpenCV_LIBS} )
