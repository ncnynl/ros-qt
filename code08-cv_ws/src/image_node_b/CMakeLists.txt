cmake_minimum_required(VERSION 2.8.3)
project(image_node_b)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
if(WIN32 AND NOT CYGWIN)
    set(HOME $ENV{PROFILE})
else()
    set(HOME $ENV{HOME})
endif()

find_package(catkin REQUIRED COMPONENTS
 roscpp
 rospy
 std_msgs

 sensor_msgs
 cv_bridge
 image_transport
)

find_package(OpenCV REQUIRED)

catkin_package(CATKIN_DEPENDS
roscpp
std_msgs
)

include_directories(
include
${OpenCV_INCLUDE_DIRS}
${catkin_INCLUDE_DIRS}
)


### find files

file(GLOB_RECURSE HEADER_FILES ${CMAKE_CURRENT_SOURCE_DIR}/include/*.h*)
file(GLOB_RECURSE SOURCE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.c*)

add_executable(image_node_b
${HEADER_FILES}
${SOURCE_FILES}
)

target_link_libraries(image_node_b
${catkin_LIBRARIES}
${OpenCV_LIBRARIES}

)

