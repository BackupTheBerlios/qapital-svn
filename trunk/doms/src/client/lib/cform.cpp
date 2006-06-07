/***************************************************************************
 *   Copyright (C) 2006 by David Cuadrado                                  *
 *   krawek@gmail.com                                                       *
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

#include "cform.h"

#include <ddebug.h>

#include <QHBoxLayout>
#include <QPushButton>

#include "global.h"

CForm::CForm() : QWidget()
{
}


CForm::~CForm()
{
	DEND;
}

void CForm::addInput(FormWidgetIface *input)
{
	D_FUNCINFO;
	if ( input )
	{
		foreach(DBField field, input->fields() )
		{
			if ( !m_inputMap.contains( field.table ) )
			{
				m_inputMap.insert(field.table, QList<FormWidgetIface *>() << input );
			}
			else
			{
				m_inputMap[field.table] << input;
			}
		}
	}
}

void CForm::debug()
{
#if 0
	dDebug() << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<";
	for(int i = 0; i < m_inputMap.count(); i++)
	{
		QString table = m_inputMap.keys()[i];
		
		dDebug() << "----- Table " << table << " -----";
		QList<FormWidgetIface*> fields = m_inputMap[table];
		for(int j = 0; j < fields.count(); j++)
		{
			dDebug() << "#### Field: " << fields[j]->field();
		}
	}
	dDebug() << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<";
#endif
}

#define MASS_OPERATION 0

void CForm::addButtonClicked()
{
	D_FUNCINFO;
	
#if MASS_OPERATION
	QList<QStringList> fieldsList, valuesList;
#endif

	QString keyField;
	
	
	foreach(QString table, m_tables)
	{
		QList<FormWidgetIface*> formInputs = m_inputMap[table];
		
		QStringList fields, values;
		foreach(FormWidgetIface *formWidgetInput, formInputs)
		{
			// Falla si el nombre de la fk y pk son diferentes?
			QString fieldName = formWidgetInput->fields()[0].name; // FIXME: this sucks
			
			if ( formWidgetInput->fields().count() == 2 )
			{
				keyField = fieldName;
			}
			
			fields << fieldName;
			values << formWidgetInput->fieldValue();
		}
#if MASS_OPERATION
		fieldsList << fields;
		valuesList << values;
#else
		if ( fields.isEmpty() ) continue;
		
		if ( m_keyValue.isEmpty() )
		{
			CInsertPackage insert(table, fields, values);
			emit requestOperation( this, &insert );
		}
		else
		{
			CUpdatePackage update(table, fields, values);
			update.setWhere(keyField+"="+m_keyValue);
			emit requestOperation( this, &update);
		}
#endif
	}
	
#if MASS_OPERATION
	if ( m_keyValue.isEmpty() )
	{
		CInsertPackage insert(m_tables, fieldsList, valuesList);
		emit requestOperation( this, &insert );
	}
	else
	{
		CUpdatePackage update(m_tables, fieldsList, valuesList);
		update.setWhere(keyField+"="+m_keyValue);
		emit requestOperation( this, &update);
	}
#endif
}

void CForm::cancelButtonClicked()
{
	D_FUNCINFO;
	emit close();
}

void CForm::resetButtonClicked()
{
	D_FUNCINFO;
	
}


void CForm::setTables(const QStringList &tables)
{
	m_tables = tables;
}

void CForm::setOperationResult(const QList<XMLResults> &results)
{
	// TODO: llenar el formulario con los valores que llegan aqui!
	
	foreach ( XMLResults result, results)
	{
		foreach(QString table, m_tables) // Maximo 3 iteraciones
		{
			QList<FormWidgetIface*> formInputs = m_inputMap[table];
			foreach(FormWidgetIface *formWidgetInput, formInputs) // No mas de 20
			{
				foreach(DBField field, formWidgetInput->fields() ) // Maximo 2 iteraciones
				{
					SHOW_VAR(field.name);
					SHOW_VAR(result.keys());
					if ( result.contains(field.name) )
					{
						formWidgetInput->setFieldValue(result[field.name] );
						break;
					}
				}
			}
		}
	}
}

void CForm::setup(const QString &key)
{
	D_FUNCINFO << key;
	if ( key.isEmpty() ) return;
	
	m_keyValue = key;
	
	if ( m_ok )
	{
		m_ok->setText(tr("Modify"));
	}
	
	QStringList attributes;
	QString where;
	
	foreach(QString table, m_tables)
	{
		QList<FormWidgetIface*> formInputs = m_inputMap[table];
		
		foreach(FormWidgetIface *formWidgetInput, formInputs)
		{
			QString fieldName = TABLE_DOT_ATT(formWidgetInput->fields()[0]);
			
			if ( formWidgetInput->fields().count() == 2 )
			{
				where = fieldName + "=" + m_keyValue;
			}
			
			attributes << fieldName;
		}
	}
	
	// Llenamos la lista!
	CSelectPackage select(m_tables, attributes);
	if ( !where.isEmpty() )
	{
		select.setWhere( where);
	}
	
	emit requestOperation( this, &select);
}

void CForm::addButtons()
{
	QHBoxLayout *buttons = new QHBoxLayout;
		
	m_ok = new QPushButton( tr("Ok") );
	buttons->addWidget( m_ok );
		
	connect(m_ok, SIGNAL(clicked()), this, SLOT(addButtonClicked()));
		
	m_cancel = new QPushButton( tr("Cancel") );
	buttons->addWidget( m_cancel );
		
	connect(m_cancel, SIGNAL(clicked()), this, SLOT(cancelButtonClicked()));
		
	qobject_cast<QBoxLayout*>(layout())->addLayout(buttons);
}

void CForm::setModuleName(const QString &mname)
{
	m_moduleName = mname;
}

QString CForm::moduleName() const
{
	return m_moduleName;
}

QString CForm::id() const
{
	return m_moduleName;
}

