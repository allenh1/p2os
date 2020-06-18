^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
Changelog for package p2os_driver
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

2.2.0 (2019-03-14)
------------------
* Update email address (`#58 <https://github.com/allenh1/p2os/issues/58>`_)
* Fix driver license (`#56 <https://github.com/allenh1/p2os/issues/56>`_)
  * Upon further inspection, this p2os_driver is GPL 2
  * Fix kinecalc license line
  * Update p2os_ptz license
  * Fix robot_params license
* Add CI (`#54 <https://github.com/allenh1/p2os/issues/54>`_)
  * Add .travis.yml
  * Add .gitignore
  * Add test script
  * Rename *.h to *.hpp
  * Rename *.cc to *.cpp
  * Apply change to CMakeLists.txt
  * Fix copyright line(s), as well as fix header guard style
  * Default standard to C++14, and bump CMake minimum to 3.9.5
  * Remove unused boost include
  * Make headers pass CI
  * Add build status to the README
* Contributors: Hunter L. Allen

2.2.1 (2020-06-18)
------------------
* Two fixes for Melodic. (`#62 <https://github.com/allenh1/p2os/issues/62>`_)
  In p2os_driver, the p2os_msgs_gencpp doesn't exist (and, as
  far as I can tell, never existed).  It worked up until recently
  because older versions of CMake would complain but not fail,
  while more recent cmake versions actually fail.  Just remove
  the dependency.
  The second fix is a cosmetic issue, where CMake would spew a
  bunch of warnings on the command line.  Increase the version
  to 3.9.5 to match other CMakeLists.txt and to get rid of the
  warnings.
* Prepare release 2.2.0 (`#59 <https://github.com/allenh1/p2os/issues/59>`_)
  * Update changelog
  * 2.2.0
* Update email address (`#58 <https://github.com/allenh1/p2os/issues/58>`_)
* Fix driver license (`#56 <https://github.com/allenh1/p2os/issues/56>`_)
  * Upon further inspection, this p2os_driver is GPL 2
  * Fix kinecalc license line
  * Update p2os_ptz license
  * Fix robot_params license
* Add CI (`#54 <https://github.com/allenh1/p2os/issues/54>`_)
  * Add .travis.yml
  * Add .gitignore
  * Add test script
  * Rename *.h to *.hpp
  * Rename *.cc to *.cpp
  * Apply change to CMakeLists.txt
  * Fix copyright line(s), as well as fix header guard style
  * Default standard to C++14, and bump CMake minimum to 3.9.5
  * Remove unused boost include
  * Make headers pass CI
  * Add build status to the README
* Contributors: Chris Lalancette, Hunter L. Allen

2.1.1 (2018-07-03)
------------------

2.1.0 (2017-08-01)
------------------
* Switch to format 2 (`#48 <https://github.com/allenh1/p2os/issues/48>`_)
  * Update p2os_launch to package.xml format 2.
  * Update p2os_driver to package.xml format 2.
  * Update p2os_urdf to package.xml format 2.
  * Update p2os_teleop package.xml to format 2.
  * Update p2os_msgs to package.xml format 2.
  * Update p2os_doc to package.xml format 2.
* Contributors: Hunter Allen

2.0.7 (2017-05-30)
------------------
* Made a small change to prepare version bump.
* Updated changelog.
* Missed a paren.
* Fixed compiler error.
* Contributors: Hunter L. Allen

* Missed a paren.
* Fixed compiler error.
* Contributors: Hunter L. Allen

2.0.6 (2017-05-22)
------------------

2.0.5 (2016-05-26)
------------------
* Added missing dependencies.
* Contributors: Hunter L. Allen

2.0.4 (2016-05-26)
------------------
* Cleaned up driver source.
* Contributors: Hunter L. Allen

2.0.3 (2015-10-25)
------------------
* Reformatted code style.
* Cleaned up the driver.
* Contributors: Hunter Allen

2.0.2 (2015-08-04)
------------------
* Fixed a small issue (but a big problem) in the source.
* Contributors: Hunter Allen

2.0.1 (2015-07-11)
------------------
* Doing some cleanup of the code.
* Additional code updates for p3dx-sh-lms1xx parameters.
* Added robot parameters for the P3DX models that ship with LMS1xx lasers.
* Contributors: Damjan Miklic, Hunter Allen

1.0.13 (2015-05-02)
-------------------
* Added parameters the p2os node to specify frame IDs for the odom->base_link transform.
* Contributors: Damjan Miklic

1.0.12 (2014-06-25)
-------------------
* Updated to match indigo-devel
* Fixed dependency issues and cleaned up package.xml and CMakeLists.txt for p2os_driver and p2os_msgs
* Separated p2os_driver and p2os_msgs
* Fixed include paths of p2os_driver
* General cleanup and fixing issues with the code
* Contributors: Aris Synodinos, Hunter Allen

1.0.11 (2014-06-25)
-------------------

1.0.10 (2014-05-28)
-------------------

1.0.9 (2013-08-18)
------------------
* Updated version
* 1.0.7
* Updated changelogs

1.0.7 (2013-08-18)
------------------

* Updated to match hmt-git.com repository

1.0.5 (2013-07-23)
------------------

* Syncing github with hmt-git.com repository

1.0.1 (2013-07-22)
------------------
* Updating to match hmt-git.com repo
* Added forgotten dependencies
* Added package dependencies
* Updated C++ Code
* Updated package.xml
* Updated CMakeLists.txt
* Updated CMakeLists.txt
* Added message header files
* Remapped the files to the right headers
* cleaned up include directory
* Updated the main driver to use catkin
* Added covariance to Odometry msg.
* Modified the CMakeLists.txt file.
* added the code
