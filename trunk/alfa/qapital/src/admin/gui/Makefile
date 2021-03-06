#############################################################################
# Makefile for building: libgui.a
# Generated by qmake (1.07a) (Qt 3.3.3) on: Sat Feb 19 18:54:42 2005
# Project:  gui.pro
# Template: lib
# Command: $(QMAKE) -o Makefile gui.pro
#############################################################################

####### Compiler, tools and options

CC       = gcc
CXX      = g++
LEX      = flex
YACC     = yacc
CFLAGS   = -pipe -Wall -W -mcpu=athlon-xp -pipe -march=athlon-xp -O2  -DQT_NO_DEBUG
CXXFLAGS = -pipe -Wall -W -mcpu=athlon-xp -pipe -march=athlon-xp -O2  -DQT_NO_DEBUG
LEXFLAGS = 
YACCFLAGS= -d
INCPATH  = -I/usr/qt/3/mkspecs/linux-g++ -I. -I../../../src/sbase/sbbd -I../../../src/sbase/sbxml -I../../../src/sbase/sbcontrol -I../../../src/sbase/sblogica -I../../../src/sbase/sbred -I../../../src/sbase/sbgui -I../../../src/sbase/sbqapital -I$(QTDIR)/include -I.moc/
AR       = ar cqs
RANLIB   = 
MOC      = $(QTDIR)/bin/moc
UIC      = $(QTDIR)/bin/uic
QMAKE    = qmake
TAR      = tar -cf
GZIP     = gzip -9f
COPY     = cp -f
COPY_FILE= $(COPY)
COPY_DIR = $(COPY) -r
INSTALL_FILE= $(COPY_FILE)
INSTALL_DIR = $(COPY_DIR)
DEL_FILE = rm -f
SYMLINK  = ln -sf
DEL_DIR  = rmdir
MOVE     = mv -f
CHK_DIR_EXISTS= test -d
MKDIR    = mkdir -p

####### Output directory

OBJECTS_DIR = .obj/

####### Files

HEADERS = consola.h \
		gadmainwindow.h \
		paneldeherramientas.h
SOURCES = main.cpp \
		consola.cpp \
		gadmainwindow.cpp \
		paneldeherramientas.cpp
OBJECTS = .obj/main.o \
		.obj/consola.o \
		.obj/gadmainwindow.o \
		.obj/paneldeherramientas.o
FORMS = 
UICDECLS = 
UICIMPLS = 
SRCMOC   = .moc/moc_consola.cpp \
		.moc/moc_gadmainwindow.cpp \
		.moc/moc_paneldeherramientas.cpp
OBJMOC = .obj/moc_consola.o \
		.obj/moc_gadmainwindow.o \
		.obj/moc_paneldeherramientas.o
DIST	   = gui.pro
QMAKE_TARGET = gui
DESTDIR  = 
TARGET   = libgui.a

first: all
####### Implicit rules

.SUFFIXES: .c .o .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o $@ $<

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o $@ $<

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o $@ $<

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o $@ $<

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o $@ $<

####### Build rules

all: Makefile $(TARGET) 

staticlib: $(TARGET)

$(TARGET):  $(UICDECLS) $(OBJECTS) $(OBJMOC) $(OBJCOMP) ../../../src/sbase/sbxml/libsbxml.a ../../../src/sbase/sbcontrol/libsbcontrol.a ../../../src/sbase/sbgui/libsbgui.a ../../../src/sbase/sbqapital/libsbqapital.a
	-$(DEL_FILE) $(TARGET)
	$(AR) $(TARGET) $(OBJECTS) $(OBJMOC)


mocables: $(SRCMOC)
uicables: $(UICDECLS) $(UICIMPLS)

$(MOC): 
	( cd $(QTDIR)/src/moc && $(MAKE) )

Makefile: gui.pro  /usr/qt/3/mkspecs/linux-g++/qmake.conf 
	$(QMAKE) -o Makefile gui.pro
qmake: 
	@$(QMAKE) -o Makefile gui.pro

dist: 
	@mkdir -p .obj/gui && $(COPY_FILE) --parents $(SOURCES) $(HEADERS) $(FORMS) $(DIST) .obj/gui/ && ( cd `dirname .obj/gui` && $(TAR) gui.tar gui && $(GZIP) gui.tar ) && $(MOVE) `dirname .obj/gui`/gui.tar.gz . && $(DEL_FILE) -r .obj/gui

mocclean:
	-$(DEL_FILE) $(OBJMOC)
	-$(DEL_FILE) $(SRCMOC)

uiclean:

yaccclean:
lexclean:
clean: mocclean
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) $(TARGET)


FORCE:

####### Compile

.obj/main.o: main.cpp gadmainwindow.h \
		consola.h \
		paneldeherramientas.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/main.o main.cpp

.obj/consola.o: consola.cpp consola.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/consola.o consola.cpp

.obj/gadmainwindow.o: gadmainwindow.cpp gadmainwindow.h \
		consola.h \
		paneldeherramientas.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/gadmainwindow.o gadmainwindow.cpp

.obj/paneldeherramientas.o: paneldeherramientas.cpp paneldeherramientas.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/paneldeherramientas.o paneldeherramientas.cpp

.obj/moc_consola.o: .moc/moc_consola.cpp  consola.h 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/moc_consola.o .moc/moc_consola.cpp

.obj/moc_gadmainwindow.o: .moc/moc_gadmainwindow.cpp  gadmainwindow.h consola.h \
		paneldeherramientas.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/moc_gadmainwindow.o .moc/moc_gadmainwindow.cpp

.obj/moc_paneldeherramientas.o: .moc/moc_paneldeherramientas.cpp  paneldeherramientas.h 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/moc_paneldeherramientas.o .moc/moc_paneldeherramientas.cpp

.moc/moc_consola.cpp: $(MOC) consola.h
	$(MOC) consola.h -o .moc/moc_consola.cpp

.moc/moc_gadmainwindow.cpp: $(MOC) gadmainwindow.h
	$(MOC) gadmainwindow.h -o .moc/moc_gadmainwindow.cpp

.moc/moc_paneldeherramientas.cpp: $(MOC) paneldeherramientas.h
	$(MOC) paneldeherramientas.h -o .moc/moc_paneldeherramientas.cpp

####### Install

install:  

uninstall:  

