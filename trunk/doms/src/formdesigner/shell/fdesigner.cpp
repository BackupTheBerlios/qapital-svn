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
#include <QTimer>

#include <ddebug.h>

FDesigner::FDesigner() : QMainWindow()
{
	QFrame *containter = new QFrame;
	m_mainLayout = new QHBoxLayout(containter);
	
	m_editor = new QTextEdit;
	m_editor->setFocusPolicy( Qt::WheelFocus );
	m_mainLayout->addWidget(m_editor);
	
	m_workspace = new QWorkspace;
	m_workspace->setScrollBarsEnabled ( true );
	m_mainLayout->addWidget(m_workspace);
	connect(m_workspace, SIGNAL(windowActivated ( QWidget *)), this, SLOT(activeForm(QWidget *)));
	
	connect(m_editor, SIGNAL(textChanged()), this, SLOT(analize()));
	
	setCentralWidget( containter );
	
	m_builder = new CFormBuilder;
	
	m_currentForm = new QMainWindow;
	m_workspace->addWindow(m_currentForm);
	
	m_formCode.insert(m_currentForm, "");
	
	setupMenu();
	
	FToolManager *toolManager = new FToolManager(this);
	
	connect(toolManager, SIGNAL(appendObject( const QString& )), m_editor, SLOT(insertPlainText(const QString &)));
}


FDesigner::~FDesigner()
{
}

void FDesigner::setupMenu()
{
	QMenu *menu = menuBar()->addMenu(tr("File"));
	
	menu->addAction(tr("New form..."), this, SLOT(newForm()));
	menu->addAction(tr("Open file..."), this, SLOT(openFile()));
	menu->addAction(tr("Save..."), this, SLOT(save()));
	menu->addAction(tr("Quit"), this, SLOT(close()));
}

void FDesigner::newForm()
{
	QMainWindow *newForm = new QMainWindow;
	
	m_formCode.insert(newForm, "");
	
	m_workspace->addWindow(newForm);
	
	newForm->show();
	
	m_currentForm = newForm;
	
	m_editor->clear();
}

void FDesigner::analize()
{
// 	D_FUNCINFO;
	QString text = m_editor->toPlainText();
	
	CForm *w = m_builder->form( text );
	
	if( w && m_currentForm )
	{
		QWidget *central = m_currentForm->centralWidget();
		
		if( central )
		{
			delete central;
		}
		
		m_currentForm->setCentralWidget( w );
		m_currentForm->setWindowTitle( w->windowTitle() );
		m_currentForm->adjustSize();
		m_formCode[m_currentForm] = text;
		
		m_editor->setFocus();
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

void FDesigner::save()
{
	QString fileName = QFileDialog::getSaveFileName (this,tr("Save..."), QString(),"Forms (*.dfm)" );
	
	if ( !fileName.endsWith(".dfm" ) )
	{
		fileName += ".dfm";
	}
	
	QFile file(fileName);
	
	if ( file.open( QIODevice::WriteOnly | QIODevice::Text))
	{
		QTextStream out(&file);
		out << m_editor->toPlainText() << endl;
		file.close();
	}
}


void FDesigner::activeForm(QWidget *window)
{
	QMainWindow *form = qobject_cast<QMainWindow*>(window);
	
	if ( form )
	{
		m_currentForm = form;
		m_currentForm->setFocus();
		
		QTimer::singleShot( 0, this, SLOT(updateEditor()));
	}
	
}


void FDesigner::updateEditor()
{
	m_editor->setPlainText( m_formCode[m_currentForm] );
}

