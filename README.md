p2os
====

P2OS ROS driver for Groovy. We are currently updating the packages to use [catkin](http://ros.org/wiki/catkin) instead of rosbuild.

p2os_dashboard
--------------

This package holds the dashboard for the Robot. This serves as a tool to enable the motors, and view important messages from the P2OS Robots remotely. 
No catkin yet. 

p2os_driver
-----------

Essential to the P2OS is the driver. This controls the interface for the P2OS controller. 
No catkin.

p2os_launch
-----------

Relevant ROS launch files for the Robot. 
No catkin.

p2os_teleop
-----------

Control the robot with a joystick or keyboard. 
Catkin support!

p2os_urdf
---------

Allows you to see the robot within RVIZ for navigation purposes. 
Catkin support!

To Do: 
------

* The gazebo_plugin node for controlling the differential drive was recently removed (commented out in the CMakeLists.txt file) from Gazebo. So, the P2OS gazebo launch file fails. 
* Update the rest of the packages to use the catkin build system instead of rosbuild.
