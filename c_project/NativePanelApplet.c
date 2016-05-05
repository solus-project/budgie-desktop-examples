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

#include "NativeApplet.h"

G_BEGIN_DECLS

/**
 * Define our type, which is a BudgieApplet extension
 */
#define NATIVE_TYPE_PANEL_APPLET native_panel_applet_get_type ()
G_DECLARE_FINAL_TYPE(NativePanelApplet, native_panel_applet, NATIVE, PANEL_APPLET, BudgieApplet)

G_END_DECLS

/**
 * Pass properties here too if you wish
 */
BudgieApplet *native_panel_applet_new(void)
{
        return BUDGIE_APPLET(g_object_new(NATIVE_TYPE_PANEL_APPLET, NULL));
}

/**
 * Simple instance tracking
 */
struct _NativePanelApplet
{
        BudgieApplet parent;
};

/**
 * Initialise this applet instance. For now just throw on a label :)
 */
static void native_panel_applet_init(NativePanelApplet *self)
{
        GtkWidget *label = NULL;

        label = gtk_label_new("I am native Groot.");
        gtk_container_add(GTK_CONTAINER(self), label);

        /* Show all of our things. */
        gtk_widget_show_all(GTK_WIDGET(self));
}

/**
 * Unused in our implementation. Feel free to override class methods of
 * BudgieApplet here.
 */
static void native_panel_applet_class_init(__budgie_unused__ NativePanelAppletClass *cls)
{
}

static void native_panel_applet_class_finalize(__budgie_unused__ NativePanelAppletClass *cls)
{
}

/**
 * This is us now doing the implementation chain ups..
 */

G_DEFINE_DYNAMIC_TYPE_EXTENDED(NativePanelApplet, native_panel_applet, BUDGIE_TYPE_APPLET, 0, )

/**
 * Work around the register types issue.
 */
void native_panel_applet_init_gtype(GTypeModule *module)
{
        native_panel_applet_register_type(module);
}
