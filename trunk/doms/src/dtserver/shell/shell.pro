# File generated by kdevelop's qmake manager. 
# ------------------------------------------- 
# Subdir relative project main directory: ./src/dtserver/shell
# Target is an application:  ../../../bin/domserver.bin

INSTALLS += target 
target.path = /bin/ 
HEADERS += spackageparser.h \
           dtserver.h \
           dtserverclient.h \
           dtserverconnection.h \
           dtsglobal.h \
           sdatabase.h \
           dtquery.h \
           postgreserrorhandler.h 
SOURCES += server_main.cpp \
           spackageparser.cpp \
           dtserver.cpp \
           dtserverclient.cpp \
           dtserverconnection.cpp \
           sdatabase.cpp \
           dtquery.cpp \
           postgreserrorhandler.cpp 
QT += network xml sql
KDEV_QTVER = 4
TARGETDEPS += ../../../src/dtserver/packages/libpackages.a
LIBS += -ldcore \
../../../src/dtserver/packages/libpackages.a
INCLUDEPATH += ../../../src/dtserver/packages \
../../../src/dlib/dgui \
../../../src/dlib/dcore
MOC_DIR = .moc
UI_DIR = .ui
OBJECTS_DIR = .obj
QMAKE_LIBDIR = ../../../src/dlib/dcore
TARGET = ../../../bin/domserver.bin
CONFIG += release \
warn_on
TEMPLATE = app
