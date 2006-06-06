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

#include "formbuttongroup.h"

#include <QAbstractButton>
#include <QBoxLayout>

FormButtonGroup::FormButtonGroup(Qt::Orientation o)
 : QGroupBox(), FormWidgetIface()
{
	m_buttonGroup = new QButtonGroup(this);
	
	switch(o)
	{
		case Qt::Horizontal:
		{
			new QBoxLayout(QBoxLayout::LeftToRight, this);
		}
		break;
		default:
		{
			new QBoxLayout(QBoxLayout::TopToBottom, this);
		}
		break;
	}
}


FormButtonGroup::~FormButtonGroup()
{
}

void FormButtonGroup::setFieldValue(const QVariant &v)
{
	int id = v.toInt();
	
	QAbstractButton *button = m_buttonGroup->button(id);
	
	if (button)
	{
		button->setChecked(true);
	}
}

QString FormButtonGroup::fieldValue() const
{
	return QString::number(m_buttonGroup->checkedId());
}

void FormButtonGroup::addButton(QAbstractButton *button, int id)
{
	layout()->addWidget(button);
	m_buttonGroup->addButton(button, id);
}

bool FormButtonGroup::isModified() const
{
	return true;
}

