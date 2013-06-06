# Software License Agreement (BSD License)
#
# Copyright (c) 2008, Willow Garage, Inc.
# All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions
# are met:
#
#  * Redistributions of source code must retain the above copyright
#    notice, this list of conditions and the following disclaimer.
#  * Redistributions in binary form must reproduce the above
#    copyright notice, this list of conditions and the following
#    disclaimer in the documentation and/or other materials provided
#    with the distribution.
#  * Neither the name of the Willow Garage nor the names of its
#    contributors may be used to endorse or promote products derived
#    from this software without specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
# "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
# LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
# FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
# COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
# INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
# BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
# LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
# CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
# LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
# ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
# POSSIBILITY OF SUCH DAMAGE.

#       modifications to pr2_frame.py to work with p2os_dashboard
#       Copyright (C) 2010  David Feil-Seifer [dfseifer@usc.edu], Edward T. Kaszubski [kaszubsk@usc.edu]
#
#       This program is free software; you can redistribute it and/or modify
#       it under the terms of the GNU General Public License as published by
#       the Free Software Foundation; either version 2 of the License, or
#       (at your option) any later version.
#       
#       This program is distributed in the hope that it will be useful,
#       but WITHOUT ANY WARRANTY; without even the implied warranty of
#       MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#       GNU General Public License for more details.
#       
#       You should have received a copy of the GNU General Public License
#       along with this program; if not, write to the Free Software
#       Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
#       MA 02110-1301, USA.

import roslib
roslib.load_manifest('p2os_dashboard')

import wx
import wx.aui
import wx.py.shell
import rxtools
import rxtools.cppwidgets as rxtools

import robot_monitor
from robot_monitor.robot_monitor_panel import RobotMonitorPanel
from p2os_driver.msg import BatteryState, MotorState

import std_msgs.msg
import std_srvs.srv

import rospy
from roslib import rosenv

from os import path
import threading

from status_control import StatusControl
from rosout_frame import RosoutFrame

from power_state_control import PowerStateControl

from diagnostics_frame import DiagnosticsFrame

class P2OSFrame(wx.Frame):
    _CONFIG_WINDOW_X="/Window/X"
    _CONFIG_WINDOW_Y="/Window/Y"
    
    def __init__(self, parent, id=wx.ID_ANY, title='P2OS Dashboard', pos=wx.DefaultPosition, size=(400, 50), style=wx.CAPTION|wx.CLOSE_BOX|wx.STAY_ON_TOP):
        wx.Frame.__init__(self, parent, id, title, pos, size, style)
        
        wx.InitAllImageHandlers()

        self.motorStatePub = rospy.Publisher('cmd_motor_state', MotorState)
        self.motorStateSub = rospy.Subscriber("motor_state", MotorState, self.motorStateCallback)

        self.battStateSub = rospy.Subscriber("battery_state", BatteryState, self.battStateCallback)

        self.motorState = 0
        
        rospy.init_node('p2os_dashboard', anonymous=True)
        try:
            getattr(rxtools, "initRoscpp")
            rxtools.initRoscpp("p2os_dashboard_cpp", anonymous=True)
        except AttributeError:
            pass
        
        self.SetTitle('P2OS Dashboard (%s)'%rosenv.get_master_uri())
        
        icons_path = path.join(roslib.packages.get_pkg_dir('p2os_dashboard'), "icons/")
        
        sizer = wx.BoxSizer(wx.HORIZONTAL)
        self.SetSizer(sizer)
        
        static_sizer = wx.StaticBoxSizer(wx.StaticBox(self, wx.ID_ANY, "Diagnostic"), wx.HORIZONTAL)
        sizer.Add(static_sizer, 0)
        
        # Diagnostics
        self._diagnostics_button = StatusControl(self, wx.ID_ANY, icons_path, "diag", True)
        self._diagnostics_button.SetToolTip(wx.ToolTip("Diagnostics"))
        static_sizer.Add(self._diagnostics_button, 0)
        
        # Rosout
        self._rosout_button = StatusControl(self, wx.ID_ANY, icons_path, "rosout", True)
        self._rosout_button.SetToolTip(wx.ToolTip("Rosout"))
        static_sizer.Add(self._rosout_button, 0)
        
        # Motors
        self._motors_button = StatusControl(self, wx.ID_ANY, icons_path, "motor", True)
        self._motors_button.SetToolTip(wx.ToolTip("Motors"))
        static_sizer.Add(self._motors_button, 0)
        self._motors_button.Bind(wx.EVT_LEFT_DOWN, self.on_motors_clicked)
        
        static_sizer = wx.StaticBoxSizer(wx.StaticBox(self, wx.ID_ANY, "Battery"), wx.HORIZONTAL)
        sizer.Add(static_sizer, 0)
        
        # Battery State
        self._power_state_ctrl = PowerStateControl(self, wx.ID_ANY, icons_path)
        self._power_state_ctrl.SetToolTip(wx.ToolTip("Battery: Stale"))
        static_sizer.Add(self._power_state_ctrl, 1, wx.EXPAND)
        
        self._config = wx.Config("p2os_dashboard")
        
        self.Bind(wx.EVT_CLOSE, self.on_close)
        
        self.Layout()
        self.Fit()
        
        self._diagnostics_frame = DiagnosticsFrame(self, wx.ID_ANY, "Diagnostics")
        self._diagnostics_frame.Hide()
        self._diagnostics_frame.Center()
        self._diagnostics_button.Bind(wx.EVT_BUTTON, self.on_diagnostics_clicked)
        
        self._rosout_frame = RosoutFrame(self, wx.ID_ANY, "Rosout")
        self._rosout_frame.Hide()
        self._rosout_frame.Center()
        self._rosout_button.Bind(wx.EVT_BUTTON, self.on_rosout_clicked)
        
        self.load_config()
        
        self._timer = wx.Timer(self)
        self.Bind(wx.EVT_TIMER, self.on_timer)
        self._timer.Start(1000)
        
        self.battery_msg_last_time = rospy.Time.now()
        #self.motor_msg_good = false;
        
    def __del__(self):
        self._dashboard_agg_sub.unregister()

    def battStateCallback(self, msg):
		self.battery_msg_last_time = rospy.Time.now()
		self._power_state_ctrl.set_power_state(msg)

    def motorStateCallback(self, msg):
		self.motorState = msg.state

		if(self.motorState):
			self._motors_button.set_ok()
			self._motors_button.SetToolTip(wx.ToolTip("Motors: Running"))
		else:
			self._motors_button.set_error()
			self._motors_button.SetToolTip(wx.ToolTip("Motors: Halted"))

    def on_timer(self, evt):
      level = self._diagnostics_frame._diagnostics_panel.get_top_level_state()
      if (level == -1 or level == 3):
        if (self._diagnostics_button.set_stale()):
            self._diagnostics_button.SetToolTip(wx.ToolTip("Diagnostics: Stale"))
      elif (level >= 2):
        if (self._diagnostics_button.set_error()):
            self._diagnostics_button.SetToolTip(wx.ToolTip("Diagnostics: Error"))
      elif (level == 1):
        if (self._diagnostics_button.set_warn()):
            self._diagnostics_button.SetToolTip(wx.ToolTip("Diagnostics: Warning"))
      else:
        if (self._diagnostics_button.set_ok()):
            self._diagnostics_button.SetToolTip(wx.ToolTip("Diagnostics: OK"))
        
      
      if (rospy.Time.now() > self.battery_msg_last_time + rospy.Duration(5.0)):
		  #battery msg status is stale
		  #print "setting battery to stale"
		  self._power_state_ctrl.set_stale()
      
      self.update_rosout()
      self._power_state_ctrl.updateToolTip()

      if (rospy.is_shutdown()):
        self.Close()
        
    def on_diagnostics_clicked(self, evt):
      self._diagnostics_frame.Show()
      self._diagnostics_frame.Raise()
		
    def on_rosout_clicked(self, evt):
      self._rosout_frame.Show()
      self._rosout_frame.Raise()
      
    def on_motors_clicked(self, evt):
      menu = wx.Menu()
      menu.Bind(wx.EVT_MENU, self.on_reset_motors, menu.Append(wx.ID_ANY, "Enable"))
      menu.Bind(wx.EVT_MENU, self.on_halt_motors, menu.Append(wx.ID_ANY, "Disable"))
      self._motors_button.toggle(True)
      self.PopupMenu(menu)
      self._motors_button.toggle(False)
      
    def on_reset_motors(self, evt):

      self.motorStatePub.publish(MotorState(1))
    
    def on_halt_motors(self, evt):
      self.motorStatePub.publish(MotorState(0))
                
    def update_rosout(self):
      summary_dur = 30.0
      if (rospy.get_time() < 30.0):
          summary_dur = rospy.get_time() - 1.0
          
      if (summary_dur < 0):
          summary_dur = 0.0
    
      summary = self._rosout_frame.get_panel().getMessageSummary(summary_dur)
      
      if (summary.fatal or summary.error):
        self._rosout_button.set_error()
      elif (summary.warn):
        self._rosout_button.set_warn()
      else:
        self._rosout_button.set_ok()
        
        
      tooltip = ""
      if (summary.fatal):
        tooltip += "\nFatal: %s"%(summary.fatal)
      if (summary.error):
        tooltip += "\nError: %s"%(summary.error)
      if (summary.warn):
        tooltip += "\nWarn: %s"%(summary.warn)
      if (summary.info):
        tooltip += "\nInfo: %s"%(summary.info)
      if (summary.debug):
        tooltip += "\nDebug: %s"%(summary.debug)
      
      if (len(tooltip) == 0):
        tooltip = "Rosout: no recent activity"
      else:
        tooltip = "Rosout: recent activity:" + tooltip
    
      if (tooltip != self._rosout_button.GetToolTip().GetTip()):
          self._rosout_button.SetToolTip(wx.ToolTip(tooltip))
        
    def load_config(self):
      # Load our window options
      (x, y) = self.GetPositionTuple()
      (width, height) = self.GetSizeTuple()
      if (self._config.HasEntry(self._CONFIG_WINDOW_X)):
          x = self._config.ReadInt(self._CONFIG_WINDOW_X)
      if (self._config.HasEntry(self._CONFIG_WINDOW_Y)):
          y = self._config.ReadInt(self._CONFIG_WINDOW_Y)
      
      self.SetPosition((x, y))
      self.SetSize((width, height))
        
    def save_config(self):
      config = self._config
      
      (x, y) = self.GetPositionTuple()
      (width, height) = self.GetSizeTuple()
      config.WriteInt(self._CONFIG_WINDOW_X, x)
      config.WriteInt(self._CONFIG_WINDOW_Y, y)
      
      config.Flush()
        
    def on_close(self, event):
      self.save_config()
      self.Destroy()
