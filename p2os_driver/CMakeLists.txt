cmake_minimum_required(VERSION 3.9.5)
project(p2os_driver)

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()
if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra)
endif()

find_package(catkin REQUIRED COMPONENTS
  p2os_msgs
  diagnostic_updater
  nav_msgs
  roscpp
  geometry_msgs
  tf
  std_msgs
  kdl_parser
)

catkin_package(
  INCLUDE_DIRS include
  LIBRARIES p2os_driver
  CATKIN_DEPENDS p2os_msgs nav_msgs roscpp geometry_msgs diagnostic_updater tf std_msgs kdl_parser
)

## Specify additional locations of header files
include_directories(include
  ${catkin_INCLUDE_DIRS}
)

## Declare a cpp executable
add_executable(p2os_driver
  src/p2osnode.cpp
  src/p2os.cpp
  src/kinecalc.cpp
  src/packet.cpp
  src/robot_params.cpp
  src/sip.cpp
  src/p2os_ptz.cpp
)

target_link_libraries(p2os_driver ${catkin_LIBRARIES})

## Mark executables and/or libraries for installation
install(TARGETS p2os_driver
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)
