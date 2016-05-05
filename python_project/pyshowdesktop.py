#!/usr/bin/env python3

# Copyright (C) 2016 Ikey Doherty
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
# 
# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.
#  
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
# THE SOFTWARE.

import gi.repository
gi.require_version('Budgie', '1.0')
gi.require_version('Wnck', '3.0')
from gi.repository import Budgie, GObject, Wnck, Gtk

class PyShowDesktop(GObject.GObject, Budgie.Plugin):
    """ This is simply an entry point into your Budgie Applet implementation.
        Note you must always override Object, and implement Plugin.
    """

    # Good manners, make sure we have unique name in GObject type system
    __gtype_name__ = "PyShowDesktop"

    def __init__(self):
        """ Initialisation is important.
        """
        GObject.Object.__init__(self)

    def do_get_panel_widget(self, uuid):
        """ This is where the real fun happens. Return a new Budgie.Applet
            instance with the given UUID. The UUID is determined by the
            BudgiePanelManager, and is used for lifetime tracking.
        """
        return PyShowDesktopApplet(uuid)

class PyShowDesktopApplet(Budgie.Applet):
    """ Budgie.Applet is in fact a Gtk.Bin """

    wn_screen = None
    button = None

    def __init__(self, uuid):
        Budgie.Applet.__init__(self)

        # Add a button to our UI
        self.button = Gtk.ToggleButton.new()
        self.button.set_relief(Gtk.ReliefStyle.NONE)
        self.button.set_active(False)
        self.add(self.button)
        self.wn_screen = Wnck.Screen.get_default()

        img = Gtk.Image.new_from_icon_name("user-desktop-symbolic", Gtk.IconSize.BUTTON)
        self.button.add(img)
        self.button.set_tooltip_text("Toggle the desktop (from Python!)")
        self.show_all()

        # Hook up Wnck signals
        self.wn_screen.connect_after('showing-desktop-changed', self.scr_changed)
        self.button.connect_after('clicked', self.on_clicked)

    def scr_changed(self, wscr, udata=None):
        """ WnckScreen changed, update button """
        self.button.set_active(self.wn_screen.get_showing_desktop())

    def on_clicked(self, widg, data=None):
        """ User clicked our button, update WnckScreen """
        self.wn_screen.toggle_showing_desktop(self.button.get_active())
