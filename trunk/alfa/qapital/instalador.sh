#!/bin/bash

DIALOG=`which kdialog`
ACTUAL=$(pwd)

function die()
{
	$DIALOG --error "<h3>Error Faltal</h3> Ha ocurrido un error: $1"
}

if [ -x $DIALOG ]
then
	$DIALOG --msgbox "<h3>QApital</h3>Espere un momento miembras se construye el instalador..." &
fi

for i in $(find src -type d)
do
        cd $i
	        if [ -e Makefile ]
		then
			qmake 2> /dev/null >/dev/null
		fi
	cd -
done

cd qpinstalador
qmake -makefile
make || die "No se pudo compilar"

#mv qpinstalador ../installer

cd $ACTUAL
./installer || die "No se pudo ejecutar"
rm installer
