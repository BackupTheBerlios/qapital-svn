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

#include "clnred.h"
#include <qdom.h>

/**
Constructor
@param host: Direreccion del servidor
@param port: puerto del servidor.
*/
qpcred::ClnRed::ClnRed(const QString &host, int port) : QSocket(), host(host), puerto(port), conectado(false)
{
	qDebug("[Construyendo ClnRed]");
}

/**
Destructor
*/
qpcred::ClnRed::~ClnRed()
{
	qDebug("[Destruyendo ClnRed]");
}

void qpcred::ClnRed::conectar()
{
	QObject::connect( this, SIGNAL(connected()), SLOT(clnSocketConectado()) );
        QObject::connect( this, SIGNAL(connectionClosed()),  SLOT(clnConexionCerrada()) );
        QObject::connect( this, SIGNAL(readyRead()), SLOT(clnEstaListo()) );
        QObject::connect( this, SIGNAL(error(int)), SLOT(clnSocketError(int)) );
	this->connectToHost( host, puerto );
	
}

bool qpcred::ClnRed::estaConectado()
{
	return conectado;
}


/**
Slot encargado de desconectarse
*/
void qpcred::ClnRed::clnBye()
{
	QTextStream os(this);
	// Enviar un paquete <CLOSE>...</CLOSE>
}

/**
Este slot es llamado al cerrarse la conexion
*/
void qpcred::ClnRed::clnCerrarConexion()
{
	clnBye();
        this->close();
        if ( this->state() == QSocket::Closing )
	{
             QObject::connect( this, SIGNAL(delayedCloseFinished()), SLOT(clnSocketCerrado()) );
        } 
	else 
	{
            clnSocketCerrado();
        }
}

/**
Slot que se encarga de enviar los datos al servidor.
@param str: es la cadena enviada al servidor.
@see clnEnviarAlServer(QPDocumentoXML doc)
*/
void qpcred::ClnRed::clnEnviarAlServer(QString str)
{
        QTextStream os(this);
	os << str;
}

/**
Slot sobrecargado encargada de enviar al servidor un documento XML
@param doc: documento XML que sera enviado al servidor.
@see clnEnviarAlServer(QString str)
*/
void qpcred::ClnRed::clnEnviarAlServer(sbxml::QPDocumentoXML doc)
{
	clnEnviarAlServer(doc.toString() );
}

/**
slot que se activa cuando el servidor esta listo.
*/
void qpcred::ClnRed::clnEstaListo()
{
        // read from the server
	conectado = true;
        while ( this->canReadLine() )
	{
        	std::cout << this->readLine() << std::endl;
	}
}

/**
Este slot se conecta cuando el socket ha sido conectado.
*/
void qpcred::ClnRed::clnSocketConectado()
{
	conectado = true;
	std::cout << "Conectado!" << std::endl;
	QPLOGGER.salvarLog(SBLogger::QP_INFO, tr("Se logro conectar al servidor"));
}

/**
Se activa cuando la conexion ha sido cerrada.
*/
void qpcred::ClnRed::clnConexionCerrada()
{
	std::cout << "Conexion cerrada" << std::endl;
	QPLOGGER.salvarLog(SBLogger::QP_INFO, tr("La conexion con el servidor fue cerrada.") );
	conectado = false;
}

/**
Se activa cuando el socket ha sido cerrado
*/
void qpcred::ClnRed::clnSocketCerrado()
{
	std::cout << "Socket cerrado" << std::endl;
	QPLOGGER.salvarLog(SBLogger::QP_INFO, tr("La conexion con el servidor fue cerrada.") );
	conectado = false;
}

/**
Se activa cuando ha ocurrido un error, el codigo de error sera reportado en e
@param e: codigo de error
*/
void qpcred::ClnRed::clnSocketError( int e )
{
        std::cout << "Ocurrio un error en la conexion. CodError: " << e << std::endl;
	QPLOGGER.salvarLog(SBLogger::QP_ERROR, tr("Ocurrio un error en la conexion con el servidor.") );
	conectado = false;
}


