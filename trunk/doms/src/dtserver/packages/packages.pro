# File generated by kdevelop's qmake manager. 
# ------------------------------------------- 
# Subdir relative project main directory: ./src/dtserver/packages
# Target is a library:  

QT += xml 
KDEV_QTVER = 4 
INCLUDEPATH += ../../../src/dlib/dgui \
               ../../../src/dlib/dcore 
MOC_DIR = .moc 
UI_DIR = .ui 
OBJECTS_DIR = .obj 
CONFIG += release \
          warn_on \
          staticlib 
TEMPLATE = lib 
HEADERS += serrorpackage.h \
           ssuccesspackage.h \
           schatpackage.h 
SOURCES += serrorpackage.cpp \
           ssuccesspackage.cpp \
           schatpackage.cpp 
