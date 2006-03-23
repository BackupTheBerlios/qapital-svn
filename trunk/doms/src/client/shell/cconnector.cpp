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

#include "cconnector.h"

#include <QDataStream>

#include <ddebug.h>

#include "cconnectpackage.h"
#include "cpackageparser.h"

#include "global.h"

CConnector::CConnector(QObject * parent) : QTcpSocket(parent)
{
	connect(this, SIGNAL(readyRead()), this, SLOT(readFromServer()));
	connect(this, SIGNAL(error ( QAbstractSocket::SocketError)), this, SLOT(handleError(QAbstractSocket::SocketError)));
	
	connect(this, SIGNAL(connected()), this, SLOT(flushQueue()));
	
	m_parser = new CPackageParser;
	m_reader.setContentHandler(m_parser);
	m_reader.setErrorHandler(m_parser);
}


CConnector::~CConnector()
{
}

void CConnector::readFromServer()
{
	QString readed;
	
	while(canReadLine())
	{
		readed += readLine();
	}
	QXmlInputSource xmlsource;
	xmlsource.setData(readed);
			
	dDebug() << "READED: " << readed;
			
	if ( m_reader.parse(&xmlsource) )
	{
		QString root = m_parser->root();
		
		if( root == "Success")
		{
			emit readedModuleForms( m_parser->moduleForms() );
		}
		else if(root == "Chat" )
		{
			XMLResults results = m_parser->results();
			emit chatMessage(results["login"], results["message"]);
		}
	}
	else
	{
		
	}
}

void CConnector::sendToServer(const QString &text)
{
	dDebug() << "Sending: " << text;
	
	if ( state() == QAbstractSocket::ConnectedState )
	{
		QTextStream out(this);
		out << text << endl;
		flush();
	}
	else
	{
		m_queue << text;
	}
}

void CConnector::login(const QString &user, const QString &passwd)
{
	QString toSend = CConnectPackage(user, passwd).toString();
	toSend.remove('\n');
	
	sendToServer( toSend );
}

void CConnector::flushQueue()
{
	D_FUNCINFO;
	while ( m_queue.count() > 0 )
	{
		sendToServer( m_queue.takeFirst());
	}
}

void CConnector::handleError(QAbstractSocket::SocketError error)
{
	dError() << "Error: " << error;
}


