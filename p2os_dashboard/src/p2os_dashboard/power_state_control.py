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

#       modifications to power_state_control.py to work with p2os_dashboard
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

#from pr2_msgs.msg import PowerState, PowerBoardState
#from pr2_power_board.srv import PowerBoardCommand, PowerBoardCommandRequest

from os import path

class PowerStateControl(wx.Window):
  def __init__(self, parent, id, icons_path):
    wx.Window.__init__(self, parent, id, wx.DefaultPosition, wx.Size(60, 32))
    
    self._pct = 0
    self._vlt = 0
    
    self._left_bitmap = wx.Bitmap(path.join(icons_path, "battery-minus.png"), wx.BITMAP_TYPE_PNG)
    self._right_bitmap = wx.Bitmap(path.join(icons_path, "battery-plus.png"), wx.BITMAP_TYPE_PNG)
    self._plug_bitmap = wx.Bitmap(path.join(icons_path, "battery-charging.png"), wx.BITMAP_TYPE_PNG)
    self._background_bitmap = wx.Bitmap(path.join(icons_path, "battery-background.png"), wx.BITMAP_TYPE_PNG)
    self._green = wx.Bitmap(path.join(icons_path, "battery-green-bar.png"), wx.BITMAP_TYPE_PNG)
    self._yellow = wx.Bitmap(path.join(icons_path, "battery-yellow-bar.png"), wx.BITMAP_TYPE_PNG)
    self._red = wx.Bitmap(path.join(icons_path, "battery-red-bar.png"), wx.BITMAP_TYPE_PNG)
    
    self.SetSize(wx.Size(self._left_bitmap.GetWidth() + self._right_bitmap.GetWidth() + self._background_bitmap.GetWidth(), 32))
    
    self._start_x = self._left_bitmap.GetWidth()
    self._end_x = self.GetSize().x - self._right_bitmap.GetWidth()
    self._width = self._end_x - self._start_x
    
    self._plugged_in = False
    
    self.Bind(wx.EVT_PAINT, self.on_paint)

  def on_paint(self, evt):
    dc = wx.BufferedPaintDC(self)

    dc.SetBackground(wx.Brush(self.GetBackgroundColour()))
    dc.Clear()
 
    w = self.GetSize().GetWidth()
    h = self._left_bitmap.GetHeight()
    
    color_bitmap = None
    if (self._pct > 0.5):
      color_bitmap = self._green
    elif (self._pct > 0.3):
      color_bitmap = self._yellow
    else:
      color_bitmap = self._red
    
    dc.DrawBitmap(self._background_bitmap, self._start_x, 0, True)
    
    color_image = color_bitmap.ConvertToImage()
    scaled_color_image = color_image.Rescale(round(self._width * self._pct), color_bitmap.GetHeight())
    color_bitmap = wx.BitmapFromImage(scaled_color_image)
    dc.DrawBitmap(color_bitmap, self._start_x, 0, True)
    dc.DrawBitmap(self._left_bitmap, 0, 0, True)
    dc.DrawBitmap(self._right_bitmap, self._end_x, 0, True)
          
  def set_power_state(self, msg):
	last_pct = self._pct
	last_vlt = self._vlt
	last_plugged_in = self._plugged_in

	self._pct = (msg.voltage - 11.3) / 2.2 #msg.relative_capacity / 100.0
	if self._pct > 1.0:
		self._pct = 1.0
	
	if self._pct < 0.0:
		self._pct = 0.0
	self._vlt = msg.voltage

	self.Refresh()
    
  def updateToolTip(self):
	self.SetToolTip(wx.ToolTip("Battery: %.2f%% (%.2f v)"%(self._pct * 100.0, self._vlt)))
	self.Refresh()

    
  def set_stale(self):
    self._plugged_in = 0
    self._pct = 0
    self._vlt = 0
    self.SetToolTip(wx.ToolTip("Battery: Stale"))
    
    self.Refresh()
