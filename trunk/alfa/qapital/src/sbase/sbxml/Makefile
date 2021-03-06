#############################################################################
# Makefile for building: libsbxml.a
# Generated by qmake (1.07a) (Qt 3.3.3) on: Sat Feb 19 18:54:41 2005
# Project:  sbxml.pro
# Template: lib
# Command: $(QMAKE) -o Makefile sbxml.pro
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
INCPATH  = -I/usr/qt/3/mkspecs/linux-g++ -I. -I../../../src/sbase/sbqapital -I$(QTDIR)/include -I.moc/
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

HEADERS = sbxmlinterprete.h \
		sbxmlerror.h \
		sbxml.h \
		qpdocumentoxml.h \
		sbxmlcnx.h \
		sbxmlconfig.h \
		sbxmlacp.h \
		sbxmlquery.h \
		sbxmlmessage.h \
		sbxmlsuccess.h \
		sbxmlupdatecode.h \
		sbxmlanswer.h
SOURCES = sbxmlinterprete.cpp \
		sbxmlerror.cpp \
		qpdocumentoxml.cpp \
		sbxmlcnx.cpp \
		sbxmlconfig.cpp \
		sbxmlacp.cpp \
		sbxmlquery.cpp \
		sbxmlmessage.cpp \
		sbxmlsuccess.cpp \
		sbxmlupdatecode.cpp \
		sbxmlanswer.cpp
OBJECTS = .obj/sbxmlinterprete.o \
		.obj/sbxmlerror.o \
		.obj/qpdocumentoxml.o \
		.obj/sbxmlcnx.o \
		.obj/sbxmlconfig.o \
		.obj/sbxmlacp.o \
		.obj/sbxmlquery.o \
		.obj/sbxmlmessage.o \
		.obj/sbxmlsuccess.o \
		.obj/sbxmlupdatecode.o \
		.obj/sbxmlanswer.o
FORMS = 
UICDECLS = 
UICIMPLS = 
SRCMOC   = 
OBJMOC = 
DIST	   = sbxml.pro
QMAKE_TARGET = sbxml
DESTDIR  = 
TARGET   = libsbxml.a

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

$(TARGET):  $(UICDECLS) $(OBJECTS) $(OBJMOC) $(OBJCOMP) ../../../src/sbase/sbqapital/libsbqapital.a
	-$(DEL_FILE) $(TARGET)
	$(AR) $(TARGET) $(OBJECTS) $(OBJMOC)


mocables: $(SRCMOC)
uicables: $(UICDECLS) $(UICIMPLS)

$(MOC): 
	( cd $(QTDIR)/src/moc && $(MAKE) )

Makefile: sbxml.pro  /usr/qt/3/mkspecs/linux-g++/qmake.conf 
	$(QMAKE) -o Makefile sbxml.pro
qmake: 
	@$(QMAKE) -o Makefile sbxml.pro

dist: 
	@mkdir -p .obj/sbxml && $(COPY_FILE) --parents $(SOURCES) $(HEADERS) $(FORMS) $(DIST) .obj/sbxml/ && ( cd `dirname .obj/sbxml` && $(TAR) sbxml.tar sbxml && $(GZIP) sbxml.tar ) && $(MOVE) `dirname .obj/sbxml`/sbxml.tar.gz . && $(DEL_FILE) -r .obj/sbxml

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

.obj/sbxmlinterprete.o: sbxmlinterprete.cpp sbxmlinterprete.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/sbxmlinterprete.o sbxmlinterprete.cpp

.obj/sbxmlerror.o: sbxmlerror.cpp sbxmlerror.h \
		qpdocumentoxml.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/sbxmlerror.o sbxmlerror.cpp

.obj/qpdocumentoxml.o: qpdocumentoxml.cpp qpdocumentoxml.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/qpdocumentoxml.o qpdocumentoxml.cpp

.obj/sbxmlcnx.o: sbxmlcnx.cpp sbxmlcnx.h \
		qpdocumentoxml.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/sbxmlcnx.o sbxmlcnx.cpp

.obj/sbxmlconfig.o: sbxmlconfig.cpp sbxmlconfig.h \
		qpdocumentoxml.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/sbxmlconfig.o sbxmlconfig.cpp

.obj/sbxmlacp.o: sbxmlacp.cpp sbxmlacp.h \
		qpdocumentoxml.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/sbxmlacp.o sbxmlacp.cpp

.obj/sbxmlquery.o: sbxmlquery.cpp sbxmlquery.h \
		qpdocumentoxml.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/sbxmlquery.o sbxmlquery.cpp

.obj/sbxmlmessage.o: sbxmlmessage.cpp sbxmlmessage.h \
		qpdocumentoxml.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/sbxmlmessage.o sbxmlmessage.cpp

.obj/sbxmlsuccess.o: sbxmlsuccess.cpp sbxmlsuccess.h \
		qpdocumentoxml.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/sbxmlsuccess.o sbxmlsuccess.cpp

.obj/sbxmlupdatecode.o: sbxmlupdatecode.cpp sbxmlupdatecode.h \
		qpdocumentoxml.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/sbxmlupdatecode.o sbxmlupdatecode.cpp

.obj/sbxmlanswer.o: sbxmlanswer.cpp sbxmlanswer.h \
		qpdocumentoxml.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/sbxmlanswer.o sbxmlanswer.cpp

####### Install

install:  

uninstall:  

