# File generated by kdevelop's qmake manager. 
# ------------------------------------------- 
# Subdir relative project main directory: ./src/admin
# Target is a subdirs project 

TARGETDEPS += ../../src/sbase/sbqapital/libsbqapital.a \
              ../../src/sbase/sbxml/libsbxml.a \
              ../../src/sbase/sbcontrol/libsbcontrol.a \
              ../../src/sbase/sblogica/libsblogica.a \
              ../../src/sbase/sbred/libsbred.a \
              ../../src/sbase/sbgui/libsbgui.a \
              ../../src/sbase/sbbd/libsbbd.a 
LIBS += ../../src/sbase/sbqapital/libsbqapital.a \
        ../../src/sbase/sbxml/libsbxml.a \
        ../../src/sbase/sbcontrol/libsbcontrol.a \
        ../../src/sbase/sblogica/libsblogica.a \
        ../../src/sbase/sbred/libsbred.a \
        ../../src/sbase/sbgui/libsbgui.a \
        ../../src/sbase/sbbd/libsbbd.a 
INCLUDEPATH = red/ \
              logica/ \
              gui/ 
CONFIG += release \
          warn_on 
TEMPLATE = subdirs 
SUBDIRS += red \
           logica \
           gui \
           qpadmin 
