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

#include "ftoolmanager.h"

#include <QInputDialog>
#include <QIcon>
#include <QTextDocument>

#define ATT(a) QString("\"%1\"").arg(a)

#define GET_TEXT Qt::escape(QInputDialog::getText( 0, tr("Text..."), tr("Write the label text")))

FToolManager::FToolManager(QMainWindow *window) : QToolBar(window)
{
	Q_INIT_RESOURCE(icons);
	
	QAction *addLabel = addAction(QIcon(":/res/icons/add_label.png"),tr("Add label"),this, SLOT(addLabel()));
	
	QAction *addButton = addAction(QIcon(":/res/icons/add_button.png"),tr("Add button"),this, SLOT(addButton()));
	
	QAction *addCheckBox = addAction(QIcon(":/res/icons/add_checkbox.png"),tr("Add check box"),this, SLOT(addCheckBox()));
	
	QAction *addVBox = addAction(QIcon(":/res/icons/add_vbox.png"),tr("Add vertical box"),this, SLOT(addVBox()));
	
	QAction *addHBox = addAction(QIcon(":/res/icons/add_hbox.png"),tr("Add horizontal box"),this, SLOT(addHBox()));
	
	QAction *addVBoxGroup = addAction(QIcon(":/res/icons/add_vgroupbox.png"),tr("Add vertical group box"),this, SLOT(addVBoxGroup()));
	
	QAction *addHBoxGroup = addAction(QIcon(":/res/icons/add_hgroupbox.png"),tr("Add horizontal group box"),this, SLOT(addHBoxGroup()));
	
	window->addToolBar( Qt::TopToolBarArea, this);
}


FToolManager::~FToolManager()
{
}

void FToolManager::addLabel()
{
	QString text = GET_TEXT;
	
	emit appendObject( "<Label text="+ATT(text)+" />\n" );
}

void FToolManager::addButton()
{
	QString text = GET_TEXT;
	
	emit appendObject( "<Button label="+ATT(text)+" />\n" );
}

void FToolManager::addCheckBox()
{
	QString text = GET_TEXT;
	
	emit appendObject( "<CheckBox label="+ATT(text)+" />\n" );
}

void FToolManager::addVBox()
{
	emit appendObject( "<VBox>\n\n</VBox>" );
}

void FToolManager::addHBox()
{
	emit appendObject( "<HBox>\n\n</HBox>" );
}

void FToolManager::addVBoxGroup()
{
	emit appendObject( "<VGroupBox>\n\n</VGroupBox>" );
}

void FToolManager::addHBoxGroup()
{
	emit appendObject( "<HGroupBox>\n\n</HGroupBox>" );
}




