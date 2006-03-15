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

CPackageParser::CPackageParser() : QXmlDefaultHandler(), m_isParsing(false), m_readChar(false)
{
}


CPackageParser::~CPackageParser()
{
}

void CPackageParser::reset()
{
	m_root = QString();
	m_qname = QString();
	
	m_currentForms.clear();
}


bool CPackageParser::startElement( const QString& , const QString& , const QString& qname, const QXmlAttributes& atts)
{
	if (!m_isParsing)
	{
		reset();
		m_root = qname;
		
		m_isParsing = true;
	}
	else if ( m_root == "Error" )
	{
		if ( qname == "Id" )
		{
		}
		else if ( qname == "Message" )
		{
		}
	}
	else if ( m_root == "Success" )
	{
		if ( qname == "FormDef" )
		{
			m_readChar = true;
			
			FormData formData;
			formData.id = atts.value("id").toInt();
			
			m_currentForms << formData;
		}
		else if ( qname == "Module" )
		{
			m_currentModuleName = atts.value("name");
		}
		else if ( qname == "Message" )
		{
		}
	}
	
	m_qname = qname;
	return true;
}

bool CPackageParser::endElement(const QString&, const QString& , const QString& qname)
{
	if ( m_root == "Error" )
	{
	}
	else if ( m_root == "Success" )
	{
		if ( qname == "Module" )
		{
			m_moduleForms.insert(m_currentModuleName, m_currentForms);
		}
	}
	
	if ( qname == m_root )
	{
		m_isParsing = false;
	}
	
	return true;
}

bool CPackageParser::characters ( const QString & ch )
{
	if (m_readChar )
	{
		if ( m_root == "Success" )
		{
			if ( m_qname == "FormDef" )
			{
				// ch contiene el formulario
				m_currentForms.last().document = ch;
			}
		}
		
		m_readChar = false;
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

ModuleForms CPackageParser::moduleForms() const
{
	return m_moduleForms;
}


QString CPackageParser::root() const
{
	return m_root;
}

