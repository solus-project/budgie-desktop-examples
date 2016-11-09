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

#pragma once

#include <budgie-desktop/applet.h>
#include <gtk/gtk.h>

#define __budgie_unused__ __attribute__((unused))

G_BEGIN_DECLS

typedef struct _ExampleNativeApplet ExampleNativeApplet;
typedef struct _ExampleNativeAppletClass ExampleNativeAppletClass;

#define EXAMPLE_TYPE_NATIVE_APPLET example_native_applet_get_type()
#define EXAMPLE_NATIVE_APPLET(o)                                                                   \
        (G_TYPE_CHECK_INSTANCE_CAST((o), EXAMPLE_TYPE_NATIVE_APPLET, ExampleNativeApplet))
#define EXAMPLE_IS_NATIVE_APPLET(o) (G_TYPE_CHECK_INSTANCE_TYPE((o), EXAMPLE_TYPE_NATIVE_APPLET))
#define EXAMPLE_NATIVE_APPLET_CLASS(o)                                                             \
        (G_TYPE_CHECK_CLASS_CAST((o), EXAMPLE_TYPE_NATIVE_APPLET, ExampleNativeAppletClass))
#define EXAMPLE_IS_NATIVE_APPLET_CLASS(o) (G_TYPE_CHECK_CLASS_TYPE((o), EXAMPLE_TYPE_NATIVE_APPLET))
#define EXAMPLE_NATIVE_APPLET_GET_CLASS(o)                                                         \
        (G_TYPE_INSTANCE_GET_CLASS((o), EXAMPLE_TYPE_NATIVE_APPLET, ExampleNativeAppletClass))

struct _ExampleNativeAppletClass {
        BudgieAppletClass parent_class;
};

struct _ExampleNativeApplet {
        BudgieApplet parent;
};

GType example_native_applet_get_type(void);

/**
 * Public for the plugin to allow registration of types
 */
void example_native_applet_init_gtype(GTypeModule *module);

/**
 * Construct a new ExampleNativeApplet
 */
BudgieApplet *example_native_applet_new(void);

G_END_DECLS

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
