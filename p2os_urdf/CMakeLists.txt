cmake_minimum_required(VERSION 2.8.3)
project(p2os_urdf)

find_package(catkin REQUIRED COMPONENTS message_generation geometry_msgs sensor_msgs std_msgs robot_state_publisher urdf)

catkin_package(
    CATKIN_DEPENDS message_runtime robot_state_publisher urdf geometry_msgs sensor_msgs std_msgs
    LIBRARIES lib
)

include_directories(
  ${catkin_INCLUDE_DIRS}
)


add_executable(p2os_publisher src/publisher.cc)
target_link_libraries(p2os_publisher ${catkin_LIBRARIES})

install(TARGETS p2os_publisher
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

install(DIRECTORY 
   launch defs meshes models
   DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
 )
