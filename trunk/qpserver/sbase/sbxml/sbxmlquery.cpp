/* Clase: SbXmlQUERY
 * Autor: CetiSoft
 * Version: 0.0.1
 * Fecha de creacion: /08/2004
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

#include "sbxmlquery.h"

using sbxml::QPDocumentoXML;

/**
 * Constructor
 * @param sqlkey
 * @param argumentos
 */
sbxml::SbXmlQUERY::SbXmlQUERY(QString sqlkey, QStringList argumentos) : QPDocumentoXML()
{
	QDomElement raiz = this->createElement( "QUERY" ); 
	this->appendChild( raiz );
	
	QDomElement sqlElement = this->createElement("sql");
	QDomText sqlText = this->createTextNode( sqlkey );
	sqlElement.appendChild(sqlText);
	raiz.appendChild(sqlElement);
	
	QDomElement paramElement = this->createElement("param");
	
	for(uint i = 0; i < argumentos.count(); i++)
	{
		QDomElement argElement = this->createElement("arg");
		QDomText argText = this->createTextNode( argumentos[i] );
		argElement.appendChild(argText);
		paramElement.appendChild(argElement);
	}
	
	raiz.appendChild(paramElement);
}

/**
 * Constructor
 * @param sqlkey
 * @param password
 * @param argumentos
 */
sbxml::SbXmlQUERY::SbXmlQUERY(QString sqlkey,QString password, QStringList argumentos)
{
	QDomElement raiz = this->createElement( "QUERY" ); 
	this->appendChild( raiz );
	
	QDomElement sqlElement = this->createElement("sql");
	QDomText sqlText = this->createTextNode( sqlkey );
	sqlElement.appendChild(sqlText);
	raiz.appendChild(sqlElement);

	QDomElement passwdElement = this->createElement("password");
	QDomText passwdText = this->createTextNode( password );
	passwdElement.appendChild(passwdText);
	raiz.appendChild(passwdElement);
			
	QDomElement paramElement = this->createElement("param");
	
	for(uint i = 0; i < argumentos.count(); i++)
	{
		QDomElement argElement = this->createElement("arg");
		QDomText argText = this->createTextNode( argumentos[i] );
		argElement.appendChild(argText);
		paramElement.appendChild(argElement);
	}
	
	raiz.appendChild(paramElement);	
}

/**
 * Destructor
 */
sbxml::SbXmlQUERY::~SbXmlQUERY()
{
}

