/***************************************************************************
 *   Copyright (C) 2004 by David Alejandro Cuadrado Cabrera                *
 *   krawek@linuxmail.org                                                         *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/
 
#ifndef XMLPARSER_H
#define XMLPARSER_H

#include <qxml.h>
#include <qstring.h>
#include <qstringlist.h>
#include <qdict.h>
#include <iostream>

typedef QDict<QStringList> HashMenu;
/**
 * @fn typedef HashMenu
 * Esta definicion contiene los menus
 */

/**
 * @short Esta clase interpreta el XML para crear toolbars, esta clase hace parte del motor de GUI.
 * @b NOTA: Esta funcion hace parte del motor de creacion de GUI en base a XML
 * @author CetiSoft
*/

class GUIMdiXMLParser : public QXmlDefaultHandler
{
	private:
		QString tag;
		QString menuName;
		QStringList names;
		HashMenu menus;
		QStringList menuInfo;
		bool leer;
		
	public:
    		GUIMdiXMLParser();
		~GUIMdiXMLParser();
		bool startElement ( const QString & , const QString & , const QString& qName, const QXmlAttributes & atts );
		bool endElement ( const QString & , const QString & , const QString& qName );
		bool characters ( const QString & ch );
		
		HashMenu obtenerMenus();
		QStringList obtenerNombres();
};

#endif
