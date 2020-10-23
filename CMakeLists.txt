# Project:
include_directories( ${Boost_INCLUDE_DIR}
                     src
                     src/opt_parser
                     src/clusterize
                     src/exec_cmd
                     src/parser
                     )

add_executable( clusterizer
                src/clusterizer.cpp
                src/opt_parser/opt_parser.cpp
                src/clusterize/clusterize.cpp
                src/exec_cmd/exec_cmd.cpp
                src/parser/parser.cpp
                )




### SETUP ###

cmake_minimum_required(VERSION 3.12)
project( MicmacCluster )
set(CMAKE_CXX_STANDARD 17)

#BOOST Libraries:
if (CMAKE_BUILD_TYPE STREQUAL "Release")
    set(Boost_USE_STATIC_LIBS ON)
endif()

find_package( Boost COMPONENTS system program_options REQUIRED)
set(LIBRARIES Boost::system Boost::program_options ${CMAKE_DL_LIBS})




set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

target_link_libraries( clusterizer
                    ${Boost_LIBRARIES}
                    )
