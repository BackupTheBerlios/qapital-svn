/* Clase: BDInstrucciones
 * Autor: CetiSoft
 * Version: 0.0.1
 * Fecha de creacion: 15/08/2004
 * Fecha de modificacion:
 * Relacion con objetos:
 * Descripcion: 
 *	Esta clase almacena las sentencias sql definidas en la base de datos de midas.
*/

/********************************************************************************
 *   Copyright (C) 2004 by CetiSoft                                        	*
 *   cetisoft@linuxmail.org                                                	*
 *                                                                         	*
 *   This program is free software; you can redistribute it and/or modify  	*
 *   it under the terms of the GNU General Public License as published by  	*
 *   the Free Software Foundation; either version 2 of the License, or     	*
 *   (at your option) any later version.                                   	*
 *                                                                         	*
 *   This program is distributed in the hope that it will be useful,       	*
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        	*
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the        	*
 *   GNU General Public License for more details.                          	*
 *                                                                         	*
 *   You should have received a copy of the GNU General Public License     	*
 *   along with this program; if not, write to the                         	*
 *   Free Software Foundation, Inc.,                                       	*
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             	*
 *******************************************************************************/

#ifndef BDINSTRUCCIONES_H
#define BDINSTRUCCIONES_H

#include "sbbd.h"
#include <qstringlist.h>
#include <qapplication.h>

using qapital::QPLOGGER;

/**
Esta clase almacena las sentencias sql definidas en la base de datos de midas.

@author CetiSoft
*/
class BDInstrucciones
{
	private:
		StringHash cacheInstrucciones;
		BoolHash permisos;
		SbBDConexion basesDeDatos;
	public:
	    	BDInstrucciones();
		~BDInstrucciones();
		bool cargarInstrucciones( SbBDConexion conexiones, QStringList dbnames);
		QString obtenerInstruccion(const QString &codigo, const QStringList &argumentos) const;
		QString obtenerInstruccion(const QString &codigo) const;
		QSqlQuery exec(QString dbname, QString sqlkey);
		QSqlQuery exec(QString dbname, QString sqlkey, QStringList args);
};

#endif
