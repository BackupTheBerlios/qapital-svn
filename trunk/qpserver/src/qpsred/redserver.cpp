/* Clase: RedServer
 * Autor: CetiSoft
 * Version: 0.0.1
 * Fecha de creacion: 19/06/2004
 * Fecha de modificacion:
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

#include "redserver.h"

/** 
Constructor
@param puerto: Puerto del servidor 
@param conexiones: Numero de conexiones que admite el servidor.
@param padre: Padre del objeto.
*/
RedServer::RedServer(int puerto, int conexiones, QObject* padre) : QServerSocket(puerto, conexiones, padre)
{
	qDebug("[Construyendo RedServer]");
	conexionesFallidas.setAutoDelete(true);
	if ( ! this->ok() )
	{
		qWarning(tr("RedServer: Error abriendo el puerto: %1").arg(puerto));
		QPLOGGER.salvarLog(SBLogger::QP_ERROR, SBLogger::SERVIDOR, tr("No se pudo abrir el puerto %1").arg(puerto) );
		exit(-1);
	}
	else
	{
		QPINFO( tr("Servidor corriendo en el puerto: %1").arg(puerto) );
	}
}

/**
Destructor
*/
RedServer::~RedServer()
{
	qDebug("[Destruyendo RedServer]");
}

/**
Envia el texto a cada uno de los clientes de la lista.
@param str: Texto a enviar.
*/
void RedServer::redServerEnviarATodos(QString str)
{
	qDebug(tr("Enviando a todos: %1").arg(str) );
	for (unsigned int i = 0; i < rdsClientes.count(); i++)
	{
		RedCliente *tmpCliente = rdsClientes[i];
		if (tmpCliente != NULL )
			tmpCliente->redClienteEnviar(str);
	}
}

/**
Este slot se conecta cuando ocurre una conexion nueva.
@param socket: decriptor del socket.
@todo terminar el soporte para blacklists, escribiendo un archivo y leyendo de él, en el momento se volveran a recibir conexiones pasado un tiempo...
*/
void RedServer::newConnection(int socket)
{
	RedCliente *s = new RedCliente( socket, this, "Cliente" );
	QString ip = s->address ().toString();

	if (conexionesFallidas.find(ip) == 0 )
	{
		conexionesFallidas.insert(ip, new int(0) );
	}
	
	int fallos = (int) *conexionesFallidas.find(ip);
	
	if (fallos  > 10 )
	{
		std::cout << tr("Numero de fallos: %1").arg(fallos) << std::endl;
		s->redClienteEnviar(tr("Su ip sera agregada a la lista de negra del servidor, si considera que esto es un error por favor contacte al administrador del servidor.\nSu conexion fue denegada."));
		s->redClienteCerrarConexion();
		QPLOGGER.salvarLog(SBLogger::QP_INFO, SBLogger::SERVIDOR, tr("La ip %1 fue agregada a la blacklist.").arg(ip));
		
		// FIXME: El servidor podria volver a recibir conexiones desde la ip bloqueada
		QTimer::singleShot(300000, this, SLOT( removerBans() ));
	} 
	else
	{
		QPINFO(tr("Nueva Conexion desde: %1").arg(ip) );
		QPLOGGER.salvarLog(SBLogger::QP_INFO, SBLogger::SERVIDOR, tr("Nueva Conexion desde: %1").arg(ip));
		rdsClientes.append(s);
	}
}

/**
Esta funcion se encarga de remover el cliente c de la lista de clientes
@param c: cliente a ser removido
*/
void RedServer::redServerQuitarCliente(RedCliente *c)
{
	rdsClientes.remove(c);
	delete c;
}

void RedServer::fallo(QString ip)
{
	if (conexionesFallidas.find(ip) == 0 )
	{
		conexionesFallidas.insert(ip, new int(0) );
	}
		
	int fallos = (int) *conexionesFallidas.find(ip);
	conexionesFallidas.replace(ip, new int(fallos+1) );
}

void RedServer::removerBans()
{
	std::cout << tr("Removiendo todos los bans") << std::endl;
	conexionesFallidas.clear();
}
