#!/bin/bash
# Autor: CetiSoft
# Version: 0.0.1
# Descripcion:
# 	Este script sirve para crear la base de datos

LOGINADMIN=dcuadra
DBNAME=DBMidas2
DBDUMP=DBMidas.dump
PSQL=psql


if [ ! -x $PSQL ]
then
	if [ ! -x `which psql` ]
	then
		echo "Haga que psql este en su \$PATH"
		exit 0
	else
		PSQL=`which psql`	
	fi
fi

function mkdb()
{
	createuser -d -a $LOGINADMIN 
	createdb -U $LOGINADMIN $DBNAME || exit
	cat $DBDUMP | psql -U $LOGINADMIN $DBNAME
}

PGUSERS=`$PSQL -c "SELECT * from pg_user ;" | grep t |awk '{ print $1 }' | grep -v usename`

for USER in $PGUSERS
do
	if [ `whoami` == $USER ]
	then
		mkdb
		exit 0
	fi
done

