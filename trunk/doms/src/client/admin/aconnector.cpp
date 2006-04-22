/***************************************************************************
 *   Copyright (C) 2006 by David Cuadrado                                  *
 *   krawek@gmail.com                                                       *
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

#include "aconnector.h"

#include "cconnectpackage.h"

#include <ddebug.h>

AConnector::AConnector(QObject * parent) : CConnectorBase(parent)
{
	m_parser = new APackageParser;
	m_reader.setContentHandler(m_parser);
	m_reader.setErrorHandler(m_parser);
}


AConnector::~AConnector()
{
}


void AConnector::login(const QString& user, const QString& passwd)
{
	QString toSend = CConnectPackage(user, passwd).toString();
	toSend.remove('\n');
	
	sendToServer( toSend );
}

void AConnector::handleError(QAbstractSocket::SocketError error)
{
	dError() << "Error: " << error;
}

void AConnector::readFromServer()
{
	while(canReadLine())
	{
		m_readed += readLine();
	}
	
	QXmlInputSource xmlsource;
	xmlsource.setData(m_readed);
			
	dDebug() << "READED: " << m_readed;
	
	if ( m_reader.parse(&xmlsource) )
	{
// 		QString root = m_parser->root();
		
		
		m_readed = "";
	}
	else
	{
		
	}
}

