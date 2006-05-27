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

#ifndef FORMWIDGETIFACE_H
#define FORMWIDGETIFACE_H

#include <QString>
#include <QStringList>
#include <QVariant>
#include <QVector>

#include "global.h"

/**
 * Interfaz para todos los widgets de entrada que pertenecen a un formulario, esta clase es util para tener una interfaz común respecto a los datos que retorna cada widget.
 * @author David Cuadrado <krawek@gmail.com>
*/

#define DEBUG_FORM 1

class FormWidgetIface
{
	public:
		FormWidgetIface();
		virtual ~FormWidgetIface();
		virtual void setFieldValue(const QVariant &data) = 0;
		virtual QString fieldValue() const = 0;
		
		void setFieldInfo(const QString &table_field );
		
		QVector<DBField> fields() const;
		DBField field() const;
		DBField foreignField() const;
		
		bool hasForeignKey() const;
		
		
	private:
		QVector<DBField> m_fields;
};

#endif
