/* Clase: XMLInterprete
 * Autor: CetiSoft
 * Version: 0.0.1
 * Fecha de creacion: 10/07/2004
 * Fecha de modificacion:
 * Relacion con objetos:
 * Descripcion: 
 *	Este modulo sirve para trabajar con archivos XML, permite leer y hacer XMLs de forma sencilla.
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

#ifndef SBXMLINTERPRETE_H
#define SBXMLINTERPRETE_H

#include <qdom.h>
#include <iostream>
#include <qxml.h>
#include <qiodevice.h> 
#include <qstring.h>
#include <qobject.h>


/**
Este modulo sirve para trabajar con archivos XML, permite leer y hacer XMLs de forma sencilla.
@author CetiSoft
*/

namespace sbxml
{
	class SbXmlInterprete
	{
		private:
			QDomDocument xmlDocumento;
			QString *errorMsg;
			QString xmlTagRaiz;
			int *lineaError;
			
			QDomElement xmlElemento;
		public:
			SbXmlInterprete(QString);
			SbXmlInterprete(QIODevice *);
	
			virtual ~SbXmlInterprete();
			
			void ponerDocumento(QString);
			virtual QString xmlObtenerTexto(QString tag);
			QString xmlRaiz();
			
	};
}
#endif
