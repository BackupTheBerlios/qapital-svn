# File generated by kdevelop's qmake manager. 
# ------------------------------------------- 
# Subdir relative project main directory: ./src/qpserver
# Target is an application:  

TARGETDEPS += ../../src/qpsbd/libqpsbd.a \
              ../../src/qpsred/libqpsred.a \
              ../../sbase/sbqpserver/libsbqpserver.a \
              ../../sbase/sbred/libsbred.a \
              ../../sbase/sbxml/libsbxml.a \
              ../../sbase/sblogica/libsblogica.a \
              ../../sbase/sbcontrol/libsbcontrol.a \
              ../../sbase/sbbd/libsbbd.a \
              ../../src/qpscontrol/libqpscontrol.a \
              ../../src/qpslogica/libqpslogica.a 
LIBS += ../../src/qpsred/libqpsred.a \
        ../../src/qpsbd/libqpsbd.a \
        ../../sbase/sbqpserver/libsbqpserver.a \
        ../../sbase/sbred/libsbred.a \
        ../../sbase/sbxml/libsbxml.a \
        ../../sbase/sblogica/libsblogica.a \
        ../../sbase/sbcontrol/libsbcontrol.a \
        ../../sbase/sbbd/libsbbd.a \
        ../../src/qpscontrol/libqpscontrol.a \
        ../../src/qpslogica/libqpslogica.a 
INCLUDEPATH = ../../src/qpscontrol \
              ../../src/qpslogica \
              ../../src/qpsbd \
              ../../src/qpsred \
              ../../sbase/sbqpserver \
              ../../sbase/sbred \
              ../../sbase/sbxml \
              ../../sbase/sblogica \
              ../../sbase/sbcontrol \
              ../../sbase/sbbd 
MOC_DIR = .moc 
OBJECTS_DIR = .obj 
CONFIG += release \
          warn_on 
TEMPLATE = app 
HEADERS += qpsconfighandler.h 
SOURCES += qpsconfighandler.cpp \
           qpserver.cpp 
