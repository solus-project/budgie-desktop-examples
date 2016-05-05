plugindir = $(libdir)/budgie-desktop/plugins

valaappletdir = $(plugindir)/vala-example

valaapplet_LTLIBRARIES = \
	libvalaexampleapplet.la

libvalaexampleapplet_la_SOURCES = \
	ValaApplet.vala

libvalaexampleapplet_la_CFLAGS = \
	$(BUDGIE_PLUGIN_CFLAGS)

libvalaexampleapplet_la_LIBADD = \
	$(BUDGIE_PLUGIN_LIBS)

libvalaexampleapplet_la_LDFLAGS = \
	-module \
	-avoid-version \
	-shared \
	$(AM_LDFLAGS)

libvalaexampleapplet_la_VALAFLAGS = \
	--pkg budgie-1.0 \
	--pkg gtk+-3.0 \
	--pkg gio-unix-2.0 \
	--pkg libpeas-1.0

valaapplet_DATA = \
	ValaApplet.plugin

EXTRA_DIST = \
	ValaApplet.plugin
