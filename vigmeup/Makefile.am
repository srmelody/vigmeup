####### kdevelop will overwrite this part!!! (begin)##########
CXXFLAGS = -O0 -g1 -Wall 
LDFLAGS = 
vigmeup_SOURCES = vigmeup.cpp main.cpp vigmeup.h
vigmeup_LDADD   = -lkfile -lkfm -lkdeui -lkdecore -lqt -lXext -lX11 $(LIBSOCKET)

%.moc.cpp : %.h
	$(MOC) $< -o $@

SUBDIRS = docs 

EXTRA_DIST = main.cpp vigmeup.cpp vigmeup.h resource.h vigmeup.kdelnk vigmeup.xpm mini-vigmeup.xpm 

install-data-local:
	$(mkinstalldirs) $(kde_appsdir)/Applications/
	$(INSTALL_DATA) vigmeup.kdelnk $(kde_appsdir)/Applications/vigmeup.kdelnk
	$(mkinstalldirs) $(kde_icondir)/
	$(INSTALL_DATA) vigmeup.xpm $(kde_icondir)/vigmeup.xpm
	$(mkinstalldirs) $(kde_minidir)/
	$(INSTALL_DATA) mini-vigmeup.xpm $(kde_minidir)/vigmeup.xpm

uninstall-local:
	-rm -f $(kde_appsdir)/Applications/vigmeup.kdelnk
	-rm -f $(kde_icondir)/vigmeup.xpm
	-rm -f $(kde_minidir)/vigmeup.xpm

####### kdevelop will overwrite this part!!! (end)############
# this 10 paths are KDE specific. Use them:
# kde_htmldir       Where your docs should go to. (contains lang subdirs)
# kde_appsdir       Where your application file (.kdelnk) should go to. 
# kde_icondir       Where your icon should go to.
# kde_minidir       Where your mini icon should go to.
# kde_datadir       Where you install application data. (Use a subdir)
# kde_locale        Where translation files should go to.(contains lang subdirs)
# kde_cgidir        Where cgi-bin executables should go to.
# kde_confdir       Where config files should go to.
# kde_mimedir       Where mimetypes should go to.
# kde_toolbardir    Where general toolbar icons should go to.
# kde_wallpaperdir  Where general wallpapers should go to.

# set the include path for X, qt and KDE
INCLUDES= $(all_includes)
# claim, which subdirectories you want to install
# you can add here more. This one gets installed 
bin_PROGRAMS = vigmeup 

vigmeup_METASOURCES = vigmeup.moc.cpp vigmeup.moc.o #USE_AUTOMOC 

# the library search path. 
vigmeup_LDFLAGS = $(all_libraries) $(KDE_RPATH)

# them while "make clean", use CLEANFILES
DISTCLEANFILES = $(vigmeup_METASOURCES)

# make messages.po. Move this one to ../po/ and "make merge" in po
# the -x is for skipping messages already translated in kdelibs
messages:
	$(XGETTEXT) -C -ki18n -x $(includedir)/kde.pot $(vigmeup_SOURCES) && mv messages.po ../po/vigmeup.pot






