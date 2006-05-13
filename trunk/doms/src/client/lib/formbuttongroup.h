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
#ifndef FORMBUTTONGROUP_H
#define FORMBUTTONGROUP_H

#include <qgroupbox.h>
#include <formwidgetiface.h>

#include <QButtonGroup>

class QAbstractButton;

/**
 * @author David Cuadrado <krawek@gmail.com>
*/

class FormButtonGroup : public QGroupBox, public FormWidgetIface
{
	public:
		FormButtonGroup(Qt::Orientation o = Qt::Vertical);
		~FormButtonGroup();
		
		void setFieldValue(const QVariant &v);
		QString fieldValue() const;
		
		void addButton(QAbstractButton *button, int id);
		
	private:
		QButtonGroup *m_buttonGroup;
};

#endif
