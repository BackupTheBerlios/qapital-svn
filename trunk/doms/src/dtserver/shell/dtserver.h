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

#ifndef FORTUNESERVER_H
#define FORTUNESERVER_H

#include <QStringList>
#include <QTcpServer>

#include "dtserverconnection.h"
#include "sdatabase.h"

#include "dtsglobal.h"

/**
 * Esta es la clase controladora, esta clase representa el servidor.
 * @author David Cuadrado \<krawek@gmail.com\>
 */
class DTServer : public QTcpServer
{
	Q_OBJECT;
	
	public:
		DTServer(QObject *parent = 0);
		DTServer(DTS::ConnectionType type, const QString &host, QObject *parent = 0);
		~DTServer();
		void sendToAll(const QDomDocument &pkg);
		
		bool openConnection(DTS::ConnectionType type, const QString &host);
		
	public slots:
		void sendToAll(const QString &msg);
		void removeConnection(DTServerConnection *cnx);
		void authenticate(DTServerConnection *cnx,const QString &login, const QString &password);
		
		void doOperation(DTServerConnection *cnx, const DTQuery *query);
		
		
	private:
		void handle(const DTServerConnection *cnx);
		
		
	protected:
		void incomingConnection(int socketDescriptor);
		
	private:
		QList<DTServerConnection *> m_connections;
		
		DTS::ConnectionType m_type;
};

#endif
