/* Clase: SbXmlConfig
 * Autor: CetiSoft
 * Version: 0.0.1
 * Fecha de creacion: 12/08/2004
 * Fecha de modificacion:
 * Relacion con objetos:
 * Descripcion: 
 *	Esta clase sirve para generar las configuraciones del servidor, administrador o los clientes.
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

#ifndef SBXMLCONFIG_H
#define SBXMLCONFIG_H

#include "qpdocumentoxml.h"
#include "sbqpserver.h"

namespace sbxml
{
	/**
	Esta clase sirve para generar las configuraciones del servidor, administrador o los clientes.

	@author CetiSoft
	 */
	
	class SbXmlConfig
	{
		public:
			SbXmlConfig();
			~SbXmlConfig();
			static QPDocumentoXML crearConfigCliente(QString host, QString puerto, int tipoDeInterfaz);
			//static QPDocumentoXML crearConfigServer(QString past, QString pcst, QString maxClients, QString bdNombre, QString bdDriver, QString bdHost, QString bdPuerto, QString usuario, QString password);
			static QPDocumentoXML crearConfigServer(StringHash argumentos);
			static QPDocumentoXML crearConfigAdmin ();
	
	};
}
#endif
