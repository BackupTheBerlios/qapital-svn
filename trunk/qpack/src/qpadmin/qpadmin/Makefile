#############################################################################
# Makefile for building: qpadmin
# Generated by qmake (1.07a) (Qt 3.3.3) on: Sun Feb 27 12:52:42 2005
# Project:  qpadmin.pro
# Template: app
# Command: $(QMAKE) -o Makefile qpadmin.pro
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
INCPATH  = -I/usr/qt/3/mkspecs/linux-g++ -I. -I../../../src/qpadmin/qpalogica -I../../../src/qpadmin/qpagui -I../../../src/qpadmin/qpared -I../../../sbase/sbqpack -I../../../sbase/sbgui -I../../../sbase/sbxml -I../../../sbase/sbred -I../../../sbase/sblogica -I../../../sbase/sbcontrol -I../../../sbase/sbbd -I$(QTDIR)/include -I.moc/
LINK     = g++
LFLAGS   =  -Wl,-rpath,$(QTDIR)/lib
LIBS     = $(SUBLIBS) -L$(QTDIR)/lib -L/usr/X11R6/lib ../../../src/qpadmin/qpared/libqpared.a ../../../src/qpadmin/qpalogica/libqpalogica.a ../../../src/qpadmin/qpagui/libqpagui.a ../../../sbase/sbqpack/libsbqpack.a ../../../sbase/sbgui/libsbgui.a ../../../sbase/sbxml/libsbxml.a ../../../sbase/sbred/libsbred.a ../../../sbase/sblogica/libsblogica.a ../../../sbase/sbcontrol/libsbcontrol.a ../../../sbase/sbbd/libsbbd.a -lqt -lXext -lX11 -lm
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

HEADERS = 
SOURCES = qpadmin.cpp
OBJECTS = .obj/qpadmin.o
FORMS = 
UICDECLS = 
UICIMPLS = 
SRCMOC   = 
OBJMOC = 
DIST	   = qpadmin.pro
QMAKE_TARGET = qpadmin
DESTDIR  = 
TARGET   = qpadmin

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

$(TARGET):  $(UICDECLS) $(OBJECTS) $(OBJMOC)  ../../../src/qpadmin/qpared/libqpared.a ../../../src/qpadmin/qpalogica/libqpalogica.a ../../../src/qpadmin/qpagui/libqpagui.a ../../../sbase/sbqpack/libsbqpack.a ../../../sbase/sbgui/libsbgui.a ../../../sbase/sbxml/libsbxml.a ../../../sbase/sbred/libsbred.a ../../../sbase/sblogica/libsblogica.a ../../../sbase/sbcontrol/libsbcontrol.a ../../../sbase/sbbd/libsbbd.a
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJMOC) $(OBJCOMP) $(LIBS)

mocables: $(SRCMOC)
uicables: $(UICDECLS) $(UICIMPLS)

$(MOC): 
	( cd $(QTDIR)/src/moc && $(MAKE) )

Makefile: qpadmin.pro  /usr/qt/3/mkspecs/linux-g++/qmake.conf 
	$(QMAKE) -o Makefile qpadmin.pro
qmake: 
	@$(QMAKE) -o Makefile qpadmin.pro

dist: 
	@mkdir -p .obj/qpadmin && $(COPY_FILE) --parents $(SOURCES) $(HEADERS) $(FORMS) $(DIST) .obj/qpadmin/ && ( cd `dirname .obj/qpadmin` && $(TAR) qpadmin.tar qpadmin && $(GZIP) qpadmin.tar ) && $(MOVE) `dirname .obj/qpadmin`/qpadmin.tar.gz . && $(DEL_FILE) -r .obj/qpadmin

mocclean:

uiclean:

yaccclean:
lexclean:
clean:
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) $(TARGET)


FORCE:

####### Compile

.obj/qpadmin.o: qpadmin.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/qpadmin.o qpadmin.cpp

####### Install

install:  

uninstall:  

