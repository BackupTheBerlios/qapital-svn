#!/bin/sh

QPDIR=$(pwd)/../
QPTS=qack_en.ts

cd $QPDIR/src/data/traducciones

echo -e "PREFIX =\n" > ./traducciones.pro
echo -e "ROOT =\n" >> ./traducciones.pro
echo -e "\n" >> ./traducciones.pro

CABECERAS=$(find $QPDIR  -name "*.h" -printf "%p ")
FUENTES=$(find $QPDIR -name "*.cpp" -printf "%p ")

echo "HEADERS = $TABLAS $CONSULTAS $CABECERAS $SCRIPTS" >> ./traducciones.pro
echo "SOURCES = $FUENTES" >> ./traducciones.pro

echo -e "TRANSLATIONS = $QPTS" >> ./traducciones.pro

lupdate -noobsolete ./traducciones.pro
rm -fR ./traducciones.pro

linguist $QPTS &

cd $QPDIR

