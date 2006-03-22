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
#include <QToolBar>

#include "cconnectiondialog.h"

#include <dtabwidget.h> // dlib
#include <ddebug.h>
#include <dconfig.h>

#include <dglobal.h>

CMainWindow::CMainWindow() : DMainWindow(), m_helpBrowser(0)
{
	setWindowTitle(tr("Client"));
	
#ifdef Q_WS_X11
	static const uint SIZE = 40960; //40 KiB
        static char stdout[ SIZE ];
	
	FILE *process = ::popen( "fortune", "r" );
	stdout[ std::fread( (void*)stdout, sizeof(char), SIZE-1, process ) ] = '\0';
	
	::pclose( process );
	
	QString title = QString::fromLocal8Bit(stdout);
	
	if ( !title.isEmpty() )
	{
		setWindowTitle( title );
	}
	
#endif
	
	m_actionManager = new DActionManager(this);
	
	m_connector = new CConnector;
	
	m_formManager = new CFormManager(this);
	
	connect(m_formManager, SIGNAL(formLoaded(QWidget *, const QString &)), this, SLOT(addForm(QWidget *, const QString &)));
	
	connect(m_connector, SIGNAL(readedModuleForms( const ModuleForms& )), this, SLOT(buildModules(const ModuleForms &)));
	
	QTimer::singleShot(800, this, SLOT(showConnectDialog()));
	
	m_helper = new CHelpWidget;
	connect(m_helper, SIGNAL(pageLoaded( const QString&, const QString& )), this, SLOT(showHelp(const QString &, const QString &)));
	toolWindow(DDockWindow::Right)->addWidget( tr("Help"), m_helper);
	
	m_chat = new CChatWindow;
	connect(m_chat, SIGNAL(textToSend( const QString& )), m_connector, SLOT(sendToServer( const QString& )));
	
	connect(m_connector, SIGNAL(chatMessage( const QString&, const QString& )), m_chat, SLOT(setChatMessage( const QString&, const QString&)));
	
	
	setupActions();
	setupToolbar();
	setupMenu();
	
	statusBar()->show();
	
	toolWindow( DDockWindow::Bottom )->hide();
}

void CMainWindow::setupActions()
{
	DAction *network = new DAction( QIcon(THEME_DIR+"/icons/connect.png"), tr("Connect"), QKeySequence(), this, SLOT(showConnectDialog()), m_actionManager, "connect"); 
	network->setStatusTip(tr("Connect to server..."));
}

void CMainWindow::setupMenu()
{
	QMenu *file = menuBar()->addMenu(tr("File"));
	
	file->addAction(tr("Load test form"), this, SLOT(loadTestForm()));
	
	file->addSeparator();
	file->addAction(tr("Quit"), this, SLOT(close()));
	
	
	QMenu *tools = menuBar()->addMenu(tr("Tools"));
	tools->addAction(QIcon(THEME_DIR+"/icons/chat.png"),tr("Chat"), this, SLOT(showChat()));
	tools->addSeparator();
	
	tools->addAction(QIcon(THEME_DIR+"/icons/wizard.png"), tr("First run dialog..."), dApp, SLOT(firstRun()));
	
	
	QMenu *help = menuBar()->addMenu(tr("Help"));
	
// 	help->addAction(tr("Help..."), m_helper, SLOT(show()));
	
	help->addAction(tr("About Qt..."), qApp, SLOT(aboutQt()));
	
}

void CMainWindow::setupToolbar()
{
	QToolBar *toolBar = new QToolBar(this);
	
	toolBar->addAction(m_actionManager->find("connect"));
	
	
	addToolBar( Qt::TopToolBarArea, toolBar );
}

CMainWindow::~CMainWindow()
{
}

void CMainWindow::closeEvent(QCloseEvent *)
{
	delete m_chat;
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
	m_formManager->loadForm( "General", 1 );
}

void CMainWindow::buildModules(const ModuleForms &modules)
{
	m_formManager->setForms(modules);
	
	foreach(QString moduleName, modules.keys())
	{
		CModuleWidget *module = 0;
		DDockWindow::Position pos = DDockWindow::Left;
		
		if ( moduleName.toLower() == tr("clients") )
		{
			module = new CClientModuleWidget(tr("Clients") );
			
		}
		else
		{
			module = new CModuleWidget(moduleName);
		}
		
		toolWindow(pos)->addWidget( moduleName, module);
		
		connect(module, SIGNAL(requestForm(const QString &, int)), m_formManager, SLOT(loadForm(const QString &, int)));
	}
}

void CMainWindow::showChat()
{
	m_chat->show();
}

void CMainWindow::showHelp(const QString &title, const QString &page)
{
	if(!m_helpBrowser)
	{
		m_helpBrowser = new CHelpBrowser;
	}
	
	if ( !m_helpBrowser->isVisible() )
	{
		addWidget( m_helpBrowser, tr("Help"));
	}
	
	m_helpBrowser->setSource( page );
	
}

