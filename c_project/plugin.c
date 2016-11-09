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

#include <budgie-desktop/plugin.h>

#include "applet.h"
#include "plugin.h"

static void example_native_plugin_iface_init(BudgiePluginIface *iface);

G_DEFINE_DYNAMIC_TYPE_EXTENDED(ExampleNativePlugin, example_native_plugin, G_TYPE_OBJECT, 0,
                               G_IMPLEMENT_INTERFACE_DYNAMIC(BUDGIE_TYPE_PLUGIN,
                                                             example_native_plugin_iface_init))

/**
 * Return a new panel widget
 */
static BudgieApplet *native_applet_get_panel_widget(__budgie_unused__ BudgiePlugin *self,
                                                    __budgie_unused__ gchar *uuid)
{
        /* TODO: Propagate the UUID to the applet */
        return example_native_applet_new();
}

/**
 * Handle cleanup
 */
static void example_native_plugin_dispose(GObject *object)
{
        G_OBJECT_CLASS(example_native_plugin_parent_class)->dispose(object);
}

/**
 * Class initialisation
 */
static void example_native_plugin_class_init(ExampleNativePluginClass *klazz)
{
        GObjectClass *obj_class = G_OBJECT_CLASS(klazz);

        /* gobject vtable hookup */
        obj_class->dispose = example_native_plugin_dispose;
}

/**
 * Implement the BudgiePlugin interface, i.e the factory method get_panel_widget
 */
static void example_native_plugin_iface_init(BudgiePluginIface *iface)
{
        iface->get_panel_widget = native_applet_get_panel_widget;
}

/**
 * No-op, just skips compiler errors
 */
static void example_native_plugin_init(__budgie_unused__ ExampleNativePlugin *self)
{
}

/**
 * We have no cleaning ourselves to do
 */
static void example_native_plugin_class_finalize(__budgie_unused__ ExampleNativePluginClass *klazz)
{
}

/**
 * Export the types to the gobject type system
 */
G_MODULE_EXPORT void peas_register_types(PeasObjectModule *module)
{
        example_native_plugin_register_type(G_TYPE_MODULE(module));

        /* Register the actual dynamic types contained in the resulting plugin */
        example_native_applet_init_gtype(G_TYPE_MODULE(module));

        peas_object_module_register_extension_type(module,
                                                   BUDGIE_TYPE_PLUGIN,
                                                   EXAMPLE_TYPE_NATIVE_PLUGIN);
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
