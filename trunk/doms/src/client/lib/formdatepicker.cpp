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
#include "formdatepicker.h"

FormDatePicker::FormDatePicker() : DDatePicker(), FormWidgetIface()
{
}


FormDatePicker::~FormDatePicker()
{
}

void FormDatePicker::setFieldValue(const QVariant &v)
{
	setDate(v.toDate());
}

QString FormDatePicker::fieldValue() const
{
	return date().toString(Qt::ISODate);
}

bool FormDatePicker::isModified() const
{
	return true;
}

