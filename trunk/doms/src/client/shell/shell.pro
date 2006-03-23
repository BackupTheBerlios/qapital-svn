# File generated by kdevelop's qmake manager. 
# ------------------------------------------- 
# Subdir relative project main directory: ./src/client/shell
# Target is an application:  ../../../bin/domsclient.bin

INSTALLS += data \
            target 
target.path = /bin/ 
data.files += data/es data/en 
data.path = /data/ 
HEADERS += cmainwindow.h \
           cconnectiondialog.h \
           cconnector.h \
           cpackageparser.h \
           cformmanager.h \
           capplication.h \
           cfirstrundialog.h \
           cchatwindow.h 
SOURCES += client_main.cpp \
           cmainwindow.cpp \
           cconnectiondialog.cpp \
           cconnector.cpp \
           cpackageparser.cpp \
           cformmanager.cpp \
           capplication.cpp \
           cfirstrundialog.cpp \
           cchatwindow.cpp 
QT += xml network
KDEV_QTVER = 4
TARGETDEPS += ../../../src/client/packages/libpackages.a \
../../../src/client/modules/clients/libclients.a \
../../../src/client/modules/help/libhelp.a \
../../../src/client/lib/libdclient.a
LIBS += -ldgui \
-ldcore \
../../../src/client/packages/libpackages.a \
../../../src/client/modules/clients/libclients.a \
../../../src/client/modules/help/libhelp.a \
../../../src/client/lib/libdclient.a
INCLUDEPATH += ../../../src/client/modules/help \
../../../src/client/modules/clients \
../../../src/client/packages \
../../../src/client/lib \
../../../src/dlib/dgui \
../../../src/dlib/dcore
MOC_DIR = .moc
UI_DIR = .ui
OBJECTS_DIR = .obj
QMAKE_LIBDIR = ../../../src/dlib/dgui \
../../../src/dlib/dcore
TARGET = ../../../bin/domsclient.bin
CONFIG += release \
warn_on
TEMPLATE = app
