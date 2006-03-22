# File generated by kdevelop's qmake manager. 
# ------------------------------------------- 
# Subdir relative project main directory: ./src/dtserver/shell
# Target is an application:  ../../../bin/domserver.bin

QT += network xml 
INSTALLS += target 
target.path = /bin/ 
KDEV_QTVER = 4 
TARGETDEPS += ../../../src/dartlib/dcore/libdcore.so \
              ../../../src/dtserver/packages/libpackages.a 
LIBS += -ldcore \
        ../../../src/dtserver/packages/libpackages.a 
INCLUDEPATH += ../../../src/dtserver/packages \
               ../../../src/dartlib/dcore 
MOC_DIR = .moc 
UI_DIR = .ui 
OBJECTS_DIR = .obj 
QMAKE_LIBDIR = ../../../src/dartlib/dcore 
TARGET = ../../../bin/domserver.bin 
CONFIG += release \
          warn_on 
TEMPLATE = app 
HEADERS += domserver.h \
           domserverconnection.h \
           domserverclient.h \
           spackageparser.h 
SOURCES += server_main.cpp \
           domserver.cpp \
           domserverconnection.cpp \
           domserverclient.cpp \
           spackageparser.cpp 
