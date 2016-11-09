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

#define _GNU_SOURCE

#include "applet.h"

G_DEFINE_DYNAMIC_TYPE_EXTENDED(ExampleNativeApplet, example_native_applet, BUDGIE_TYPE_APPLET, 0, )

/**
 * Handle cleanup
 */
static void example_native_applet_dispose(GObject *object)
{
        G_OBJECT_CLASS(example_native_applet_parent_class)->dispose(object);
}

/**
 * Class initialisation
 */
static void example_native_applet_class_init(ExampleNativeAppletClass *klazz)
{
        GObjectClass *obj_class = G_OBJECT_CLASS(klazz);

        /* gobject vtable hookup */
        obj_class->dispose = example_native_applet_dispose;
}

/**
 * We have no cleaning ourselves to do
 */
static void example_native_applet_class_finalize(__budgie_unused__ ExampleNativeAppletClass *klazz)
{
}

/**
 * Initialisation of basic UI layout and such
 */
static void example_native_applet_init(ExampleNativeApplet *self)
{
        GtkWidget *label = NULL;

        label = gtk_label_new("I am native Groot.");
        gtk_container_add(GTK_CONTAINER(self), label);

        /* Show all of our things. */
        gtk_widget_show_all(GTK_WIDGET(self));
}

void example_native_applet_init_gtype(GTypeModule *module)
{
        example_native_applet_register_type(module);
}

BudgieApplet *example_native_applet_new(void)
{
        return g_object_new(EXAMPLE_TYPE_NATIVE_APPLET, NULL);
}

/*
 * Editor modelines  -  https://www.wireshark.org/tools/modelines.html
 *
 * Local variables:
 * c-basic-offset: 8
 * tab-width: 8
 * indent-tabs-mode: nil
 * End:
 *
 * vi: set shiftwidth=8 tabstop=8 expandtab:
 * :indentSize=8:tabSize=8:noTabs=true:
 */
