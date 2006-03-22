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

#ifndef DOMSERVERCONNECTION_H
#define DOMSERVERCONNECTION_H

#include <QThread>
#include <QTcpSocket>
#include <QDomDocument>

#include "domserverclient.h"
#include "spackageparser.h"

class DomServerConnection : public QThread
{
	Q_OBJECT;

	public:
		DomServerConnection(int socketDescriptor, QObject *parent);
		~DomServerConnection();
		void run();
		
		void close();
		
	private:
		
	public slots:
		void sendToClient(const QString &msg);
		void sendToClient(const QDomDocument &doc);

	signals:
		void error(QTcpSocket::SocketError socketError);
		void requestSendToAll(const QString &msg);
// 		void requestSendToAll(const QDomDocument &pkg);
		void requestRemoveConnection(DomServerConnection *self);
		
		void requestAuth(DomServerConnection *cnx, const QString &, const QString &);

	private:
		DomServerClient *m_client;
		
		QXmlSimpleReader m_reader;
		SPackageParser *m_parser;
};

#endif
