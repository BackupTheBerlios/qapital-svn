# File generated by kdevelop's qmake manager. 
# ------------------------------------------- 
# Subdir relative project main directory: ./src/client/packages
# Target is a library:  

QT += xml 
KDEV_QTVER = 4 
INCLUDEPATH += ../../../src/dlib/dgui \
               ../../../src/dlib/dcore \
               ../../dlib/ 
MOC_DIR = .moc 
UI_DIR = .ui 
OBJECTS_DIR = .obj 
CONFIG += release \
          warn_on \
          staticlib 
TEMPLATE = lib 
HEADERS += cconnectpackage.h \
           cchatpackage.h \
           cselectpackage.h \
           cupdatepackage.h \
           cinsertpackage.h \
           cdeletepackage.h \
           csqlpackagebase.h 
SOURCES += cconnectpackage.cpp \
           cchatpackage.cpp \
           cselectpackage.cpp \
           cupdatepackage.cpp \
           cinsertpackage.cpp \
           cdeletepackage.cpp \
           csqlpackagebase.cpp 
