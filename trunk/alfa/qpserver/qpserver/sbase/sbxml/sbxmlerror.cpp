/* Clase: SbXMLError
 * Autor: CetiSoft
 * Version: 0.0.1
 * Fecha de creacion: 11/08/2004
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

#include "sbxmlerror.h"

/**
Constructor
@param codigoDeError: Codigo de error enviado al nodo.
@param mensajeDeError: Mensaje asociado al codigo de error.
*/
SbXMLError::SbXMLError(QString codigoDeError, QString mensajeDeError) : QPDocumentoXML(), codigoDeError(codigoDeError), mensajeDeError(mensajeDeError)
{	
	QDomElement raiz = this->createElement( "ERROR" );
	this->appendChild( raiz );
	
	QDomElement errorCode = this->createElement("errorCode");
	QDomText codigoTxt = this->createTextNode(codigoDeError);
	errorCode.appendChild(codigoTxt);
	raiz.appendChild(errorCode);
	
	QDomElement errorMsg = this->createElement("errorMsg");
	QDomText  mensajeTxt = this->createTextNode(mensajeDeError);
	errorMsg.appendChild(mensajeTxt);
	raiz.appendChild(errorMsg);
}

/**
Destructor
*/
SbXMLError::~SbXMLError()
{
}

/**
Retorna el codigo de error
*/
QString SbXMLError::errorCode()
{
	return codigoDeError;
}

/**
Retorna el mensaje de error
*/
QString SbXMLError::errorMsg()
{
	return mensajeDeError;
}


