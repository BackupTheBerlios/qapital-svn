/* Clase: QPSConfigHandler
 * Autor: CetiSoft
 * Version: 0.0.1
 * Fecha de creacion: 12/08/2004
 * Fecha de modificacion:
 * Relacion con objetos:
 * Descripcion: 
 *
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

#ifndef QPSCONFIGHANDLER_H
#define QPSCONFIGHANDLER_H

#include <iostream>
#include <qxml.h>

#include "sbbd.h"

/**
Esta clase se encarga de analizar, interpretar y utilizar el archivo de configuracion del cliente.
@author CetiSoft
*/

class QPSConfigHandler : public QXmlDefaultHandler
{
	private:
		QString qName, raiz, bdnombre, bddriver, bdhost, bdpuerto, usuario, password;
		int puertoAST, puertoCST, maxClients, numeroDeBDS;
		bool leer;
		ListaDeBD basesDeDatos;
		QStringList listaNombresBDS;
		sbbd::SbBDConexion *cnx;
		
	public:
    		QPSConfigHandler();
    		~QPSConfigHandler();
		bool startElement(const QString& , const QString& , const QString& qname, const QXmlAttributes& atts);
		bool endElement( const QString& ns, const QString& localname, const QString& qname);
		bool characters ( const QString & ch );
		sbbd::SbBDConexion conexiones();
		int past();
		int pcst();
		int maximoDeClientes();
		int obtenerNumeroDeBDS();
// 		QString nombreDB();
// 		QString obtenerUsuario();
// 		QString obtenerPassword();
		ListaDeBD dbs();
		QStringList nombresBDS();
};

#endif
