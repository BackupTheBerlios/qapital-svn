/* Clase: SbXmlACP
 * Autor: CetiSoft
 * Version: 0.0.1
 * Fecha de creacion: 27/08/2004
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

#include "sbxmlacp.h"

SbXmlACP::SbXmlACP(QStringList drivers, QStringList sqls) : QPDocumentoXML()
{
	QDomElement raiz = this->createElement( "ACP" );
	this->appendChild( raiz );
	
	QDomElement transaction = this->createElement("transaction");
	
	for (uint i = 0; i < drivers.count(); i+= 2)
	{
		QDomElement drv = this->createElement("driver");
		drv.setAttribute( "authentication", drivers[i+1] );
		QDomText driverTxt = this->createTextNode(drivers[i]);
		drv.appendChild(driverTxt);
		transaction.appendChild(drv);
	}
	raiz.appendChild( transaction );
	
	QDomElement query = this->createElement("query");
	raiz.appendChild( query );	
	
	for (uint i = 0; i < sqls.count(); i+= 2)
	{
		QDomElement sql = this->createElement("driver");
		sql.setAttribute( "authentication", sqls[i+1] );
		QDomText sqlTxt = this->createTextNode(sqls[i]);
		sql.appendChild(sqlTxt);
		query.appendChild(sql);
	}
	raiz.appendChild( query );	
	
}


SbXmlACP::~SbXmlACP()
{
}


