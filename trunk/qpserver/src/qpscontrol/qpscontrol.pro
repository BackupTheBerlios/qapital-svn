# File generated by kdevelop's qmake manager. 
# ------------------------------------------- 
# Subdir relative project main directory: ./src/qpscontrol
# Target is a library:  

TARGETDEPS += ../../sbase/sbqpserver/libsbqpserver.a \
              ../../sbase/sbred/libsbred.a \
              ../../sbase/sbxml/libsbxml.a \
              ../../sbase/sblogica/libsblogica.a \
              ../../sbase/sbcontrol/libsbcontrol.a \
              ../../sbase/sbbd/libsbbd.a \
              ../../src/qpsbd/libqpsbd.a 
LIBS += ../../sbase/sbqpserver/libsbqpserver.a \
        ../../sbase/sbred/libsbred.a \
        ../../sbase/sbxml/libsbxml.a \
        ../../sbase/sblogica/libsblogica.a \
        ../../sbase/sbcontrol/libsbcontrol.a \
        ../../sbase/sbbd/libsbbd.a \
        ../../src/qpsbd/libqpsbd.a 
INCLUDEPATH = ../../src/qpsbd \
              ../../sbase/sbqpserver \
              ../../sbase/sbred \
              ../../sbase/sbxml \
              ../../sbase/sblogica \
              ../../sbase/sbcontrol \
              ../../sbase/sbbd 
MOC_DIR = .moc 
OBJECTS_DIR = .obj 
CONFIG += release \
          warn_on \
          staticlib 
TEMPLATE = lib 
HEADERS += qpscontrol.h \
           aceptarconexion.h 
SOURCES += aceptarconexion.cpp 
