cmake_minimum_required(VERSION 2.8.3)
project(vision_tracker)

## Compile as C++11, supported in ROS Kinetic and newer
add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  cv_bridge
  image_transport
  roscpp
  sensor_msgs
  vision_msgs
  message_filters
)

catkin_package(
  INCLUDE_DIRS include
#  LIBRARIES vision_tracker
  CATKIN_DEPENDS cv_bridge image_transport roscpp
#  DEPENDS system_lib
)

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
  ${OpenCV_INCLUDE_DIRS}
)

add_executable(vision_tracker_node src/vision_tracker_node.cpp src/vision_tracker.cpp)
target_link_libraries(vision_tracker_node ${catkin_LIBRARIES} ${OpenCV_LIBRARIES})