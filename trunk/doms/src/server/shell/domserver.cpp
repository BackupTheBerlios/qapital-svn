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

#include "domserver.h"
#include "domserverconnection.h"

#include <ddebug.h>

#include "serrorpackage.h"
#include "ssuccesspackage.h"

DomServer::DomServer(QObject *parent) : QTcpServer(parent)
{
}

void DomServer::incomingConnection(int socketDescriptor)
{
	SHOW_VAR(m_connections.count());
	
	DomServerConnection *newConnection = new DomServerConnection(socketDescriptor,this);
	
	handle(newConnection);
	
	m_connections << newConnection;
	
	newConnection->start();
}

void DomServer::handle(const DomServerConnection *cnx)
{
	connect(cnx, SIGNAL(finished()), cnx, SLOT(deleteLater()));
	
	connect(cnx, SIGNAL(requestSendToAll( const QString& )), this, SLOT(sendToAll( const QString& )));
	connect(cnx, SIGNAL(requestSendToAll( const QDomDocument& )), this, SLOT(sendToAll( const QDomDocument& )));
	
	connect(cnx, SIGNAL(requestRemoveConnection(DomServerConnection *)), this, SLOT(removeConnection(DomServerConnection *)));
	
	connect(cnx, SIGNAL(requestAuth(DomServerConnection *, const QString &, const QString &)), this, SLOT(authenticate(DomServerConnection *,const QString &, const QString &)));
}


void DomServer::sendToAll(const QString &msg)
{
	foreach(DomServerConnection *connection, m_connections)
	{
		connection->sendToClient(msg);
	}
}

void DomServer::sendToAll(const QDomDocument &pkg)
{
	D_FUNCINFO;
	foreach(DomServerConnection *connection, m_connections)
	{
		connection->sendToClient(pkg);
	}
}

void DomServer::removeConnection(DomServerConnection *cnx)
{
	D_FUNCINFO;
	m_connections.removeAll(cnx);
}

void DomServer::authenticate(DomServerConnection *cnx, const QString &login, const QString &password)
{
	dDebug() << "Request auth!";
	dDebug() << "Login: " << login << " Password: " << password;
	
// 	cnx->sendToClient( SErrorPackage(1, "Bad password or login") );
	
	cnx->sendToClient( SSuccessPackage("weeeeeeee"));
	
	cnx->close(); 
}
