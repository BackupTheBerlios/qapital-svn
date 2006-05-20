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

#include "cclientmodulewidget.h"
#include <QHeaderView>

CClientModuleWidget::CClientModuleWidget(const QString &title, QWidget *parent) : CModuleWidget(title, parent)
{
	setWindowIcon(QIcon(THEME_DIR+"/icons/users.png"));
	
	
	CModuleButtonBar *buttonBar = addButtonBar( CModuleButtonBar::Add | CModuleButtonBar::Del );
	
	connect(buttonBar, SIGNAL(buttonClicked( int )), this, SLOT(doAction(int)));
	
	m_pTree->setHeaderLabels(QStringList() << tr("Name")<<tr("Last name"));
	m_pTree->header()->show();
	
	// For testing purpose
	
	addPacient( "Pepito","Perez");
	addPacient( "David ","Cuadrado");
	addPacient( "Carlos ","Giraldo");
	addPacient(  "Jonathan"," Guzman");
	addPacient(  "Andres ","XLS");
	addPacient(  "Alguien"," mas");
	addPacient(  "Homero"," Simpson" );
}


CClientModuleWidget::~CClientModuleWidget()
{
}

void CClientModuleWidget::doAction(int buttonId)
{
	switch(buttonId)
	{
		case CModuleButtonBar::Add:
		{
			emit requestForm( "pct", 0);
		}
		break;
		case CModuleButtonBar::Del:
		{
			emit requestForm( "pct", 1);
		}
		break;
		case CModuleButtonBar::Query:
		{
			
		}
		break;
		case CModuleButtonBar::Modify:
		{
			
		}
		break;
	}
}

void CClientModuleWidget::addPacient(const QString &name, const QString &lastName)
{
	QTreeWidgetItem *item = new QTreeWidgetItem(m_pTree);
	item->setText(0, "ID");
	item->setText(1, name);
	item->setText(2, lastName);
}



