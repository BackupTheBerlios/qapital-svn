/* Clase: RedServer
 * Autor: David Cuadrado
 * Version: 0.0.2
 * Fecha de creacion: 19/06/2004
 * Fecha de modificacion: 23/02/2005
 * Relacion con objetos:
 * Descripcion: Clase que se encarga de mantener los clientes, esta clase esta intimamente relacionada con el servidor.
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

#ifndef QPSREDCLIENTE_H
#define QPSREDCLIENTE_H

#include <qsocket.h>
#include <iostream>
#include <qobject.h>
#include <qdom.h>
#include <qdict.h>
#include "qpsredserver.h"
#include "srvxmlhandler.h"
#include "sbxml.h"

namespace qpsred
{
	class QPSRedServer;
	
	/**
	 * Esta clase representa el servidor qapital
	 * @author CetiSoft
	 * @todo 
	 * - Terminar la comunicacion de los clientes/admin con el servidor de transacciones
	 * - Recibir paquetes XML e interpretarlos.
	 */

	class QPSRedCliente : public QSocket
	{
		Q_OBJECT
	
		private:
			QPSRedServer *server;
			QString ipServer;
			QString ipCliente;
		
		public:
			QPSRedCliente(int sock, QPSRedServer *padre = 0, const char *nombre = 0 );
			~QPSRedCliente();
			
			void enviarATodos(QString);
			void enviarTexto(QString);
			void enviarXml(QDomDocument);
	
		public slots:
			void leer();
			void cerrarConexion();
			void conexionCerrada();
	};
}

#endif
