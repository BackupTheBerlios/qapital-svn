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

#ifndef CCONNECTOR_H
#define CCONNECTOR_H

#include "cconnectorbase.h"

#include <QStringList>
#include <QXmlSimpleReader>

#include "global.h"

class CPackageParser;

/**
 * Maneja las conexiones al servidor, asi mismo tambien maneja los errores de conexion
 * @author David Cuadrado \<krawek@gmail.com\>
*/
class CConnector : public CConnectorBase
{
	Q_OBJECT;
	public:
		CConnector(QObject * parent = 0);
		~CConnector();
		
		void login(const QString &user, const QString &passwd);
		
	private slots:
		void readFromServer();
		void handleError(QAbstractSocket::SocketError error);
		
	signals:
		void readedModuleForms(const ModuleForms &);
		void chatMessage(const QString &login, const QString &msg);
		void message(Msg::Type t, const QString &message);
		void operationFinished(const QList<XMLResults> &results );
		
	private:
		CPackageParser *m_parser;
		
		QString m_readed;
};

#endif
