/* Clase: QPSRedCliente
 * Autor: David Cuadrado
 * Version: 0.0.2
 * Fecha de creacion: 19/06/2004
 * Fecha de modificacion: 23/02/2005
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

#include "qpsredcliente.h"
#include <qdatastream.h>
#include <qstringlist.h>

#include "aceptarconexion.h"

/**
* Constructor
* @param sock: socket asociado.
* @param padre: El servidor padre.
* @param nombre: El nombre del objecto.
*/
qpsred::QPSRedCliente::QPSRedCliente(int sock, QPSRedServer *padre, const char *nombre)
 : QSocket(0, nombre), server(padre)
{
	//qDebug("[Construyendo QPSRedCliente]");
	INIQPC; 
        // esta listo para leer? lea.
        connect( this, SIGNAL(readyRead()), SLOT(leer()) );
	
	// Se cierra la conexion...
        connect( this, SIGNAL(connectionClosed()), SLOT(deleteLater()) );
	
        this->setSocket( sock );
	ipCliente = socketDevice()->address().toString();
}

/**
* Destructor
*/
qpsred::QPSRedCliente::~QPSRedCliente()
{
	qDebug("[Destruyendo QPSRedCliente]");	
}

/**
* Esta funcion se encarga de enviar una cadena al cliente.
* @param str cadena de texto enviada al cliente.
* @see redClienteEnviar(QDomDocument doc)
*/
void qpsred::QPSRedCliente::enviarTexto(QString str)
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
void qpsred::QPSRedCliente::enviarXml(QDomDocument doc)
{
	QString str = doc.toString();
	enviarTexto(str);
}

/**
* Esta funcion es la encargada de leer del canal e interpretar la cadena leida.
*/
void qpsred::QPSRedCliente::leer()
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
		server->quitarCliente(this);
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
			sbxml::SbXMLError paqueteDeError("0", tr("Formato de paquete invalido"));
			enviarXml(paqueteDeError);
			server->fallo(ipCliente);
			cerrarConexion();
		}
		
		QStringList datos = xmlHandler->obtenerDatos();
		
		if ( xmlHandler->obtenerRaiz() == "CNX" )
		{
			if ( datos.count() == 3 )
			{
				qpscontrol::AceptarConexion acpcnx( server->obtenerInstrucciones(), datos[0], datos[1]);
			}
			else
			{
				std::cerr << "Paquete invalido" << std::endl;
				// TODO: Enviar ErrorXML y cerrar conexion.
			}
		}
		
		sourceXML.reset();
	}
}

/**
* Esta funcion cierra la conexion
*/
void qpsred::QPSRedCliente::cerrarConexion()
{
        this->close();
        if ( this->state() == QSocket::Closing )
	{
		connect (this , SIGNAL(delayedCloseFinished () ), SLOT(conexionCerrada() ));
        }
	else
	{
		conexionCerrada();
	}
}

/**
* Este slot es activado cuando se ha cerrado la conexion.
*/
void qpsred::QPSRedCliente::conexionCerrada()
{
	QPLOGGER.salvarLog(SBLogger::QP_INFO, SBLogger::SERVIDOR, tr("Conexion cerrada por el cliente %1").arg(ipCliente));
	server->quitarCliente(this);
}

