#!/bin/bash

DIALOG=`which kdialog`
ACTUAL=$(pwd)
SERVIDOR=$(pwd)/src/servidor/qpserver/
CLIENTE=$(pwd)/src/cliente/qpcliente/


function die()
{
	$DIALOG --error "<h3>Error Faltal</h3> Ha ocurrido un error: $1"
}

function testKDE()
{
	kdialog -v 2>/dev/null >/dev/null
	
	if [ $? != 0 ]
	then
		echo "Necesita kdialog para utilizar este script"
		exit -1
	fi
}

function fixMakefiles()
{
	for i in $(find src -type d)
	do
	        cd $i
		        if [ -e Makefile ]
			then
				qmake 2> /dev/null >/dev/null
			fi
		cd -
	done
}

function compilar()
{
	cd $ACTUAL
	make || die "No se pudo compilar"
}

function ejecutarServer()
{
	echo $SERVIDOR
	if [ -d $SERVIDOR ]
	then
		cd $SERVIDOR	
		if [ -x ./qpserver ]
		then
			./qpserver || die "Error ejecutando servidor" &
		fi
		cd -
	fi
}

function ejecutarCliente()
{
	if [ -d $CLIENTE ]
	then
		cd $CLIENTE
		if [ -x ./qpcliente ]
		then
			./qpcliente || die "Error ejecutando cliente" &
		fi
		cd -
	fi
}

function bye()
{
	killall qpserver 2>/dev/null > /dev/null
	killall qpcliente 2> /dev/null > /dev/null
}


testKDE
while [ true ]
do
	case `$DIALOG --title "Compilar Qapital " --menu "Que desea hacer?" 1 "Compilar qapital" 2 "Ejecutar servidor" 3 "Ejecutar cliente" quit "Salir"` in
		1) 
		fixMakefiles
		compilar	
		;;
		2) ejecutarServer 
		;;
		3) ejecutarCliente
		;;
		quit) break
		;;
		"") break
		;;
	esac
done


bye

