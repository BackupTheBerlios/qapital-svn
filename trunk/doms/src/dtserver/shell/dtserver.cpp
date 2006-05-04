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

#include <QHostInfo>

#include <ddebug.h>

#include "serrorpackage.h"
#include "ssuccesspackage.h"
#include "sresourcepackage.h"

DTServer::DTServer(QObject *parent) : QTcpServer(parent)
{
}

DTServer::DTServer(DTS::ConnectionType type, const QString &host, QObject *parent) : QTcpServer(parent)
{
	openConnection( type, host);
}

DTServer::~DTServer()
{
}

bool DTServer::openConnection(DTS::ConnectionType type, const QString &host)
{
	QList<QHostAddress> addrs = QHostInfo::fromName(host).addresses();
	
	if ( !addrs.isEmpty() )
	{
		int port = 0;
		
		switch(type)
		{
			case DTS::Admin:
			{
				port = DTS::ADMIN_PORT;
			}
			break;
			case DTS::Client:
			{
				port = DTS::CLIENT_PORT;
			}
			break;
		}
		
		if(! listen(QHostAddress(addrs[0]), port) )
		{
			dError() << "Can't connect to " << host<<":"<<port<< " error was: " << errorString();
			return false;
		}
		else
		{
			m_type = type;
		}
	}
	else
	{
		dError() << "Error while try to resolve " << host;
		return false;
	}
	
	return true;
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
	
	connect(cnx, SIGNAL(requestOperation( const DTQuery* )), this, SLOT(doOperation( const DTQuery* )));
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
	// TODO: encriptar el password
	
	dDebug() << "Request auth!";
	dDebug() << "Login: " << login << " Password: " << password;
	
	DTSelect select(QStringList() << "password", "users" );
	select.setWhere("login="+SQLSTR(login));
	
	SResultSet rs = SDBM->execQuery(&select);
	
	if ( !rs.isValid() )
	{
		cnx->sendToClient( SErrorPackage(1, tr("Bad login") ) );
		cnx->close();
		
		return;
	}
	
	QString truePasswd = rs.map()["password"][0];
	
	if ( truePasswd.isEmpty() || password != truePasswd )
	{
		cnx->sendToClient( SErrorPackage(3, tr("Bad password") ) );
		cnx->close();
	}
	else
	{
		cnx->setLogin(login);
	
		cnx->sendToClient( SSuccessPackage(tr("Welcome to the jungle")));
		cnx->sendToClient( SResourcePackage() );
	}
}

void DTServer::doOperation(const DTQuery *query)
{
	SResultSet rs = SDBM->execQuery(query);
	
	
}



