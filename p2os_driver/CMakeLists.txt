cmake_minimum_required(VERSION 3.5)
project(p2os_driver)

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()
if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra)
endif()

find_package(ament_cmake_auto REQUIRED)
find_package(ament_cmake_ros REQUIRED)

set(req_deps
  "p2os_msgs"
  "std_msgs"
  "nav_msgs"
  "rclcpp"
  "rcutils"
  "geometry_msgs"
  "tf2"
  "tf2_ros"
  "tf2_msgs"
  "tf2_geometry_msgs"
)

ament_auto_find_build_dependencies(REQUIRED ${req_deps})

INCLUDE_DIRECTORIES(include)

## Declare a cpp executable
ament_auto_add_executable(p2os_driver
  src/p2osnode.cc
  src/p2os.cc
  src/kinecalc.cc
  src/packet.cc
  src/robot_params.cc
  src/sip.cc
  src/p2os_ptz.cpp
)
ament_target_dependencies(p2os_driver ${req_deps})

## Mark executables and/or libraries for installation
install(
  TARGETS p2os_driver
  DESTINATION lib/${PROJECT_NAME}
)

ament_auto_package()
