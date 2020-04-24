cmake_minimum_required(VERSION 2.8.3)
project(Console)

## Compile as C++11, supported in ROS Kinetic and newer
# add_compile_options(-std=c++11)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  genmsg
)

find_package(OpenCV REQUIRED)
if(NOT OpenCV_FOUND)
    message(FATAL_ERROR "\n\n OpenCV2 is missing")
endif()

add_compile_options(-std=c++11)
SET(SRC_LIST src/main.cpp 
            src/console.cpp)

## Declare ROS messages and services
add_message_files(FILES  gripper.msg setpoint.msg)
#add_service_files(FILES AddTwoInts.srv)

## Generate added messages and services
generate_messages(DEPENDENCIES std_msgs)

## Declare a catkin package
catkin_package(
    CATKIN_DEPENDS 
    )


## Build talker and listener
include_directories(include ${catkin_INCLUDE_DIRS})
## include_directories(/usr/local/include/serial)
include_directories(${OpenCV_INCLUDE_DIRS})

#add_executable(auxiliary src/main.cpp src/datapackage.cpp src/arm.cpp)
add_executable(panel ${SRC_LIST})
target_link_libraries(panel ${catkin_LIBRARIES} ${OpenCV_LIBS})
#add_dependencies(auxiliary beginner_tutorials_generate_messages_cpp)

#add_executable(listener src/listener.cpp)
#target_link_libraries(listener ${catkin_LIBRARIES})
#add_dependencies(listener beginner_tutorials_generate_messages_cpp)
