cmake_minimum_required(VERSION 2.8.3)
project(p2os_teleop)

find_package(catkin REQUIRED COMPONENTS message_generation geometry_msgs std_msgs sensor_msgs tf)

#set the default path for built executables to the "bin" directory
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
#set the default path for built libraries to the "lib" directory
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

generate_messages(
  DEPENDENCIES 
  geometry_msgs 
  sensor_msgs
  std_msgs
)

catkin_package(
    CATKIN_DEPENDS message_runtime geometry_msgs sensor_msgs tf
    INCLUDE_DIRS 
    LIBRARIES lib
)

add_executable(p2os_teleop src/p2os_teleop.cc)
target_link_libraries(p2os_teleop ${catkin_LIBRARIES})

install(TARGETS p2os_teleop
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)
