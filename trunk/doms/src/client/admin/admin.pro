# File generated by kdevelop's qmake manager. 
# ------------------------------------------- 
# Subdir relative project main directory: ./src/client/admin
# Target is an application:  ../../../bin/domsadmin.bin

HEADERS += amainwindow.h \
           aapplication.h \
           aconnector.h \
           apackageparser.h 
SOURCES += main_admin.cpp \
           amainwindow.cpp \
           aapplication.cpp \
           aconnector.cpp \
           apackageparser.cpp 
QT += xml network 
KDEV_QTVER = 4 
TARGETDEPS += ../../../src/client/lib/libdclient.a \
              ../../../src/dlib/dgui/libdgui.so \
              ../../../src/dlib/dcore/libdcore.so \
              ../../../src/client/modules/help/libhelp.a \
              ../../../src/client/packages/libpackages.a 
LIBS += ../../../src/client/modules/help/libhelp.a \
        ../../../src/client/lib/libdclient.a \
        -ldgui \
        -ldcore \
        ../../../src/client/packages/libpackages.a 
INCLUDEPATH += ../../../src/client/shell \
               ../../../src/client/modules/help \
               ../../../src/client/packages \
               ../../../src/client/lib \
               ../../../src/dlib/dgui \
               ../../../src/dlib/dcore 
MOC_DIR = .moc 
UI_DIR = .ui 
OBJECTS_DIR = .obj 
QMAKE_LIBDIR = ../../../src/dlib/dgui \
               ../../../src/dlib/dcore 
TARGET = ../../../bin/domsadmin.bin 
CONFIG += release \
          warn_on 
TEMPLATE = app 