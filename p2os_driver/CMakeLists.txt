cmake_minimum_required(VERSION 2.8.3)
project(p2os_driver)

find_package(catkin REQUIRED COMPONENTS diagnostic_updater nav_msgs message_generation roscpp geometry_msgs tf std_msgs)

#######################################
## Declare ROS messages and services ##
#######################################

## Generate messages in the 'msg' folder
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

generate_messages(
  DEPENDENCIES
  std_msgs
  geometry_msgs
  nav_msgs
)

#add_dependencies(p2os_driver nav_msgs_gencpp)
###################################################
## Declare things to be passed to other projects ##
###################################################

## LIBRARIES: libraries you create in this project that dependent projects also need
## CATKIN_DEPENDS: catkin_packages dependent projects also need
## DEPENDS: system dependencies of this project that dependent projects also need
catkin_package(
   INCLUDE_DIRS include
#  LIBRARIES p2os_driver
   CATKIN_DEPENDS message_runtime nav_msgs roscpp geometry_msgs diagnostic_updater tf std_msgs
#  DEPENDS system_lib
)

###########
## Build ##
###########

## Specify additional locations of header files
include_directories(include
  ${catkin_INCLUDE_DIRS}
)

## Declare a cpp executable
add_executable(p2os_driver  src/p2osnode.cc 
                            src/p2os.cc 
                            src/kinecalc.cc 
                            src/packet.cc 
                            src/robot_params.cc 
                            src/sip.cc 
                            src/p2os_ptz.cpp)
target_link_libraries(p2os_driver ${catkin_LIBRARIES})
add_dependencies(p2os_driver nav_msgs_gencpp)

#############
## Install ##
#############

## Mark executables and/or libraries for installation
install(TARGETS p2os_driver
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

## Mark other files for installation (e.g. launch and bag files, etc.)
 install(DIRECTORY 
   launch
   DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
 )
