#!/bin/bash

# Script de instalacion de Qapital
# Autor: CetiSoft
# Version: 0.0.1

# TODO: * Si QTDIR no esta asignada, probar automaticamente con /usr/qt/3 y con /usr/lib/qt/
#	* Definir el PATH de instalacion.
#	* Definir el PATH de datos y copiar los datos a el.
#	* Hacer una pequeña interfaz grafica de instalacion.

# Esta version es unicamente para desarrolladores.

# Look & feel

GREEN='\033[1;32m'
RED='\033[9;31m'
NULLC='\033[0;0m'

function qpinfo ()
{
	echo -e $GREEN '*' $NULLC $1
}

function qperror ()
{
	echo -e $RED '*' $NULLC $1
}

function qpelec ()
{
	echo -e $RED $1 $NULLC $2
}

# elaf
PSQL=psql

DIRS=`find . -type d`
DIRS="$DIRS"

qpinfo "Actualizando directorios"
for i in $DIRS
do
	cd $i
	if [ -e *.pro ]
	then
		qpinfo "Actualizando $i"
		qmake 2> /dev/null >/dev/null
	fi
	cd -
done

#if [ ! $QTDIR ]
#then
#	qperror "Por favor asigne la variable de entorno QTDIR."
#	exit -1
#fi

qmake

qpinfo "Compilando QPack..."

make || exit 1

qpinfo "Compilacion exitosa!"

