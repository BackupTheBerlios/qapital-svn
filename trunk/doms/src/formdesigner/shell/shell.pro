# File generated by kdevelop's qmake manager. 
# ------------------------------------------- 
# Subdir relative project main directory: ./src/formdesigner/shell
# Target is an application:  ../../../bin/dformcreator.bin

RESOURCES += icons.qrc 
QT += xml svg 
INSTALLS += target 
target.path = /bin/ 
KDEV_QTVER = 4 
TARGETDEPS += ../../../src/client/lib/libdclient.a \
              ../../../src/dlib/dgui/libdgui.so \
              ../../../src/dlib/dcore/libdcore.so 
LIBS += ../../../src/client/lib/libdclient.a \
        -ldgui \
        -ldcore 
INCLUDEPATH += ../../../src/client/lib \
               ../../../src/dlib/dgui \
               ../../../src/dlib/dcore 
QMAKE_LIBDIR = ../../../src/dlib/dgui \
               ../../../src/dlib/dcore 
TARGET = ../../../bin/dformcreator.bin 
CONFIG += release \
          warn_on 
TEMPLATE = app 
HEADERS += fdesigner.h \
           ftoolmanager.h 
SOURCES += formcreator_main.cpp \
           fdesigner.cpp \
           ftoolmanager.cpp 
