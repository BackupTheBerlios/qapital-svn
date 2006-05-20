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
#include <QHeaderView>

#include <dtreewidgetsearchline.h>

#include "global.h"

CModuleWidget::CModuleWidget(const QString &moduleMame, QWidget *parent) : QWidget(parent)
{
	QVBoxLayout *layout = new QVBoxLayout(this);
	
	QHBoxLayout *search = new QHBoxLayout;
	
	QToolButton *button = new QToolButton;
	button->setIcon( QIcon(THEME_DIR+"/icons/clear_right.png"));
	
	
	search->addWidget(button);
	
	m_pTree = new DTreeListWidget;
	
	m_pSearch = new DTreeWidgetSearchLine(tr("Search here")+"...", this, m_pTree);
	search->addWidget( m_pSearch );
	
	m_pSearch->setSearchColumns(QList<int>() << 0 );
	
	layout->addLayout(search);
	
	layout->addWidget(m_pTree);
	
	
	connect(button, SIGNAL(clicked()), m_pSearch, SLOT(clear()));
}


CModuleWidget::~CModuleWidget()
{
}

CModuleButtonBar *CModuleWidget::addButtonBar(int flags)
{
	CModuleButtonBar *bar = new CModuleButtonBar(flags);
	boxLayout()->addWidget( bar );
	
	return bar;
}

QBoxLayout *CModuleWidget::boxLayout()
{
	return qobject_cast<QVBoxLayout *>(layout());
}

void CModuleWidget::setup(const ModuleInfo &module)
{
	// TODO: guardar los cambios de la BD
	
	QStringList headers;
	
	typedef QPair<QString, QString> StringPair;
	
	foreach(StringPair info, module.listInfo)
	{
		headers << info.first;
	}
	
	m_pTree->setHeaderLabels(headers);
	m_pTree->header()->show();
	
	m_moduleInfo = module;
}


