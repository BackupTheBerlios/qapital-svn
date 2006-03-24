/***************************************************************************
 *   Copyright (C) 2006 by David Cuadrado                                  *
 *   krawek@gmail.com                                                      *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#include "dtserver.h"
#include "dtserverconnection.h"

#include <ddebug.h>

#include "serrorpackage.h"
#include "ssuccesspackage.h"
#include "sresourcepackage.h"

DTServer::DTServer(QObject *parent) : QTcpServer(parent)
{
}

void DTServer::incomingConnection(int socketDescriptor)
{
	SHOW_VAR(m_connections.count());
	
	DTServerConnection *newConnection = new DTServerConnection(socketDescriptor,this);
	
	handle(newConnection);
	
	m_connections << newConnection;
	
	newConnection->start();
}

void DTServer::handle(const DTServerConnection *cnx)
{
	connect(cnx, SIGNAL(finished()), cnx, SLOT(deleteLater()));
	
	connect(cnx, SIGNAL(requestSendToAll( const QString& )), this, SLOT(sendToAll( const QString& )));
	connect(cnx, SIGNAL(requestSendToAll( const QDomDocument& )), this, SLOT(sendToAll( const QDomDocument& )));
	
	connect(cnx, SIGNAL(requestRemoveConnection(DTServerConnection *)), this, SLOT(removeConnection(DTServerConnection *)));
	
	connect(cnx, SIGNAL(requestAuth(DTServerConnection *, const QString &, const QString &)), this, SLOT(authenticate(DTServerConnection *,const QString &, const QString &)));
}


void DTServer::sendToAll(const QString &msg)
{
	foreach(DTServerConnection *connection, m_connections)
	{
		connection->sendToClient(msg);
	}
}

void DTServer::sendToAll(const QDomDocument &pkg)
{
	D_FUNCINFO;
	foreach(DTServerConnection *connection, m_connections)
	{
		connection->sendToClient(pkg);
	}
}

void DTServer::removeConnection(DTServerConnection *cnx)
{
	D_FUNCINFO;
	m_connections.removeAll(cnx);
}

void DTServer::authenticate(DTServerConnection *cnx, const QString &login, const QString &password)
{
	// TODO: HACER VALIDACION!
	// TODO: Hacer una blacklist!
	dDebug() << "Request auth!";
	dDebug() << "Login: " << login << " Password: " << password;
	
// 	cnx->sendToClient( SErrorPackage(1, "Bad password or login") );
	
	// Cuando se verique como correcto
	cnx->setLogin(login);
	
	cnx->sendToClient( SSuccessPackage("weeeeeeee"));
	cnx->sendToClient( SResourcePackage() );
	
// 	cnx->close(); 
}
