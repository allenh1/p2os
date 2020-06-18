^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
Changelog for package p2os_teleop
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

2.2.0 (2019-03-14)
------------------
* Update email address (`#58 <https://github.com/allenh1/p2os/issues/58>`_)
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
* Updated changelog.
* merged.
* Updated package metadata, as well as added the correct c++ flags to the urdf file (for Gentoo support).
* Contributors: Hunter L. Allen

* merged.
* Updated package metadata, as well as added the correct c++ flags to the urdf file (for Gentoo support).
* Contributors: Hunter L. Allen

2.0.6 (2017-05-22)
------------------

2.0.5 (2016-05-26)
------------------

2.0.4 (2016-05-26)
------------------

2.0.3 (2015-10-25)
------------------

2.0.2 (2015-08-04)
------------------

2.0.1 (2015-07-11)
------------------

1.0.13 (2015-05-02)
-------------------
* this fixes issue `#30 <https://github.com/allenh1/p2os/issues/30>`_
* Contributors: Guy Burroughes

1.0.12 (2014-06-25)
-------------------
* General cleanup and fixing issues with the code
* Contributors: Aris Synodinos

1.0.10 (2014-05-28)
-------------------
* Added issue tracker to package.xml for telop
* Contributors: Hunter Allen

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
* Cleaned up for release
* Removed manifest and mainpage

* Updated to match hmt-git.com

* Updated to hmt-git.com repo

1.0.1 (2013-07-22)
------------------
* Updating to match hmt-git.com repo
* Fixed cmake file
* Removed line
* Updated p2os_teleop package to use catkin_make
* added the code
