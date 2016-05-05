include $(top_srcdir)/common.mk

plugindir = $(libdir)/budgie-desktop/plugins

nativeappletdir = $(plugindir)/native-example

nativeapplet_LTLIBRARIES = \
	libnativeexampleapplet.la

libnativeexampleapplet_la_SOURCES = \
	NativeApplet.c

libnativeexampleapplet_la_CFLAGS = \
	$(BUDGIE_PLUGIN_CFLAGS) \
	$(AM_CFLAGS)

libnativeexampleapplet_la_LIBADD = \
	$(BUDGIE_PLUGIN_LIBS)

libnativeexampleapplet_la_LDFLAGS = \
	-module \
	-avoid-version \
	-shared \
	$(AM_LDFLAGS)

nativeapplet_DATA = \
	NativeApplet.plugin

EXTRA_DIST = \
	NativeApplet.plugin
