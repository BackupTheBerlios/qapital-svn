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
#include <ddatepicker.h>
#include <cmath>

#include <QtGui>
#include <QtSvg>

#include <dglobal.h>

#include "formwidgets.h"

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
		if ( qname == "Form" )
		{
			m_form->setWindowTitle(atts.value("title"));
			
			QStringList tables = atts.value("tables").split(' ');
			m_form->setTables(tables);
			
		}
		else if ( qname == "HBox" )
		{
			QWidget *hbox = new QWidget;
			m_widgets.last()->layout()->addWidget(hbox);
			
			QHBoxLayout *layout = new QHBoxLayout(hbox);
			
			m_widgets << hbox;
		}
		else if ( qname == "VBox" )
		{
			QWidget *vbox = new QWidget;

			m_widgets.last()->layout()->addWidget(vbox);
						
			QVBoxLayout *layout = new QVBoxLayout(vbox);
			
			m_widgets << vbox;
		}
		else if ( qname == "VGroupBox" )
		{
			QGroupBox *group = new QGroupBox(atts.value("title"));
			QVBoxLayout *layout = new QVBoxLayout(group);
			
			m_widgets.last()->layout()->addWidget(group);
			
			m_widgets << group;
			
		}
		else if ( qname == "HGroupBox" )
		{
			QGroupBox *group = new QGroupBox(atts.value("title"));
			QHBoxLayout *layout = new QHBoxLayout(group);
			
			m_widgets.last()->layout()->addWidget(group);
			
			m_widgets << group;
		}
		else if ( qname == "Label" )
		{
			QLabel *label = new QLabel( atts.value("text") /*,m_widgets.last()*/);

			m_widgets.last()->layout()->addWidget(label);
		}
		else if ( qname == "Input" )
		{
			QHBoxLayout *ly = new QHBoxLayout;
			ly->setMargin(0);
// 			ly->setSpacing(0);
			
			QBoxLayout *boxLayout = qobject_cast<QBoxLayout *>(m_widgets.last()->layout());
			if ( boxLayout )
			{
				boxLayout->addLayout(ly);
			}
			
			QString label = atts.value("label");
			QString type = atts.value("type");
			QString dbfield = atts.value("dbfield"); // FIXME
			
			if( type.isEmpty() || type == "text" )
			{
				ly->addWidget(new QLabel(label));
				
				FormLineEdit *lineEdit = new FormLineEdit;
				lineEdit->setFieldInfo( dbfield );
				
				ly->addWidget(lineEdit);
				
				m_form->addInput(lineEdit);
			}
			else if (type == "date" )
			{
				FormDateWidget *date = new FormDateWidget;
				ly->addWidget( date );
				
				date->setFieldInfo( dbfield );
				m_form->addInput(date );
			}
			else if ( type == "calendar" )
			{
				FormDatePicker *picker = new FormDatePicker;
				ly->addWidget(picker );
				
				picker->setFieldInfo( dbfield );
				m_form->addInput( picker );
			}
			else if ( type == "options" )
			{
				int orientation = atts.value("orientation", "0").toInt();
				
				FormButtonGroup *buttonGroup = 0;
				
				switch(orientation)
				{
					case 1:
					{
						buttonGroup = new FormButtonGroup(Qt::Horizontal);
					}
					default:
					{
						buttonGroup = new FormButtonGroup(Qt::Vertical);
					}
				}
				
				if ( !buttonGroup) return false;
				
				buttonGroup->setTitle( label );
				
				ly->addWidget( buttonGroup );
				
				buttonGroup->setFieldInfo( dbfield );
				
				m_form->addInput( buttonGroup );
				
				m_widgets << buttonGroup;
			}
		}
		else if ( qname == "Table" )
		{
			QTableWidget *table = new QTableWidget(atts.value("rows").toInt(), atts.value("columns").toInt()/*, m_widgets.last()*/);
			
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
			
			m_widgets.last()->layout()->addWidget(table);
		}
		else if ( qname == "Button" )
		{
			QPushButton *button = new QPushButton(atts.value("label"));

			m_widgets.last()->layout()->addWidget(button);
		}
		else if ( qname == "CheckBox" )
		{
			QCheckBox *checkbox = new QCheckBox(atts.value("label"));

			m_widgets.last()->layout()->addWidget(checkbox);

		}
		else if ( qname == "RadioButton" )
		{
			QRadioButton *button = new QRadioButton(atts.value("label"));
			
			if ( dynamic_cast<FormButtonGroup *>(m_widgets.last() ) )
			{
// 				dDebug() << atts.value("id", "NO TIENE");
				QString idStr = atts.value("id", "");
				if ( idStr.isEmpty() )
				{
					dError() << "Please set radio button id for button: "<< atts.value("label") ;
// 					return false;
				}
				
				int id = idStr.toInt();
				
				qobject_cast<FormButtonGroup *>(m_widgets.last())->addButton(button, id);
			}
			else
			{
				m_widgets.last()->layout()->addWidget(button);
			}
		}
		else if ( qname == "Image" )
		{
			int w = atts.value("width", "100" ).toInt();
			int h = atts.value("height", "100" ).toInt();
			
			QString fileName = atts.value("filename");
			
			if ( fileName.endsWith(".svg") )
			{
				QSvgWidget *svg = new QSvgWidget;
				
				QObject::connect(svg->renderer(), SIGNAL(repaintNeeded ()), svg, SLOT(update()));
				
				svg->load(REPOSITORY+"/"+fileName);
				
				m_widgets.last()->layout()->addWidget(svg);
				svg->resize(w, h); // FIXME
			}
		}
	}
	
	m_qname = qname;
	return true;
}

bool CFormBuilder::endElement(const QString&, const QString& , const QString& qname)
{
	if ( qname == "HBox" || qname == "VBox" || qname == "VGroupBox" || qname == "HGroupBox" )
	{
		m_widgets.takeLast();
	}
	else if (qname == "Input" )
	{
		if ( dynamic_cast<FormButtonGroup*>(m_widgets.last()))
		{
			m_widgets.takeLast();
		}
	}
	
	if ( qname == "Form" )
	{
		QHBoxLayout *buttons = new QHBoxLayout;
		
		QPushButton *ok = new QPushButton( QObject::tr("Ok") );
		buttons->addWidget( ok );
		
		QObject::connect(ok, SIGNAL(clicked()), m_form, SLOT(addButtonClicked()));
		
		QPushButton *cancel = new QPushButton( QObject::tr("Cancel") );
		buttons->addWidget( cancel );
		
		QObject::connect(cancel, SIGNAL(clicked()), m_form, SLOT(cancelButtonClicked()));
		
		qobject_cast<QBoxLayout*>(m_form->layout())->addLayout(buttons);
	}
	
	return true;
}

bool CFormBuilder::characters ( const QString & ch )
{
	if (m_readChar )
	{
		if ( m_root == "Form" )
		{
			if ( m_qname == "" )
			{
				m_charData = ch;
			}
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

CForm *CFormBuilder::form(const QString &document)
{
	m_form = new CForm;
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
		return 0;
	}
	
	m_form->debug();
	
	return m_form;
}
