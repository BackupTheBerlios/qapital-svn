# File generated by kdevelop's qmake manager. 
# ------------------------------------------- 
# Subdir relative project main directory: ./src/admin/gui
# Target is a library:  

HEADERS += consola.h \
           gadmainwindow.h \
           paneldeherramientas.h 
SOURCES += main.cpp \
           consola.cpp \
           gadmainwindow.cpp \
           paneldeherramientas.cpp 
TARGETDEPS += ../../../src/sbase/sbxml/libsbxml.a \
../../../src/sbase/sbcontrol/libsbcontrol.a \
../../../src/sbase/sbgui/libsbgui.a \
../../../src/sbase/sbqapital/libsbqapital.a
LIBS += ../../../src/sbase/sbxml/libsbxml.a \
../../../src/sbase/sbcontrol/libsbcontrol.a \
../../../src/sbase/sbgui/libsbgui.a \
../../../src/sbase/sbqapital/libsbqapital.a
INCLUDEPATH = ../../../src/sbase/sbbd \
../../../src/sbase/sbxml \
../../../src/sbase/sbcontrol \
../../../src/sbase/sblogica \
../../../src/sbase/sbred \
../../../src/sbase/sbgui \
../../../src/sbase/sbqapital
MOC_DIR = .moc
OBJECTS_DIR = .obj
CONFIG += release \
warn_on \
staticlib
TEMPLATE = lib
