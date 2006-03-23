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

#include "fdesigner.h"

#include <QVBoxLayout>
#include <QHBoxLayout>

#include <QLabel>
#include <QWorkspace>
#include <QTextEdit>
#include <QFileDialog>
#include <QDomDocument>
#include <QMenuBar>

#include <ddebug.h>

FDesigner::FDesigner() : QMainWindow()
{
	QFrame *containter = new QFrame;
	m_mainLayout = new QVBoxLayout(containter);
	
	
	m_workspace = new QWorkspace;
	m_workspace->setScrollBarsEnabled ( true );
	m_mainLayout->addWidget(m_workspace);
	
	m_editor = new QTextEdit;
	m_mainLayout->addWidget(m_editor);
	
	connect(m_editor, SIGNAL(textChanged()), this, SLOT(analize()));
	
	setCentralWidget( containter );
	
	m_builder = new CFormBuilder;
	
	m_currentForm = new QMainWindow;
	m_workspace->addWindow(m_currentForm);
	
	setupMenu();
}


FDesigner::~FDesigner()
{
}

void FDesigner::setupMenu()
{
	QMenu *menu = menuBar()->addMenu(tr("File"));
	
	menu->addAction(tr("Open file..."), this, SLOT(openFile()));
	menu->addAction(tr("Quit"), this, SLOT(close()));
}

void FDesigner::analize()
{
	QString text = m_editor->toPlainText();
	
	QWidget *w = m_builder->form( text );
	
	if( w )
	{
		QWidget *central = m_currentForm->centralWidget();
		
		if( central ) delete central;
		
		m_currentForm->setCentralWidget( w );
		m_currentForm->setWindowTitle( m_builder->formTitle() );
		m_currentForm->adjustSize();
		
	}
}

void FDesigner::openFile()
{
	QString file = QFileDialog::getOpenFileName (this, tr("Choose a file"), QString(), "Forms (*.dfm)");
	
	openFile( file );
}

void FDesigner::openFile(const QString &file)
{
	QDomDocument doc;
	QFile f(file);
	
	if ( doc.setContent( &f ) )
	{
		f.reset();
		m_editor->setPlainText(QString::fromLocal8Bit(f.readAll().data()));
		f.close();
	}
	else
	{
		qWarning("Isn't a form");
	}
}






