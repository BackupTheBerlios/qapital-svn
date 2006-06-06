/***************************************************************************
 *   Copyright (C) 2006 by David Cuadrado                                  *
 *   krawek@gmail.com                                                      *
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


#ifndef CFORMBUILDER_H
#define CFORMBUILDER_H

#include <QXmlDefaultHandler>

#include "cform.h"

/**
 * Esta clase se encarga de analizar el lenguaje de formularios, se podria entender esta clase como un compilador o interprete.
 * @author David Cuadrado \<krawek@gmail.com\>
*/
class CFormBuilder : public QXmlDefaultHandler
{
	public:
		CFormBuilder();
		~CFormBuilder();
		
		bool startElement(const QString& , const QString& , const QString& qname, const QXmlAttributes& atts);
		
		bool endElement( const QString& ns, const QString& localname, const QString& qname);
		
		bool characters ( const QString & ch );
		
		bool error ( const QXmlParseException & exception );
		bool fatalError ( const QXmlParseException & exception );
		
		CForm *form(const QString &document);
		
	private:
		QString m_root, m_qname;
		
		bool m_readChar;
		
		QWidgetList m_widgets;
		
		CForm *m_form;
		
		QString m_charData;
};

#endif
