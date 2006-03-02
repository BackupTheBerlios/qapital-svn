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

#include "cmainwindow.h"


#include <QLabel>
#include <QTimer>
#include <QMenuBar>
#include <QStatusBar>
#include <QMenu>
#include <QApplication>

#include "cconnectiondialog.h"

#include <dtabwidget.h> // dartlib
#include <ddebug.h>
#include <dconfig.h>


CMainWindow::CMainWindow() : DMainWindow()
{
	setWindowTitle(tr("Client"));
	
	setupMenu();
	
	m_connector = new CConnector;
	
	m_formManager = new CFormManager(this);
	
	connect(m_formManager, SIGNAL(formLoaded(QWidget *, const QString &)), this, SLOT(addForm(QWidget *, const QString &)));
	
	connect(m_connector, SIGNAL(readedForms( const QList< FormData >& )), m_formManager, SLOT(setForms(const QList<FormData > &)));
	
	QTimer::singleShot(800, this, SLOT(showConnectDialog()));
}

void CMainWindow::setupMenu()
{
	QMenu *file = menuBar()->addMenu(tr("File"));
	
	file->addAction(tr("Load test form"), this, SLOT(loadTestForm()));
	file->addAction(tr("Quit"), this, SLOT(close()));
	 
	QMenu *help = menuBar()->addMenu(tr("Help"));
	help->addAction(tr("About Qt..."), qApp, SLOT(aboutQt()));
}

CMainWindow::~CMainWindow()
{
}

void CMainWindow::showConnectDialog()
{
	CConnectionDialog connectionDialog;
	if ( connectionDialog.exec() != QDialog::Rejected )
	{
		m_connector->connectToHost(connectionDialog.server(), connectionDialog.port());
		
		m_connector->login(connectionDialog.user(), connectionDialog.password());
	}
}

void CMainWindow::addForm(QWidget *form, const QString &title)
{
	D_FUNCINFO;
	addWidget( form, title, false);
}

void CMainWindow::loadTestForm()
{
	m_formManager->loadForm( 0 );
}
