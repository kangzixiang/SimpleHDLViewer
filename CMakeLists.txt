cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
 
project(pcl_hdl_viewer_simple)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DDEBUG -O0 -Wall -g2 -ggdb")
set (EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

find_package(PCL 1.10 REQUIRED COMPONENTS)
 
include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})
#LINK_LIBRARIES(${PCL_LIBRARIES})

aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} CPP_SOURCE)
#add_executable(pcl_hdl_viewer_simple hdl_viewer_simple.cpp)
add_executable(pcl_hdl_viewer_simple ${CPP_SOURCE})

target_link_libraries(pcl_hdl_viewer_simple ${PCL_LIBRARIES} pthread)
