/* Clase: RedCliente
 * Autor: CetiSoft
 * Version: 0.0.1
 * Fecha de creacion: 19/06/2004
 * Fecha de modificacion:
*/

/********************************************************************************
 *   Copyright (C) 2004 by CetiSoft                                        	*
 *   cetisoft@linuxmail.org                                                	*
 *                                                                         	*
 *   This program is free software; you can redistribute it and/or modify  	*
 *   it under the terms of the GNU General Public License as published by  	*
 *   the Free Software Foundation; either version 2 of the License, or     	*
 *   (at your option) any later version.                                   	*
 *                                                                         	*
 *   This program is distributed in the hope that it will be useful,       	*
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        	*
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the        	*
 *   GNU General Public License for more details.                          	*
 *                                                                         	*
 *   You should have received a copy of the GNU General Public License     	*
 *   along with this program; if not, write to the                         	*
 *   Free Software Foundation, Inc.,                                       	*
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             	*
 *******************************************************************************/

#include "redcliente.h"
#include <qdatastream.h>
#include <qstringlist.h>


/**
Constructor
@param sock: socket asociado.
@param padre: El servidor padre.
@param nombre: El nombre del objecto.
*/
RedCliente::RedCliente(int sock, RedServer *padre, const char *nombre)
 : QSocket(0, nombre), server(padre)
{
	//qDebug("[Construyendo RedCliente]");
	INIQPC; 
        // esta listo para leer? lea.
        connect( this, SIGNAL(readyRead()), SLOT(redClienteLeer()) );
	
	// Se cierra la conexion...
        connect( this, SIGNAL(connectionClosed()), SLOT(deleteLater()) );
	
        this->setSocket( sock );
	ipCliente = socketDevice()->address().toString();
}

/**
Destructor
*/
RedCliente::~RedCliente()
{
	qDebug("[Destruyendo RedCliente]");	
}

/**
* Esta funcion se encarga de enviar una cadena al cliente.
* @param str cadena de texto enviada al cliente.
* @see redClienteEnviar(QDomDocument doc)
*/
void RedCliente::redClienteEnviar(QString str)
{
	QTextStream ts(this);
	ts << str << endl;
	qDebug(tr("Enviando: ") + str);
}

/**
* Esta funcion se encarga de enviar un documento XML al cliente.
* @param doc Documento XML.
* @see redClienteEnviar(QString str)
*/
void RedCliente::redClienteEnviar(QDomDocument doc)
{
	QString str = doc.toString();
	redClienteEnviar(str);
}

/**
Esta funcion es la encargada de leer del canal e interpretar la cadena leida.
*/
void RedCliente::redClienteLeer()
{
	// flujo de texto asociado al canal
	QTextStream ts(this);
        QString strXmlDoc = "";
	
	while ( this->canReadLine() )
	{
		strXmlDoc += ts.readLine();
	}
	
	if ( ! state() == QSocket::Connected || state() == QSocket::Closing || state() == QSocket::Idle )
	{
		qDebug("No se puede leer");
		server->redServerQuitarCliente(this);
	}
	else
	{
		QXmlInputSource sourceXML;
		sourceXML.setData(strXmlDoc);
		
		SrvXmlHandler *xmlHandler = new SrvXmlHandler;
		QXmlSimpleReader reader;
    		reader.setContentHandler( xmlHandler );
		
		if ( ! reader.parse( sourceXML ) )
		{
			// Hubo un error, enviar <ERROR>...</ERROR>
			SbXMLError paqueteDeError("0", tr("Formato de paquete invalido"));
			redClienteEnviar(paqueteDeError);
			server->fallo(ipCliente);
			redClienteCerrarConexion();
		}
		sourceXML.reset();
	}
}

void RedCliente::redClienteCerrarConexion()
{
        this->close();
        if ( this->state() == QSocket::Closing )
	{
		connect (this , SIGNAL(delayedCloseFinished () ), SLOT(redClienteConexionCerrada() ));
        }
	else
	{
		redClienteConexionCerrada();
	}
}

void RedCliente::redClienteConexionCerrada()
{
	QPLOGGER.salvarLog(SBLogger::QP_INFO, SBLogger::SERVIDOR, tr("Conexion cerrada por el cliente %1").arg(ipCliente));
	server->redServerQuitarCliente(this);
}


