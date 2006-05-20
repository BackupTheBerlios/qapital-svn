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
#include <QMessageBox>
#include <QScrollArea>

#include "cconnectiondialog.h"

#include <dtabwidget.h> // dlib
#include <ddebug.h>
#include <dconfig.h>

#include <dglobal.h>
#include <dtip.h>

CMainWindow::CMainWindow() : DMainWindow(), m_helpBrowser(0), m_formRequester(0)
{
	setWindowTitle(tr("Client"));
	
#ifdef Q_WS_X11
	static const uint SIZE = 40960; //40 KiB
        static char buff[ SIZE ];
	
	FILE *process = ::popen( "fortune", "r" );
	buff[ std::fread( (void*)buff, sizeof(char), SIZE-1, process ) ] = '\0';
	
	::pclose( process );
	
	QString title = QString::fromLocal8Bit(buff).remove('\n');
	
	if ( !title.isEmpty() )
	{
		setWindowTitle( title );
	}
	
#endif
	
	m_actionManager = new DActionManager(this);
	
	m_connector = new CConnector;
	
	m_formManager = new CFormManager(this);
	
	connect(m_connector, SIGNAL(readedModuleForms( const ModuleForms& )), this, SLOT(buildModules(const ModuleForms &)));
	
	m_helper = new CHelpWidget;
	connect(m_helper, SIGNAL(pageLoaded( const QString&, const QString& )), this, SLOT(showHelp(const QString &, const QString &)));
	toolWindow(DDockWindow::Right)->addWidget( tr("Help"), m_helper);
	
	m_chat = new CChatWindow;
	connect(m_chat, SIGNAL(textToSend( const QString& )), m_connector, SLOT(sendToServer( const QString& )));
	
	connect(m_connector, SIGNAL(chatMessage( const QString&, const QString& )), m_chat, SLOT(setChatMessage( const QString&, const QString&)));
	
	connect(m_connector, SIGNAL(operationFinished( const QList< XMLResults >& )), this, SLOT(operationResults( const QList< XMLResults >& )));
	
	setupActions();
	setupToolbar();
	setupMenu();
	
	statusBar()->show();
	
	toolWindow( DDockWindow::Bottom )->hide();
	
	DCONFIG->beginGroup("TipOfDay");
	bool showTips = qvariant_cast<bool>(DCONFIG->value("ShowOnStart", true ));
	
	if ( showTips )
	{
		QTimer::singleShot(0, this, SLOT(showTipDialog()));
	}
	
// 	QTimer::singleShot(800, this, SLOT(showConnectDialog()));
	
	connectToOutput( m_connector );
}

void CMainWindow::setupActions()
{
	DAction *network = new DAction( QIcon(THEME_DIR+"/icons/connect.png"), tr("Connect"), QKeySequence(), this, SLOT(showConnectDialog()), m_actionManager, "connect"); 
	network->setStatusTip(tr("Connect to server..."));
	
	new DAction(QIcon(THEME_DIR+"/icons/tip.png"), tr("Tip of day"), QKeySequence(), this, SLOT(showTipDialog()), m_actionManager, "tipofday");
}

void CMainWindow::setupMenu()
{
	QMenu *file = menuBar()->addMenu(tr("File"));
	
	QMenu *newMenu = file->addMenu(tr("New"));
	
	file->addSeparator();
	file->addAction(tr("Quit"), this, SLOT(close()));
	
	
	QMenu *tools = menuBar()->addMenu(tr("Tools"));
	tools->addAction(QIcon(THEME_DIR+"/icons/chat.png"),tr("Chat"), this, SLOT(showChat()));
	tools->addSeparator();
	
	tools->addAction(QIcon(THEME_DIR+"/icons/wizard.png"), tr("First run dialog..."), dApp, SLOT(firstRun()));
	
	
	QMenu *help = menuBar()->addMenu(tr("Help"));
	
// 	help->addAction(tr("Help..."), m_helper, SLOT(show()));
	
	help->addAction(m_actionManager->find("tipofday"));
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

void CMainWindow::addForm(CForm *form)
{
	D_FUNCINFO;
	if ( form )
	{
		QScrollArea *scroll = new QScrollArea;
		scroll->setWidget(form);
		
		addWidget( scroll, form->windowTitle(), false);
		
		connect(form, SIGNAL(requestSentToServer(const QString &)), m_connector, SLOT(sendToServer( const QString& )));
		connect(form, SIGNAL(requestOperation(CForm *, const CSqlPackageBase *)), this, SLOT(doOperation(CForm *, const CSqlPackageBase *)));
	}
}

void CMainWindow::buildModules(const ModuleForms &modules)
{
	m_formManager->setForms(modules);
	
	setUpdatesEnabled(false);
	
	foreach(ModuleInfo module, modules.keys())
	{
		CModuleWidget *moduleWidget = 0;
		DDockWindow::Position pos = DDockWindow::Left;
		
		QString title;
		
		if ( module.key == "pct" )
		{
			title = tr("Pacients");
			moduleWidget = new CClientModuleWidget(title);
		}
		else if ( module.key == "gnr" )
		{
			title = tr("General");
			moduleWidget = new CGeneralModuleWidget( title);
		}
		else if ( module.key == "agn" )
		{
			title = tr("Agend");
			moduleWidget = new CAgendModuleWidget(title );
			
			pos = DDockWindow::Right;
		}
		else if ( module.key == "ort" )
		{
			title = tr("Orthodoncy");
			moduleWidget = new COrthodoncyModuleWidget(title);
		}
		else if ( module.key == "edd" )
		{
			title = tr("Endodoncy");
			moduleWidget = new CEndodoncyModuleWidget( title);
		}
		else if ( module.key == "prd" )
		{
			title = tr("Periodoncy");
			moduleWidget = new CPeriodoncyModuleWidget( title);
		}
		else if ( module.key == "pad" )
		{
			title = tr("Phonoaudiology");
			moduleWidget = new CPhonoaudiologyWidgetModule(title );
		}
		else if ( module.key == "rpt" )
		{
			title = tr("Reports");
			moduleWidget = new CReportModuleWidget(title);
			
			pos = DDockWindow::Right;
		}
		else
		{
			moduleWidget = new CModuleWidget(module.text);
		}
		
		if ( module.text.isEmpty() )
		{
			toolWindow(pos)->addWidget( title, moduleWidget);
		}
		else
		{
			toolWindow(pos)->addWidget( module.text, moduleWidget);
		}
		
		if (  moduleWidget )
		{
			connect(moduleWidget, SIGNAL(requestForm(const QString &, int)), this, SLOT(loadForm(const QString &, int)));
			
			moduleWidget->setup(module);
			
			moduleWidget->setAutoFillBackground(true);
			
			connectToOutput( moduleWidget);
			
			m_moduleWidgets.insert(module.key, moduleWidget);
		}
	}
	
	setUpdatesEnabled(true);
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

void CMainWindow::showTipDialog()
{
	DTipDialog *m_tipDialog = new DTipDialog(DATA_DIR+"/tips", this);
	m_tipDialog->show();
}


void CMainWindow::handleMessage(Msg::Type type, const QString &message)
{
	switch(type)
	{
		case Msg::Error:
		{
			QMessageBox::critical(this, tr("Error"), message,QMessageBox::Ok , 0 );
		}
		break;
		case Msg::Info:
		{
			statusBar()->showMessage(message);
		}
		break;
		case Msg::Warning:
		{
			
		}
		break;
	}
}


void CMainWindow::connectToOutput(const QObject *o)
{
	connect(o, SIGNAL(message(Msg::Type, const QString &)), this, SLOT(handleMessage( Msg::Type, const QString& )));
}


void CMainWindow::doOperation(CForm *form, const CSqlPackageBase *package)
{
	if ( !package )
	{
		dFatal() << "Fatal error !!!";
		return;
	}
	
	m_formRequester = form; // FIXME
	
	m_connector->sendToServer( package->toString(0) );
}

void CMainWindow::operationResults(const QList<XMLResults> &results )
{
	if ( m_formRequester )
	{
		(m_formRequester)->setOperationResult(results);
	}
}

void CMainWindow::loadForm(const QString &module, int id)
{
	CForm *form = m_formManager->loadForm( module, id );
	
	if ( form )
	{
		addForm( form );
	}
}

