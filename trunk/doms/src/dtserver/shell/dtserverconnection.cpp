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

#include "dtserverconnection.h"

#include <QtNetwork>

#include <ddebug.h>

#include "serrorpackage.h"
#include "schatpackage.h"

DTServerConnection::DTServerConnection(int socketDescriptor, QObject *parent) : QThread(parent)
{
	m_client = new DTServerClient(this);
	m_client->setSocketDescriptor(socketDescriptor);
	
	m_parser = new SPackageParser;
	
	m_reader.setContentHandler(m_parser);
	m_reader.setErrorHandler(m_parser);
}

DTServerConnection::~DTServerConnection()
{
	delete m_client;
}

void DTServerConnection::run()
{
	while(m_client->state() != QAbstractSocket::UnconnectedState)
	{
		QString readed;
		while(m_client->canReadLine())
		{
			readed += m_client->readLine();
		}
		
		if ( !readed.isEmpty() )
		{
			QXmlInputSource xmlsource;
			xmlsource.setData(readed);
			
// 			dDebug() << "READED: " << readed;
			
			if ( m_reader.parse(&xmlsource) )
			{
				QString root = m_parser->root();
				QMap<QString, QString> values = m_parser->values();
				
				if ( root == "Connection")
				{
					emit requestAuth(this, values["Login"], values["Password"] );
				}
				else if ( root == "Chat" )
				{
					emit requestSendToAll(  SChatPackage(m_login,values["Message"]).toString().remove('\n') );
				}
			}
			else
			{
				sendToClient( SErrorPackage(0, tr("Bad package")) );
				if ( !readed.isEmpty() )
				{
					close();
				}
			}
		}
	}
	
	// Finish connection
	emit requestRemoveConnection( this );
}

void DTServerConnection::sendToClient(const QString &msg)
{
// 	dDebug() << "SENDING: " << msg;
	QTextStream out(m_client);
	
	out << msg << endl;
	m_client->flush();
}

void DTServerConnection::sendToClient(const QDomDocument &doc)
{
	sendToClient( doc.toString());
}

void DTServerConnection::close()
{
	D_FUNCINFO;
// 	m_client->waitForDisconnected();
	m_client->disconnectFromHost();
	m_client->close();
}

void DTServerConnection::setLogin(const QString &login)
{
	m_login = login;
}

