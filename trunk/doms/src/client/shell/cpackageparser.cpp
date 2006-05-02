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
	m_resources.clear();
	m_values.clear();
}


bool CPackageParser::startElement( const QString& , const QString& , const QString& qname, const QXmlAttributes& atts)
{
	if (!m_isParsing)
	{
		reset();
		m_root = qname;
		
		m_isParsing = true;
	}
	else if( m_root == "Chat" )
	{
		if ( qname == "Message" )
		{
			QString login = atts.value("login");
			QString msg = atts.value("value");
			
			m_values.insert("login", login);
			m_values.insert("message", msg);
		}
	}
	else if ( m_root == "Error" )
	{
		if ( qname == "Id" )
		{
			m_values.insert("id", atts.value("value"));
		}
		else if ( qname == "Message" )
		{
			m_values.insert("message", atts.value("value"));
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
			m_currentModule.key = atts.value("key");
			m_currentModule.text = atts.value("text");
		}
		else if ( qname == "Message" )
		{
		}
	}
	else if ( m_root == "Resources" )
	{
		if ( qname == "Svg" )
		{
			QString fileName = atts.value("filename");
			
			m_resources.append(qMakePair(fileName, QString("")));
			
			m_readChar = true;
		}
		else if ( qname == "Image" )
		{
		}
		else if (qname == "Sound" )
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
			m_moduleForms.insert(m_currentModule, m_currentForms);
		}
	}
	else if ( m_root == "Resources" )
	{
		if ( !m_resources.isEmpty() )
		{
			QFile rsc(REPOSITORY+"/"+m_resources.last().first );
			
			if( rsc.open( QIODevice::WriteOnly ) ) // FIXME: Images and sound must be binary
			{
				QTextStream out(&rsc);
				out << m_resources.last().second << endl;
				rsc.close();
			}
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
		else if ( m_root == "Resources" )
		{
			if ( m_qname == "Svg" )
			{
				m_resources.last().second = ch;
				
				m_readChar = true;
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

XMLResults CPackageParser::results() const
{
	return m_values;
}

