/* Clase: QPSRedServer
 * Autor: David Cuadrado
 * Version: 0.0.2
 * Fecha de creacion: 19/06/2004
 * Fecha de modificacion: 23/02/2005
 * Relacion con objetos:  
 * Descripcion: 
 *	Esta clase es el servidor, controla el envio y la recepcion de datos.
*/

/*************************************************************************************
 *   Copyright (C) 2004 by CetiSoft                                        						*
 *   cetisoft@linuxmail.org                                                						*
 *                                                                         								*
 *   This program is free software; you can redistribute it and/or modify  			*
 *   it under the terms of the GNU General Public License as published by  		*
 *   the Free Software Foundation; either version 2 of the License, or     			*
 *   (at your option) any later version.                                   						*
 *                                                                         								*
 *   This program is distributed in the hope that it will be useful,       				*
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        	*
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the   	*
 *   GNU General Public License for more details.                          				*
 *                                                                         								*
 *   You should have received a copy of the GNU General Public License     		*
 *   along with this program; if not, write to the                         					*
 *   Free Software Foundation, Inc.,                                       						*
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             			*
 *************************************************************************************/

#ifndef QPSREDSERVER_H
#define QPSREDSERVER_H

#include <qserversocket.h>
#include <qsocket.h>
#include <qtextstream.h>
#include <iostream>
#include <qapplication.h>
#include <qobject.h>
#include <qvaluelist.h>
#include <qtimer.h>

#include "sbred.h"
#include "qpsredcliente.h"
#include "sbqpserver.h"

using sbqpserver::QPLOGGER;
	
namespace qpsred
{
	// Prototipos de clases
	class QPSRedServer;
	class QPSRedCliente;

	typedef QValueList<QPSRedCliente*> Clientes;
	
	/**
	* Esta clase representa el servidor QApital
	* @author CetiSoft
	*/
	class QPSRedServer : public QServerSocket
	{
		Q_OBJECT
				
		private:
			Clientes rdsClientes; // Lista que contiene todos los clientes...
			HashInt conexionesFallidas;
		
		public:
			QPSRedServer(int puerto, int conexiones = 1, QObject* padre = 0);
			~QPSRedServer();
	
			void newConnection(int );
			void enviarATodos(QString );
			void fallo(QString ip);
		public slots:
			void removerBans();
			void quitarCliente(QPSRedCliente *);
	};
}

#endif
