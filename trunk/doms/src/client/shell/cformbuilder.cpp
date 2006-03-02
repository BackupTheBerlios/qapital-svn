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

#include "cformbuilder.h"

#include <ddebug.h>

#include <QtGui>

CFormBuilder::CFormBuilder() : QXmlDefaultHandler(), m_readChar(false), m_form(0)
{
}

CFormBuilder::~CFormBuilder()
{
}

bool CFormBuilder::startElement( const QString& , const QString& , const QString& qname, const QXmlAttributes& atts)
{
	if( m_root.isEmpty() )
	{
		m_root = qname;
	}
	
	if ( m_root == "Form" )
	{
		if ( qname == "HBox" )
		{
			QWidget *hbox = new QWidget(m_widgets.last());
			
			if( m_widgets.last()->layout() )
			{
				m_widgets.last()->layout()->addWidget(hbox);
			}
			
			QHBoxLayout *layout = new QHBoxLayout(hbox);
			
			m_widgets << hbox;
		}
		else if ( qname == "VBox" )
		{
			QWidget *vbox = new QWidget(m_widgets.last());
			
			if( m_widgets.last()->layout() )
			{
				m_widgets.last()->layout()->addWidget(vbox);
			}
			
			QVBoxLayout *layout = new QVBoxLayout(vbox);
			
			m_widgets << vbox;
		}
		else if ( qname == "Label" )
		{
			QLabel *label = new QLabel( atts.value("text") ,m_widgets.last());
			
			if ( m_widgets.last()->layout() )
			{
				m_widgets.last()->layout()->addWidget(label);
			}
		}
		else if ( qname == "Input" )
		{
			QHBoxLayout *ly = new QHBoxLayout(m_widgets.last());
			
			ly->addWidget(new QLabel(atts.value("label")));
			ly->addWidget(new QLineEdit);
			
			QBoxLayout *boxLayout = qobject_cast<QBoxLayout *>(m_widgets.last()->layout());
			if ( boxLayout )
			{
				boxLayout->addLayout(ly);
			}
			
		}
		else if ( qname == "Table" )
		{
			QTableWidget *table = new QTableWidget(atts.value("rows").toInt(), atts.value("columns").toInt(), m_widgets.last());
			
			QStringList headers = atts.value("vheaders").split(";");
			if ( headers.count() > 1 )
			{
				table->setVerticalHeaderLabels (headers);
			}
			
			headers = atts.value("hheaders").split(";");
			if ( !headers.isEmpty() )
			{
				table->setHorizontalHeaderLabels (headers);
			}
			
			if ( m_widgets.last()->layout() )
			{
				m_widgets.last()->layout()->addWidget(table);
			}
		}
	}
	
	m_qname = qname;
	return true;
}

bool CFormBuilder::endElement(const QString&, const QString& , const QString& qname)
{
	if ( qname == "HBox" || qname == "VBox" )
	{
		m_widgets.takeLast();
	}
	else if ( qname == "" )
	{
	}
	
	return true;
}

bool CFormBuilder::characters ( const QString & ch )
{
	if (m_readChar )
	{
		if ( m_root == "" )
		{
		}
		
		m_readChar = false;
	}
	
	return true;
}

bool CFormBuilder::error ( const QXmlParseException & exception )
{
	dError() << exception.lineNumber() << "x" << exception.columnNumber() << ": " << exception.message();
	
	return true;
}


bool CFormBuilder::fatalError ( const QXmlParseException & exception )
{
	dFatal() << exception.lineNumber() << "x" << exception.columnNumber() << ": " << exception.message();
	
	return true;
}

QWidget *CFormBuilder::form(const QString &document)
{
	m_form = new QWidget;
	QVBoxLayout *layout = new QVBoxLayout(m_form);
	
	m_widgets << m_form;
	
	QXmlInputSource xmlsource;
	xmlsource.setData(document);
	
	QXmlSimpleReader m_reader;
	m_reader.setContentHandler(this);
	m_reader.setErrorHandler(this);
	
	if ( !m_reader.parse(&xmlsource) )
	{
		dError() << "Error while try to parse form document";
	}
	
	return m_form;
}


