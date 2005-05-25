# Archivo generado por el gestor qmake de kdevelop. 
# ------------------------------------------- 
# Subdirectorio relativo al directorio principal del proyecto: ./carofeplugin
# Destiono es una biblioteca:  carofe

TEMPLATE = lib
TARGET = carofe
VERSION = 0.1.0
DESTDIR = ../plugins/
INCLUDEPATH += .
CONFIG+= qt thread opengl warn_on dll debug
SOURCES += mvglwidget.cpp \
           carofeplugin.cpp \
           ascview.cpp \
           asc.cpp \
           dsview.cpp \
           3ds.cpp 
HEADERS += modelsviewplugin.h \
           mvglwidget.h \
           carofeplugin.h \
           ascview.h \
           asc.h \
           dsview.h \
           3ds.hpp 
debug{
 DEFINES += MYDEBUG
}
