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

#include "domserverconnection.h"

class DomServer : public QTcpServer
{
	Q_OBJECT

	public:
		DomServer(QObject *parent = 0);
		void sendToAll(const QDomDocument &pkg);
		
	public slots:
		void sendToAll(const QString &msg);
		void removeConnection(DomServerConnection *cnx);
		void authenticate(DomServerConnection *cnx,const QString &login, const QString &password);
		
		
	private:
		void handle(const DomServerConnection *cnx);
		
		
	protected:
		void incomingConnection(int socketDescriptor);
		
	private:
		QList<DomServerConnection *> m_connections;
};

#endif
