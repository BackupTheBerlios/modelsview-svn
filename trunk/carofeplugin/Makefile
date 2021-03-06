#############################################################################
# Makefile for building: libcarofe.so.0.1.0
# Generated by qmake (1.07a) (Qt 3.3.1) on: Wed May 25 23:13:04 2005
# Project:  carofeplugin.pro
# Template: lib
# Command: $(QMAKE) -o Makefile carofeplugin.pro
#############################################################################

####### Compiler, tools and options

CC       = gcc
CXX      = g++
LEX      = flex
YACC     = yacc
CFLAGS   = -pipe -O2 -march=i586 -mcpu=i686 -fmessage-length=0 -Wall -fPIC -Wall -W -g -D_REENTRANT -fPIC  -DMYDEBUG -DQT_THREAD_SUPPORT -DQT_SHARED -DQT_TABLET_SUPPORT -DQT_NO_DEBUG
CXXFLAGS = -pipe -O2 -march=i586 -mcpu=i686 -fmessage-length=0 -Wall -fPIC -Wall -W -g -D_REENTRANT -fPIC  -DMYDEBUG -DQT_THREAD_SUPPORT -DQT_SHARED -DQT_TABLET_SUPPORT -DQT_NO_DEBUG
LEXFLAGS = 
YACCFLAGS= -d
INCPATH  = -I/usr/lib/qt3/mkspecs/default -I. -I. -I/usr/include -I$(QTDIR)/include -I/usr/include -I/usr/X11R6/include
LINK     = g++
LFLAGS   = -shared -Wl,-soname,libcarofe.so.0
LIBS     = $(SUBLIBS) -L/usr/lib/ -L$(QTDIR)/lib/ -L/usr/lib/ -L/usr/X11R6/lib/ -lqt-mt -lGLU -lGL -lXmu -lXext -lX11 -lm -lpthread
AR       = ar cqs
RANLIB   = 
MOC      = $(QTDIR)/bin/moc
UIC      = $(QTDIR)/bin/uic
QMAKE    = qmake
TAR      = tar -cf
GZIP     = gzip -9f
COPY     = cp -f
COPY_FILE= $(COPY)
COPY_DIR = $(COPY) -r
INSTALL_FILE= $(COPY_FILE)
INSTALL_DIR = $(COPY_DIR)
DEL_FILE = rm -f
SYMLINK  = ln -sf
DEL_DIR  = rmdir
MOVE     = mv -f
CHK_DIR_EXISTS= test -d
MKDIR    = mkdir -p

####### Output directory

OBJECTS_DIR = ./

####### Files

HEADERS = modelsviewplugin.h \
		mvglwidget.h \
		carofeplugin.h \
		ascview.h \
		asc.h \
		dsview.h \
		3ds.hpp
SOURCES = mvglwidget.cpp \
		carofeplugin.cpp \
		ascview.cpp \
		asc.cpp \
		dsview.cpp \
		3ds.cpp
OBJECTS = mvglwidget.o \
		carofeplugin.o \
		ascview.o \
		asc.o \
		dsview.o \
		3ds.o
FORMS = 
UICDECLS = 
UICIMPLS = 
SRCMOC   = 
OBJMOC = 
DIST	   = carofeplugin.pro
QMAKE_TARGET = carofe
DESTDIR  = ../plugins/
TARGET   = libcarofe.so.0.1.0
TARGETA	= ../plugins/libcarofe.a
TARGETD	= libcarofe.so.0.1.0
TARGET0	= libcarofe.so
TARGET1	= libcarofe.so.0
TARGET2	= libcarofe.so.0.1

first: all
####### Implicit rules

.SUFFIXES: .c .o .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o $@ $<

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o $@ $<

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o $@ $<

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o $@ $<

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o $@ $<

####### Build rules

all: Makefile  ../plugins/$(TARGET)

../plugins/$(TARGET):  $(UICDECLS) $(OBJECTS) $(OBJMOC) $(SUBLIBS) $(OBJCOMP)  
	test -d ../plugins/ || mkdir -p ../plugins/
	-$(DEL_FILE) $(TARGET) $(TARGET0) $(TARGET1) $(TARGET2)
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJMOC) $(LIBS) $(OBJCOMP)
	-ln -s $(TARGET) $(TARGET0)
	-ln -s $(TARGET) $(TARGET1)
	-ln -s $(TARGET) $(TARGET2)
	-$(DEL_FILE) ../plugins/$(TARGET)
	-$(DEL_FILE) ../plugins/$(TARGET0)
	-$(DEL_FILE) ../plugins/$(TARGET1)
	-$(DEL_FILE) ../plugins/$(TARGET2)
	-$(MOVE) $(TARGET) $(TARGET0) $(TARGET1) $(TARGET2) ../plugins/



staticlib: $(TARGETA)

$(TARGETA):  $(UICDECLS) $(OBJECTS) $(OBJMOC) $(OBJCOMP)
	-$(DEL_FILE) $(TARGETA) 
	$(AR) $(TARGETA) $(OBJECTS) $(OBJMOC)

mocables: $(SRCMOC)
uicables: $(UICDECLS) $(UICIMPLS)

$(MOC): 
	( cd $(QTDIR)/src/moc && $(MAKE) )

Makefile: carofeplugin.pro  /usr/lib/qt3/mkspecs/default/qmake.conf /usr/lib/qt3/lib/libqt-mt.prl
	$(QMAKE) -o Makefile carofeplugin.pro
qmake: 
	@$(QMAKE) -o Makefile carofeplugin.pro

dist: 
	@mkdir -p .tmp/carofe && $(COPY_FILE) --parents $(SOURCES) $(HEADERS) $(FORMS) $(DIST) .tmp/carofe/ && ( cd `dirname .tmp/carofe` && $(TAR) carofe.tar carofe && $(GZIP) carofe.tar ) && $(MOVE) `dirname .tmp/carofe`/carofe.tar.gz . && $(DEL_FILE) -r .tmp/carofe

mocclean:

uiclean:

yaccclean:
lexclean:
clean:
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) ../plugins/$(TARGET) $(TARGET)
	-$(DEL_FILE) ../plugins/$(TARGET0) ../plugins/$(TARGET1) ../plugins/$(TARGET2) $(TARGETA)


FORCE:

####### Compile

mvglwidget.o: mvglwidget.cpp mvglwidget.h

carofeplugin.o: carofeplugin.cpp carofeplugin.h \
		modelsviewplugin.h \
		ascview.h \
		dsview.h \
		mvglwidget.h \
		asc.h \
		3ds.hpp

ascview.o: ascview.cpp ascview.h \
		asc.h \
		mvglwidget.h

asc.o: asc.cpp asc.h

dsview.o: dsview.cpp dsview.h \
		mvglwidget.h \
		3ds.hpp

3ds.o: 3ds.cpp 3ds.hpp

####### Install

install:  

uninstall:  

