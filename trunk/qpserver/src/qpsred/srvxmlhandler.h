/* Clase: QPXmlHandler
 * Autor: CetiSoft
 * Version: 0.0.1
 * Fecha de creacion: 10/07/2004
 * Fecha de modificacion:
 * Relacion con objetos:
 * Descripcion: 
 *	Esta clase es una implementacion de un manejador de archivos XML.
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

#ifndef SRVXMLHANDLER_H
#define SRVXMLHANDLER_H

#include <qxml.h>
#include <iostream>

namespace qpsred
{
	/**
	Esta clase se encarga de analizar los paquetes XML que llegan al servidor.
	@author CetiSoft
	*/
	class SrvXmlHandler : public QXmlDefaultHandler
	{
		private:
			QString qName, raiz;
			bool leer;
			QStringList datos;
			
		public:
			SrvXmlHandler();
			~SrvXmlHandler();
			bool startElement(const QString& , const QString& , const QString& , const QXmlAttributes& );
			bool endElement( const QString& , const QString& , const QString& );
			bool characters ( const QString & ch );
			QStringList obtenerDatos();
			QString obtenerRaiz();
	};
}
#endif
