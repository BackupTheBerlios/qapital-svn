/***************************************************************************
 *   Copyright (C) 2004 by David Alejandro Cuadrado Cabrera                *
 *   krawek@linuxmail.org                                                        *
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
#include "guimdixmlparser.h"

/**
Contructor por defecto
 */
sbgui::GUIMdiXMLParser::GUIMdiXMLParser() : QXmlDefaultHandler(), leer(false)
{
}

/**
Destructor 
 */
sbgui::GUIMdiXMLParser::~GUIMdiXMLParser()
{
}

/**
Lee los tags de inicio
 */
bool sbgui::GUIMdiXMLParser::startElement ( const QString &, const QString &, const QString& qName, const QXmlAttributes & atts)
{
	tag = qName;
	if (qName == "Menu")
	{
		menuName = atts.value("nombre");
		names << menuName;
		leer = true;
	}
	else if (qName == "Action")
	{
		menuInfo << atts.value("nombre");
		menuInfo << atts.value("icono");
		menuInfo << atts.value("tooltip");
	}
	return true;
}

/**
Se encarga de ver si el tag de cierre es el ultimo del xml, si es asi lipia menuInfo
 */
bool sbgui::GUIMdiXMLParser::endElement (const QString &, const QString & , const QString& qName)
{
	if (qName == "Menu")
	{
		QStringList *listTmp = new QStringList(menuInfo);
		menus.insert(menuName, listTmp);
		menuInfo.clear();
		menuName = "";
	}
	return true;
}

/**
Lee seccion de texto de los tags
 */
bool sbgui::GUIMdiXMLParser::characters ( const QString & ch )
{
	if (tag == "texto" && leer)
	{
		leer = false;
	}
	return true;
}

/**
Retorna un HashMenu (menus).
 */
HashMenu sbgui::GUIMdiXMLParser::obtenerMenus()
{
	return menus;
}

/**
Retorna un QStringList (names).
 */
QStringList sbgui::GUIMdiXMLParser::obtenerNombres()
{
	return names;
}
