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

#include "amainwindow.h"

#include <QStatusBar>
#include <QMenuBar>
#include <QToolBar>

#include "global.h"

#include "cconnectiondialog.h"

AMainWindow::AMainWindow(QWidget *parent) : DMainWindow(parent), m_helpBrowser(0)
{
	setWindowTitle(tr("Admin"));
	
#ifdef Q_WS_X11
	static const uint SIZE = 40960; //40 KiB
        static char stdout[ SIZE ];
	
	FILE *process = ::popen( "fortune", "r" );
	stdout[ std::fread( (void*)stdout, sizeof(char), SIZE-1, process ) ] = '\0';
	
	::pclose( process );
	
	QString title = QString::fromLocal8Bit(stdout).remove('\n');
	
	if ( !title.isEmpty() )
	{
		setWindowTitle( title );
	}
	
#endif
	
	m_connector = new AConnector;
	
	m_actionManager = new DActionManager(this);
	
	m_helper = new CHelpWidget;
	connect(m_helper, SIGNAL(pageLoaded( const QString&, const QString& )), this, SLOT(showHelp(const QString &, const QString &)));
	toolWindow(DDockWindow::Right)->addWidget( tr("Help"), m_helper);
	
	setupActions();
	setupToolbar();
	setupMenu();
	
	statusBar()->show();
	
	toolWindow( DDockWindow::Bottom )->hide();
}


AMainWindow::~AMainWindow()
{
}

void AMainWindow::showConnectDialog()
{
	CConnectionDialog connectionDialog;
	if ( connectionDialog.exec() != QDialog::Rejected )
	{
		m_connector->connectToHost(connectionDialog.server(), connectionDialog.port());
		m_connector->login(connectionDialog.user(), connectionDialog.password());
	}
}

void AMainWindow::setupActions()
{
	DAction *network = new DAction( QIcon(THEME_DIR+"/icons/connect.png"), tr("Connect"), QKeySequence(), this, SLOT(showConnectDialog()), m_actionManager, "connect"); 
	network->setStatusTip(tr("Connect to server..."));
}

void AMainWindow::setupMenu()
{
	QMenu *file = menuBar()->addMenu(tr("File"));
	
	QMenu *newMenu = file->addMenu(tr("New"));
	
	file->addSeparator();
	file->addAction(tr("Quit"), this, SLOT(close()));
	
	
	QMenu *tools = menuBar()->addMenu(tr("Tools"));
	
	tools->addAction(QIcon(THEME_DIR+"/icons/wizard.png"), tr("First run dialog..."), dApp, SLOT(firstRun()));
	
	
	QMenu *help = menuBar()->addMenu(tr("Help"));
	
}

void AMainWindow::setupToolbar()
{
	QToolBar *toolBar = new QToolBar(this);
	
	toolBar->addAction(m_actionManager->find("connect"));
	
	
	addToolBar( Qt::TopToolBarArea, toolBar );
}
