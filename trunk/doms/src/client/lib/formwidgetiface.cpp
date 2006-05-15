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

FormWidgetIface::FormWidgetIface()
{
}


FormWidgetIface::~FormWidgetIface()
{
}

void FormWidgetIface::setFieldInfo(const QString &table_field )
{
	QStringList tafs = table_field.split("->");
	
	foreach(QString field, tafs )
	{
		QStringList table_and_field = field.split(':');
		
		if ( table_and_field.count() != 2 ) continue;
		TableField field;
		field.table = table_and_field[0];
		field.field = table_and_field[1];
		
		m_fields << field;
	}
}

QList<FormWidgetIface::TableField> FormWidgetIface::fields() const
{
	return m_fields;
}

