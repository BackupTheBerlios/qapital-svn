# Archivo generado por el gestor qmake de kdevelop. 
# ------------------------------------------- 
# Subdirectorio relativo al directorio principal del proyecto: ./src/qpadmin/qpagui
# Destiono es una biblioteca:  

TARGETDEPS += ../../../sbase/sbqpack/libsbqpack.a \
              ../../../sbase/sbgui/libsbgui.a 
LIBS += ../../../sbase/sbqpack/libsbqpack.a \
        ../../../sbase/sbgui/libsbgui.a 
INCLUDEPATH = ../../../sbase/sbqpack \
              ../../../sbase/sbgui \
              ../../../sbase/sbxml \
              ../../../sbase/sbred \
              ../../../sbase/sblogica \
              ../../../sbase/sbcontrol \
              ../../../sbase/sbbd 
CONFIG += release \
          warn_on \
          staticlib 
TEMPLATE = lib 
HEADERS += gadconsola.h \
           gadmainwindow.h \
           gadpaneldeherramientas.h 
SOURCES += gadconsola.cpp \
           gadmainwindow.cpp \
           gadpaneldeherramientas.cpp 
