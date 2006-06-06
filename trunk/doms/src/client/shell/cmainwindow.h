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

#ifndef CMAINWINDOW_H
#define CMAINWINDOW_H

#include <dmainwindow.h>
#include <QQueue>

#include "cconnector.h"
#include "cformmanager.h"
#include "cmodulewidget.h"

#include "global.h"

#include <dactionmanager.h>



// Tools
#include "cchatwindow.h"
#include "chelpbrowser.h"

// Modules
#include "cclientmodulewidget.h"
#include "chelpwidget.h"
#include "cgeneralmodulewidget.h"
#include "cagendmodulewidget.h"
#include "corthodoncymodulewidget.h"
#include "cphonoaudiologywidgetmodule.h"
#include "cperiodoncymodulewidget.h"
#include "cendodoncymodulewidget.h"
#include "creportmodulewidget.h"

#include "csqlpackagebase.h"

/**
 * Ventana principal de la aplicacion cliente
 * @author David Cuadrado \<krawek@gmail.com\>
*/
class CMainWindow : public DMainWindow
{
	Q_OBJECT;
	public:
		CMainWindow();
		~CMainWindow();
		
		QSize sizeHint() const { return QSize(600,600); };
		
		void connectToOutput(const QObject *o);
		
	private:
		void setupActions();
		void setupMenu();
		void setupToolbar();
		
	private slots:
		void showConnectDialog();
		void buildModules(const ModuleForms &modules);
		
		void loadForm(const QString &module, int id, const QString &key);
		void addForm(CForm *form);
		
		void showChat();
		void showHelp(const QString &title, const QString &page);
		void showTipDialog();
		
		void handleMessage(Msg::Type type, const QString &message);
		
		void doOperation(CForm *form, const CSqlPackageBase *package);
		void doOperation(CModuleWidget *module, const CSqlPackageBase *package);
		
		void operationResults(const QList<XMLResults> &results );
		
	protected:
		void closeEvent(QCloseEvent *);
		
	private:
		CConnector *m_connector;
		
		CChatWindow *m_chat;
		
		CFormManager *m_formManager;
		
		CHelpWidget *m_helper;
		CHelpBrowser *m_helpBrowser;
		
		QQueue<CDatabaseRequesterIface *> m_requesterQueue;
		
		QHash<QString, CModuleWidget *> m_moduleWidgets;
		
	private:
		DActionManager *m_actionManager;
};

#endif
