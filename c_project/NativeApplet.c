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

#include <budgie-desktop/plugin.h>
#include <gobject/gobject.h>

#define __budgie_unused__ __attribute__ ((unused))

G_BEGIN_DECLS

/**
 * Define our loader cruft
 */
#define NATIVE_TYPE_APPLET native_applet_get_type ()
G_DECLARE_FINAL_TYPE(NativeApplet, native_applet, NATIVE, APPLET, GObject)

G_END_DECLS

/**
 * This is apparently our instance
 */
struct _NativeApplet
{
        int __unused0;
};

/**
 * Return a new panel widget
 */
static GtkWidget *native_applet_get_panel_widget(__budgie_unused__ const char *uuid)
{
        return NULL;
}

/**
 * Implement interface and override methods
 */
static void native_applet_iface_init(BudgiePluginIface *iface)
{
        iface->get_panel_widget = native_applet_get_panel_widget;
}

/**
 * Override anything you need here like ->destroy, etc.
 */
static void native_applet_class_init(__budgie_unused__ NativeAppletClass *cl)
{
}

/**
 * Unused function
 */
static void native_applet_init(__budgie_unused__ NativeApplet *self)
{
}
static void native_applet_class_finalize(__budgie_unused__ NativeAppletClass *cls)
{
}

/**
 * This is us now doing the implementation chain ups..
 */

G_DEFINE_DYNAMIC_TYPE_EXTENDED(NativeApplet, native_applet, G_TYPE_OBJECT,
                               0, G_IMPLEMENT_INTERFACE_DYNAMIC (BUDGIE_TYPE_PLUGIN,
                                                                 native_applet_iface_init))

/**
 * Export the types back to peas
 */
G_MODULE_EXPORT void
peas_register_type(PeasObjectModule *module)
{
        native_applet_register_type(G_TYPE_MODULE(module));

        peas_object_module_register_extension_type(module,
                                                   BUDGIE_TYPE_PLUGIN,
                                                   NATIVE_TYPE_APPLET);
}
