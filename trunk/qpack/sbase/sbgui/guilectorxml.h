/* Clase: GUILectorXml
 * Autor: CetiSoft
 * Version: 0.0.1
 * Fecha de creacion: 18/6/2004
 * Fecha de modificacion:
 * Relacion con objetos:
 * Descripcion:
 *	Esta clase sirve para para manejar la lectura de XML's
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

#ifndef  GUILECTORXML_H
#define GUILECTORXML_H

#include <qxml.h>
#include <iostream>
#include <qstringlist.h>
#include <stdlib.h>

typedef QValueList<int> ListaDeEnteros;

namespace sbgui
{
/**
	@author CetiSoft
 */

	class GUILectorXml : public QXmlDefaultHandler
	{
		private:
			QString raiz, qName;
			QStringList listaDeTexto, listaDeBid, listaDeFunciones;
			bool leer;
			int numeroDeBotones, numeroDeMenus, menuActual, filas, columnas, mnid;
			ListaDeEnteros listaNumeroBotones, listaDeFilas, listaDeColumnas;
		
		public:
	    		GUILectorXml();
			bool startElement(const QString& ns, const QString& localname, const QString& qname, const QXmlAttributes& atts);
			bool endElement( const QString& ns, const QString& localname, const QString& qname);
			bool characters ( const QString & ch );
			bool parseContinue ();
			
			QStringList obtenerListaDeTexto() const;
			QStringList obtenerListaDeTexto(int mnid);
			QStringList obtenerListaDeFunciones(int mnid);
			
			int obtenerNumeroDeBotones(int mnid) const;
			int obtenerNumeroDeMenus() const;
			int obtenerFilas(int mnid) const;
			int obtenerColumnas(int mnid) const;
	};
}
#endif
