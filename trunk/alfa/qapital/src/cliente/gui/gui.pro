# File generated by kdevelop's qmake manager. 
# ------------------------------------------- 
# Subdir relative project main directory: ./src/cliente/gui
# Target is a subdirs project 

TARGETDEPS += ../../../src/cliente/logica/liblogica.a \
              ../../../src/cliente/red/libred.a \
              ../../../src/sbase/sbbd/libsbbd.a \
              ../../../src/sbase/sbxml/libsbxml.a \
              ../../../src/sbase/sbred/libsbred.a \
              ../../../src/sbase/sbgui/libsbgui.a \
              ../../../src/sbase/sbqapital/libsbqapital.a 
LIBS += ../../../src/cliente/logica/liblogica.a \
        ../../../src/cliente/red/libred.a \
        ../../../src/sbase/sbbd/libsbbd.a \
        ../../../src/sbase/sbxml/libsbxml.a \
        ../../../src/sbase/sbred/libsbred.a \
        ../../../src/sbase/sbgui/libsbgui.a \
        ../../../src/sbase/sbqapital/libsbqapital.a 
CONFIG += release \
          warn_on 
TEMPLATE = subdirs 
SUBDIRS += mdibased \
           menubased 
