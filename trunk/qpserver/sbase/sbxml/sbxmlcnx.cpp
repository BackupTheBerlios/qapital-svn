/* Clase: SbXmlCNX
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

#include "sbxmlcnx.h"

using sbxml::QPDocumentoXML;

/**
Constructor
@param qpusuario: Usuario del ST
@param qpspassword: Password de qpusuario
*/
sbxml::SbXmlCNX::SbXmlCNX(QString db, QString qpsusuario, QString qpspassword) : QPDocumentoXML()
{
	QDomElement raiz = this->createElement( "CNX" ); // Se crea la raiz
	this->appendChild( raiz ); // se añade la raíz al árbol

	QDomElement databaseElement = this->createElement( "db" );
	QDomText dbText = this->createTextNode( db );
	databaseElement.appendChild(dbText);
	raiz.appendChild(databaseElement);
		
	QDomElement username = this->createElement("login");
	QDomText login = this->createTextNode( qpsusuario );
	username.appendChild(login);
	raiz.appendChild(username);

	QDomElement pass = this->createElement("password");
	QDomText dompass = this->createTextNode(qpspassword);
	pass.appendChild(dompass);
	raiz.appendChild(pass);	
}

/**
Destructor
*/
sbxml::SbXmlCNX::~SbXmlCNX()
{
}

