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

#include "cpackageparser.h"

#include <ddebug.h>

CPackageParser::CPackageParser() : QXmlDefaultHandler()
{
}


CPackageParser::~CPackageParser()
{
}

void CPackageParser::reset()
{
	m_root = QString();
	m_qname = QString();
}


bool CPackageParser::startElement( const QString& , const QString& , const QString& qname, const QXmlAttributes& atts)
{
	dDebug() << qname;
	if (!m_isParsing)
	{
		reset();
		m_root = qname;
		
		m_isParsing = true;
	}
	else if ( m_root == "Success" )
	{
	}
	
	m_qname = qname;
	return true;
}

bool CPackageParser::endElement(const QString&, const QString& , const QString& qname)
{
	if ( m_root == "Success" )
	{
	}
	
	if ( qname == m_root )
	{
		m_isParsing = false;
	}
	
	return true;
}

bool CPackageParser::error ( const QXmlParseException & exception )
{
	dError() << exception.lineNumber() << "x" << exception.columnNumber() << ": " << exception.message();
	
	return true;
}


bool CPackageParser::fatalError ( const QXmlParseException & exception )
{
	dFatal() << exception.lineNumber() << "x" << exception.columnNumber() << ": " << exception.message();
	
	return true;
}
