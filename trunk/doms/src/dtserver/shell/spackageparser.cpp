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

#include "spackageparser.h"

#include <ddebug.h>

SPackageParser::SPackageParser() : QXmlDefaultHandler(), m_isParsing(false)
{
}


SPackageParser::~SPackageParser()
{
}

void SPackageParser::reset()
{
	m_root = QString();
	m_qname = QString();
	m_values.clear();
}

bool SPackageParser::startElement( const QString& , const QString& , const QString& qname, const QXmlAttributes& atts)
{
	dDebug() << qname;
	if (!m_isParsing)
	{
		reset();
		m_root = qname;
		
		m_isParsing = true;
	}
	else if ( m_root == "Connection" )
	{
		if ( qname == "Login" )
		{
			m_values[qname] = atts.value("value");
		}
		else if ( qname == "Password")
		{
			m_values[qname] = atts.value("value");
		}
	}
	else if ( m_root == "Chat" )
	{
		if ( qname == "Message" )
		{
			m_values[qname] = atts.value("value");
		}
	}
	else
	{
		return false;
	}
	
	m_qname = qname;
	return true;
}

bool SPackageParser::endElement(const QString&, const QString& , const QString& qname)
{
	if( qname == "Connection" )
	{
	}
	
	if ( qname == m_root )
	{
		m_isParsing = false;
	}
	
	return true;
}

bool SPackageParser::error ( const QXmlParseException & exception )
{
	dError() << exception.lineNumber() << "x" << exception.columnNumber() << ": " << exception.message();
	
	return true;
}


bool SPackageParser::fatalError ( const QXmlParseException & exception )
{
	dFatal() << exception.lineNumber() << "x" << exception.columnNumber() << ": " << exception.message();
	
	return true;
}

QString SPackageParser::root() const
{
	return m_root;
}

QMap<QString, QString> SPackageParser::values() const
{
	return m_values;
}
