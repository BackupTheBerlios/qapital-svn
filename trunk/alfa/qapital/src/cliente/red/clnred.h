/***************************************************************************
 *   Copyright (C) 2004 by krawek                                          *
 *   krawek@linuxmail.org                                                  *
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
#ifndef CLNRED_H
#define CLNRED_H

#include <qsocket.h>
#include <qapplication.h>
#include <qtextstream.h>
#include <iostream>
#include "sbxml.h"

using qapital::QPLOGGER;

/**
Esta clase es la encargada de conectarse al socket del servidor de transacciones.
@author CetiSoft
@todo heredar de QSocket!!
*/
class ClnRed : public QSocket
{

	Q_OBJECT
	
	private:
		QString host;
		int puerto;
		bool conectado;

	public:
    		ClnRed(const QString &host, Q_UINT16 port);
    		~ClnRed();
		void conectar();
		bool estaConectado();
		
	
	public slots:
		void clnCerrarConexion();
    		void clnEnviarAlServer(QString);
		void clnEnviarAlServer(QPDocumentoXML);
    		void clnEstaListo();
    		void clnSocketConectado();
    		void clnConexionCerrada();
    		void clnSocketCerrado();
    		void clnSocketError( int e );
		void clnBye();
};

#endif
