/* Clase: QPSConfigHandler
 * Autor: CetiSoft
 * Version: 0.0.1
 * Fecha de creacion: 12/08/2004
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

#include "qpsconfighandler.h"

/**
 * Constructor 
 */
QPSConfigHandler::QPSConfigHandler() : QXmlDefaultHandler(), numeroDeBDS(0), leer(false)
{
	qDebug("[Construyendo QPSConfigHandler]");
	cnx = new sbbd::SbBDConexion();
}

/**
 * Destructor
 */
QPSConfigHandler::~QPSConfigHandler()
{
	qDebug("[Destruyendo QPSConfigHandler]");
}

/**
 * Esta funcion lee los elementos de apertura: \<apertura\>
 */
bool QPSConfigHandler::startElement( const QString& , const QString& , const QString& qname, const QXmlAttributes& atts)
{
	qName = qname;
	if (raiz == "")
	{
		if (qname == "QPSConfig")
		{
			raiz = qname;
			leer = false;
		}  else
			leer = true;
	}
	
	if ( qname == "QPBD" )
	{
		numeroDeBDS++;
		leer = false;
	}
	else
		leer = true;

	return true;	
}

/**
 * Esta funcion lee los elementos de cierre: \</cierre\>
 */
bool QPSConfigHandler::endElement(const QString& ns, const QString& localname, const QString& qname)
{
	if (qname == "QPBD" )
	{
		std::cout << bdnombre << " " << usuario << " " << password << " " << bdhost << std::endl;
		cnx->cargarBD(bddriver, bdnombre, usuario, password, bdhost );
	}
	qName = "";
	return true;
}

/** 
 * Esta funcion lee la seccion de texto:  \<tag\>Esta Seccion\</tag\>
 */
bool QPSConfigHandler::characters(const QString &ch)
{
	bool conversion;
	if ( raiz == "QPSConfig" )
	{
		if (qName == "PuertoAST")
			puertoAST = ch.toInt(&conversion);
		else if (qName == "PuertoCST")
			puertoCST = ch.toInt(&conversion);
		else if (qName == "MaxClients" )
			maxClients = ch.toInt(&conversion);
		else if (qName == "bdnombre" )
		{
			bdnombre = ch;
			listaNombresBDS.append(bdnombre);
		}
		else if (qName == "bddriver" )
			bddriver = ch;
		else if (qName == "bdhost" )
			bdhost = ch;
		else if (qName == "bdpuerto" )
			bdpuerto = ch;
		else if (qName == "usuario" )
			usuario = ch;
		else if (qName == "password" )
			password = ch;
	}
	return true;
}

/**
 * retorna el puerto usado entre el administrador y el servidor de transacciones.
 */
int QPSConfigHandler::past()
{
	return puertoAST;
}

/**
 * retorna el puerto usado entre el cliente y el servidor de transacciones.
 */
int QPSConfigHandler::pcst()
{
	return puertoCST;
}

/**
 * retorna el numero maximo de clientes que recibira el servidor.
 */
int QPSConfigHandler::maximoDeClientes()
{
	return maxClients;
}

/**
 * retorna el numero de bases de datos configuradas.
 */
int QPSConfigHandler::obtenerNumeroDeBDS()
{
	return numeroDeBDS;
}

/*
QString QPSConfigHandler::nombreDB()
{
	return bdnombre;
}

QString QPSConfigHandler::obtenerUsuario()
{
	return usuario;
}

QString QPSConfigHandler::obtenerPassword()
{
	return password;
}
*/

/**
 * Retorna la lista de bases de datos configuradas.
 */
ListaDeBD QPSConfigHandler::dbs()
{
	return basesDeDatos;
}

/**
 * Retorna la lista de los nombres de las bases de datos configuradas.
 */
QStringList QPSConfigHandler::nombresBDS()
{
	return listaNombresBDS;
}

/**
 * Retorna la conexion con la base de datos.
 */
sbbd::SbBDConexion QPSConfigHandler::conexiones()
{
	return *cnx;
}

