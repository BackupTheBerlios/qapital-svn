# File generated by kdevelop's qmake manager. 
# ------------------------------------------- 
# Subdir relative project main directory: ./src/servidor/bd
# Target is a library:  

TARGETDEPS += ../../../src/sbase/sbqapital/libsbqapital.a \
              ../../../src/sbase/sbxml/libsbxml.a \
              ../../../src/sbase/sbcontrol/libsbcontrol.a \
              ../../../src/sbase/sblogica/libsblogica.a \
              ../../../src/sbase/sbred/libsbred.a \
              ../../../src/sbase/sbbd/libsbbd.a 
LIBS += ../../../src/sbase/sbqapital/libsbqapital.a \
        ../../../src/sbase/sbxml/libsbxml.a \
        ../../../src/sbase/sbcontrol/libsbcontrol.a \
        ../../../src/sbase/sblogica/libsblogica.a \
        ../../../src/sbase/sbred/libsbred.a \
        ../../../src/sbase/sbbd/libsbbd.a 
INCLUDEPATH = ../../../src/sbase/sbbd \
              ../../../src/sbase/sbxml \
              ../../../src/sbase/sbcontrol \
              ../../../src/sbase/sblogica \
              ../../../src/sbase/sbred \
              ../../../src/sbase/sbqapital 
MOC_DIR = .moc 
OBJECTS_DIR = .obj 
CONFIG += release \
          warn_on \
          staticlib 
TEMPLATE = lib 
HEADERS += bdinstrucciones.h 
SOURCES += bdinstrucciones.cpp 
