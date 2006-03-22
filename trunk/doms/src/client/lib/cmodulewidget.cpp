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


#include "cmodulewidget.h"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QToolButton>

#include <dclicklineedit.h>

#include "global.h"

CModuleWidget::CModuleWidget(const QString &moduleMame, QWidget *parent) : QWidget(parent)
{
	QVBoxLayout *layout = new QVBoxLayout(this);
	
	QHBoxLayout *search = new QHBoxLayout;
	
	QToolButton *button = new QToolButton;
	button->setIcon( QIcon(THEME_DIR+"/icons/clear_right.png"));
	
	
	search->addWidget(button);
	
	m_pSearch = new DClickLineEdit(tr("Search here")+"...");
	search->addWidget( m_pSearch );
	
	layout->addLayout(search);
	
	m_pTree = new DTreeListWidget;
	
	layout->addWidget(m_pTree);
	
	
	connect(button, SIGNAL(clicked()), m_pSearch, SLOT(clear()));
}


CModuleWidget::~CModuleWidget()
{
}

QBoxLayout *CModuleWidget::boxLayout()
{
	return qobject_cast<QVBoxLayout *>(layout());
}

