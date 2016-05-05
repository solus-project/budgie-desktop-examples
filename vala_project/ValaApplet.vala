/**
 * Copyright (C) 2016 Ikey Doherty
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *  
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

/**
 * All native Panel Applets require a factory function for the creation of new
 * Budgie.Applet instances.
 */
public class ValaAppletExample : GLib.Object, Budgie.Plugin {

    public Budgie.Applet get_panel_widget(string uuid)
    {
        return new ValaApplet(uuid);
    }
}

/**
 * This is the actual applet implementation. It's basically a GtkBin with
 * some extra methods, etc, available to it. Respect your neighbours on
 * the panel!!
 */
public class ValaApplet : Budgie.Applet
{
    Gtk.Popover? my_popover = null;
    Gtk.EventBox? box = null;

    /* Use this to register popovers with the panel system */
    unowned Budgie.PopoverManager? manager = null;

    public ValaApplet(string uuid)
    {
        /*
         * How to use relocatable schemas:
         *
        Object(settings_prefix = "/com/myawesome/applet/instance/awesome",
               settings_schema = "com.myawesome.applet");
        var settings = this.get_applet_settings(uuid); */
        Object();

        box = new Gtk.EventBox();
        add(box);
        var label = new Gtk.Label("I am Groot");
        box.add(label);

        /* Hook up a popover to the event box to catch clicks! */
        my_popover = new Gtk.Popover(box);
        var lab = new Gtk.Label("<span size='x-large'>Seriously, Groot!</span>");
        lab.use_markup = true;
        my_popover.add(lab);
        lab.margin = 20;
        lab.show_all();

        box.button_press_event.connect((e)=> {
            /* Not primary button? Good bye! */
            if (e.button != 1) {
                return Gdk.EVENT_PROPAGATE;
            }
            /* Hide if already showing */
            if (my_popover.get_visible()) {
                my_popover.hide();
            } else {
                /* Not showing, so show it.. */
                this.manager.show_popover(box);
            }
            return Gdk.EVENT_STOP;
        });


        show_all();
    }

    /**
     * Let the panel manager know we support a settings UI
     */
    public override bool supports_settings() {
        return true;
    }

    /**
     * Worth pointing out this is destroyed each time the user navigates
     * away from the view.
     */
    public override Gtk.Widget? get_settings_ui()
    {
        return new ValaAppletSettings();
    }

    /**
     * When using popovers, always register them in the entry method
     */
    public override void update_popovers(Budgie.PopoverManager? manager)
    {
        manager.register_popover(this.box, this.my_popover);
        this.manager = manager;
    }
}

/**
 * You can go further with this, but this is how we provide settings UIs for
 * the applet inside of Raven.
 */
public class ValaAppletSettings : Gtk.Box
{
    public ValaAppletSettings()
    {
        var label = new Gtk.Label("I am still Groot.");
        add(label);
        show_all();
    }
}

[ModuleInit]
public void peas_register_types(TypeModule module)
{
    /**
     * Boilerplate code. We register ValaAppletExample as a Budgie.Plugin to
     * the Peas Engine during module initialisation
     */
    var objmodule = module as Peas.ObjectModule;
    objmodule.register_extension_type(typeof(Budgie.Plugin), typeof(ValaAppletExample));
}
