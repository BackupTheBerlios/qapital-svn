/* Clase: SbXMLError
 * Autor: CetiSoft
 * Version: 0.0.1
 * Fecha de creacion: 11/08/2004
 * Fecha de modificacion:
 * Relacion con objetos:
 * Descripcion: 
 *	Esta clase representa el documento XML de error
 *	<ERROR>
 *  		<errorCode>codigo_de_error</errorCode>
 * 		<errorMsg>Mensaje de error</errorMsg>
 *	</ERROR>
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

#ifndef SBXMLERROR_H
#define SBXMLERROR_H

#include <qdom.h>
#include <qstring.h>
#include "qpdocumentoxml.h"

/**
 * Esta clase representa el documento XML de error
 * @author CetiSoft
*/
namespace sbxml
{
	class SbXMLError : public QPDocumentoXML
	{
		private:
			QString codigoDeError;
			QString mensajeDeError;
	
		public:
			SbXMLError(QString codigoDeError, QString mensajeDeError);
			~SbXMLError();
			QString errorCode();
			QString errorMsg();
	
	};
}
#endif
