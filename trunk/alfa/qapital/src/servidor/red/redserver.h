/* Clase: RedServer
 * Autor: CetiSoft
 * Version: 0.0.1
 * Fecha de creacion: 19/06/2004
 * Fecha de modificacion:
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

#ifndef REDSERVER_H
#define REDSERVER_H

#include <qserversocket.h>
#include <qsocket.h>
#include <qtextstream.h>
#include <iostream>
#include <qapplication.h>
#include <qobject.h>
#include <qvaluelist.h>
#include <qtimer.h>

#include "sbred.h"
#include "redcliente.h"

using qapital::QPLOGGER;

// Prototipos de clases
class RedServer;
class RedCliente;

typedef QValueList<RedCliente*> Clientes;

/**
Esta clase representa el servidor QApital
@author CetiSoft
*/

class RedServer : public QServerSocket
{
	Q_OBJECT
			
	private:
		Clientes rdsClientes; // Lista que contiene todos los clientes...
		HashInt conexionesFallidas;
	
	public:
		RedServer(Q_UINT16 puerto, int conexiones = 1, QObject* padre = 0);
		~RedServer();

		void newConnection(int );
		void redServerEnviarATodos(QString );
		void fallo(QString ip);
	public slots:
		void removerBans();
		void redServerQuitarCliente(RedCliente *);
};

#endif
