p2os
====

P2OS ROS driver for Groovy

p2os_dashboard
--------------

This package holds the dashboard for the Robot. This serves as a tool to enable the motors, and view important messages from the P2OS Robots remotely. 

p2os_driver
-----------

Essential to the P2OS is the driver. This controls the interface for the P2OS controller. 

p2os_launch
-----------

Relevant ROS launch files for the Robot. 

p2os_teleop
-----------

Control the robot with a joystick or keyboard. 

p2os_urdf
---------

Allows you to see the robot within RVIZ for navigation purposes. 

To Do: 
------

The gazebo_plugin node for controlling the differential drive was recently removed (commented out in the CMakeLists.txt file) from Gazebo. So, the P2OS gazebo launch file fails. 
