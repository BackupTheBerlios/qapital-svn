/* Clase: SbXmlANSWER
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

#include "sbxmlanswer.h"

using sbxml::QPDocumentoXML;

sbxml::SbXmlANSWER::SbXmlANSWER(QStringList header, QStringList data)
 : QPDocumentoXML()
{
	QDomElement raiz = this->createElement( "ERROR" );
	this->appendChild( raiz );
	
	QDomElement headerElement = this->createElement("header");
	QDomElement rowElement = this->createElement("row");
	
	for (uint i = 0; i < header.count(); i+=2)
	{
		QDomElement colElement = this->createElement("col");
		colElement.setAttribute( "type", header[i+1] );
		QDomText colTxt = this->createTextNode(header[i]);
		colElement.appendChild(colTxt);
		rowElement.appendChild(colElement);	
	}
	
	headerElement.appendChild(rowElement);
	raiz.appendChild(headerElement);
	
	for (uint i = 0; i < data.count(); i++)
	{
		QDomElement row = this->createElement("row");
		
		for (uint j = 0; j < data.count() / header.count(); j++)
		{
			QDomElement col = this->createElement("col");
			QDomText colTxt = this->createTextNode(data[j]);
			row.appendChild(colTxt);
		}
		raiz.appendChild(row);
	}
}


sbxml::SbXmlANSWER::~SbXmlANSWER()
{
}


