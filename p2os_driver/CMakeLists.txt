# http://ros.org/doc/groovy/api/catkin/html/user_guide/supposed.html
cmake_minimum_required(VERSION 2.8.3)
project(p2os_driver)
# Load catkin and all dependencies required for this package
# TODO: remove all from COMPONENTS that are not catkin packages.
find_package(catkin REQUIRED COMPONENTS message_generation geometry_msgs std_msgs tf)

add_message_files(
  FILES
  AIO.msg
  BatteryState.msg
  DIO.msg
  GripperState.msg
  GripState.msg
  LiftState.msg
  MotorState.msg
  PTZState.msg
  SonarArray.msg
)

# CATKIN_MIGRATION: removed during catkin migration
include($ENV{ROS_ROOT}/core/rosbuild/rosbuild.cmake)

#set the default path for built executables to the "bin" directory
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
#set the default path for built libraries to the "lib" directory
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

#common commands for building c++ executables and libraries
#add_library(${PROJECT_NAME} src/example.cpp)
#target_link_libraries(${PROJECT_NAME} another_library)
#
# CATKIN_MIGRATION: removed during catkin migration
# rosbuild_add_boost_directories()
#find_package(Boost REQUIRED COMPONENTS thread)
include_directories(include/p2os_driver ${catkin_INCLUDE_DIRS})
#target_link_libraries(example ${PROJECT_NAME})
## Generate added messages and services with any dependencies listed here
generate_messages(
  DEPENDENCIES 
  geometry_msgs 
  std_msgs
)
# TODO: fill in what other packages will need to use this package
## DEPENDS: system dependencies of this project that dependent projects also need
## CATKIN_DEPENDS: catkin_packages dependent projects also need
## INCLUDE_DIRS: 
## LIBRARIES: libraries you create in this project that dependent projects also need
catkin_package(
    # DEPENDS roscpp joy geometry_msgs
    CATKIN_DEPENDS message_runtime geometry_msgs tf
    INCLUDE_DIRS 
    LIBRARIES lib
)

add_executable(p2os_driver  src/p2osnode.cc 
                            src/p2os.cc 
                            src/kinecalc.cc 
                            src/packet.cc 
                            src/robot_params.cc 
                            src/sip.cc 
                            src/p2os_ptz.cpp)

target_link_libraries(p2os_driver ${catkin_LIBRARIES})

install(TARGETS p2os_driver
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

install(DIRECTORY 
   launch
   DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
 )