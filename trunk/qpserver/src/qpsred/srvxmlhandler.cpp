/* Clase: SrvXmlHandler
 * Autor: CetiSoft
 * Version: 0.0.1
 * Fecha de creacion: 10/07/2004
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

#include "srvxmlhandler.h"

/**
Constructor
*/
SrvXmlHandler::SrvXmlHandler() : QXmlDefaultHandler(), qName(""), leer(false)
{
}

/**
Destructor
*/
SrvXmlHandler::~SrvXmlHandler()
{
}

/**
Esta funcion lee los elementos de apertura: \<apertura\>
*/
bool SrvXmlHandler::startElement(const QString& , const QString& , const QString& qname, const QXmlAttributes& atts)
{
	qName = qname;
	
	// CNX
	if (raiz == "")
	{
		if (qname == "CNX")
		{
			raiz = qname;
			leer = false;
		}
		else if (qname == "ERROR")
		{
			raiz = qname;
			leer = true;
		}
	} else
	{
		if (raiz == "CNX")
		{
			if (qname == "login" || qname == "password" )
			{
				leer = true;
			} else
				leer = false;
		}
		else
		{
			std::cout << "Error en autentificacion." << std::endl;
			return false;
		}
	}

	return true;
}

/**
Esta funcion lee los elementos de cierre: \</cierre\>
*/
bool SrvXmlHandler::endElement( const QString& ns, const QString& localname, const QString& qname)
{
	qName = "";
	return true;
}

/** 
Esta funcion lee la seccion de texto: \<tag\>Esta Seccion \</tag\>
*/
bool SrvXmlHandler::characters ( const QString & ch )
{
	if ( raiz == "CNX" )
	{
		if (qName == "login")
			std::cout << "Usuario: " << ch << std::endl;
		else if (qName == "password")
			std::cout << "Password: " << ch << std::endl;
	}
	return true;
} 
