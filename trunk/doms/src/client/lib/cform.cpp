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
	dDebug() << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<";
// 	for(int i = 0; i < m_inputMap.count(); i++)
// 	{
// 		QString table = m_inputMap.keys()[i];
// 		
// 		dDebug() << "----- Table " << table << " -----";
// 		QList<FormWidgetIface*> fields = m_inputMap[table];
// 		for(int j = 0; j < fields.count(); j++)
// 		{
// 			dDebug() << "#### Field: " << fields[j]->field();
// 		}
// 	}
	dDebug() << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<";
}


void CForm::addButtonClicked()
{
	D_FUNCINFO;
	
	foreach(QString table, m_tables)
	{
		QList<FormWidgetIface*> formInputs = m_inputMap[table];
		
		QStringList fields, values;
		foreach(FormWidgetIface *formWidgetInput, formInputs)
		{
			fields << formWidgetInput->fields()[0].name; // FIXME: this sucks
			values << formWidgetInput->fieldValue();
		}
		
		CInsertPackage insert(table, fields, values);
		
		emit requestOperation( this, &insert );
	}
}

void CForm::cancelButtonClicked()
{
	D_FUNCINFO;
	
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
	SHOW_VAR(results.count());
	foreach(XMLResults result, results)
	{
		QHash<QString, QString>::const_iterator i = result.constBegin();
		while (i != result.constEnd()) 
		{
			dDebug() << i.key() << ": " << i.value() << endl;
			++i;
		}
	}
}
