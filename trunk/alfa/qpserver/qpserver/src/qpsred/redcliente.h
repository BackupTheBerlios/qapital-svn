/* Clase: RedServer
 * Autor: CetiSoft
 * Version: 0.0.1
 * Fecha de creacion: 19/06/2004
 * Fecha de modificacion:
 * Relacion con objetos:
 * Descripcion: Clase que se encarga de mantener los clientes, esta clase esta intimamente relacionada con el
 * 			 servidor.
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

#ifndef REDCLIENTE_H
#define REDCLIENTE_H

#include <qsocket.h>
#include <iostream>
#include <qobject.h>
#include <qdom.h>
#include <qdict.h>
#include "redserver.h"
#include "srvxmlhandler.h"
#include "sbxml.h"


class RedServer; 

/**
Esta clase representa el servidor qapital
@author CetiSoft
@todo 
- Terminar la comunicacion de los clientes/admin con el servidor de transacciones
- Recibir paquetes XML e interpretarlos.
*/

class RedCliente : public QSocket
{
	Q_OBJECT

	private:
		RedServer *server;
		QString ipServer;
		QString ipCliente;
	
	public:
		RedCliente(int sock, RedServer *padre = 0, const char *nombre = 0 );
    		~RedCliente();
		
		void redClienteEnviarATodos(QString);
		void redClienteEnviar(QString);
		void redClienteEnviar(QDomDocument);

	public slots:
    		void redClienteLeer();
		void redClienteCerrarConexion();
		void redClienteConexionCerrada();
};

#endif
