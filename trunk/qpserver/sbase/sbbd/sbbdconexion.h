/* Clase: SbBDConexion
 * Autor: CetiSoft
 * Version: 0.0.1
 * Fecha de creacion: 13/08/2004
 * Fecha de modificacion:
 * Relacion con objetos:
 * Descripcion: 
 *	Esta clase maneja la configuracion  y conexion de la base de datos.
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

#ifndef SBBDCONEXION_H
#define SBBDCONEXION_H

#include <iostream>
#include <qsqldatabase.h>
#include <qsqlquery.h>

namespace sbbd
{
	/**
	Esta clase maneja la configuracion  y conexion de la base de datos.

	@author CetiSoft
	 */
	class SbBDConexion
	{
		private:
			QSqlDatabase *cnx;
			QString bdname, bduser, bdpasswd, bdhost;
	
		public:
			SbBDConexion(/*QString bddriver, QString name*/);
			~SbBDConexion();
			void cargarBD(const QString bddriver, const QString bdname, const QString bduser, const QString bdpassword, const QString bdhost );
			void cargarBD(const QString bduser, const QString bdpassword, const QString bdhost);
			QSqlDatabase *obtenerBD(const QString &key) const;
			bool abrirConexion();
			QSqlQuery consultar(const QString  &consulta = QString::null ) const;
			QString nombreBD () const;
			QString nombreUsuario () const;
			QString passwd () const;
			QString host () const;
			void setDatabaseName ( const QString & name );
			void setUserName ( const QString & name );
			void setPassword ( const QString & password );
			void setHostName ( const QString & host );
	};
}

#endif
