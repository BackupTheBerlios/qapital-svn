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

#include "formwidgetiface.h"
#include <ddebug.h>

#include <cattributeparser.h>

FormWidgetIface::FormWidgetIface()
{
}


FormWidgetIface::~FormWidgetIface()
{
}

void FormWidgetIface::setFieldInfo(const QString &table_field )
{
	if ( table_field.contains("->") )
	{
		QPair<DBField, DBField> fields = CAttributeParser::parseFKField( table_field );
		m_fields << fields.first; m_fields << fields.second;
	}
	else
	{
		m_fields << CAttributeParser::parseField( table_field );
	}
}

QVector<DBField> FormWidgetIface::fields() const
{
	return m_fields;
}

bool FormWidgetIface::hasForeignKey() const
{
	return m_fields.count() == 2;
}

DBField FormWidgetIface::field() const
{
	return m_fields[0];
}

DBField FormWidgetIface::foreignField() const
{
	if ( !hasForeignKey())
	{
		return DBField();
	}
	return m_fields[1];
}
