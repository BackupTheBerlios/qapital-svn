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

CConnector::CConnector(QObject * parent) : CConnectorBase(parent)
{
	m_parser = new CPackageParser;
	m_reader.setContentHandler(m_parser);
	m_reader.setErrorHandler(m_parser);
}


CConnector::~CConnector()
{
}

void CConnector::readFromServer()
{
	while(canReadLine())
	{
		m_readed += readLine();
		
		if ( m_readed.endsWith("%%\n") )
		{
			break;
		}
	}
// 	m_readed = QString(readAll());
	
	if ( m_readed.isEmpty() )
	{
		return;
	}
	
	m_readed.remove(m_readed.lastIndexOf("%%"), 2);
	
	QXmlInputSource xmlsource;
	xmlsource.setData(m_readed+'\n');
			
// 	dDebug() << "READED: " << m_readed;
	
	if ( m_reader.parse(&xmlsource) )
	{
		QString root = m_parser->root();
		
		if( root == "Success")
		{
			emit readedModuleForms( m_parser->moduleForms() );
			
			emit message(Msg::Info, m_parser->results()["message"]);
		}
		else if(root == "Chat" )
		{
			XMLResults results = m_parser->results();
			emit chatMessage(results["login"], results["message"]);
		}
		else if ( root == "Error" )
		{
			XMLResults results = m_parser->results();
			emit message(Msg::Error, "Error "+results["id"]+": "+results["message"] );
		}
		
		m_readed = "";
	}
	else
	{
		dDebug() << "Error parsing: " << m_readed;
	}
}

void CConnector::login(const QString &user, const QString &passwd)
{
	QString toSend = CConnectPackage(user, passwd).toString();
	toSend.remove('\n');
	
	sendToServer( toSend );
}

void CConnector::handleError(QAbstractSocket::SocketError error)
{
	dError() << "Error: " << error;
}


