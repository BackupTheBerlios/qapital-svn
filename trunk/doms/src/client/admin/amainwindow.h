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

#ifndef AMAINWINDOW_H
#define AMAINWINDOW_H

#include <dmainwindow.h>
#include <dactionmanager.h>

#include "aconnector.h"

// Tools
#include "chelpbrowser.h"

// Modules
#include "chelpwidget.h"

/**
 * @author David Cuadrado <krawek@gmail.com>
*/
class AMainWindow : public DMainWindow
{
	Q_OBJECT;
	public:
		AMainWindow(QWidget *parent = 0);
		~AMainWindow();
		
	private slots:
		void showConnectDialog();
		
	private:
		void setupActions();
		void setupMenu();
		void setupToolbar();
		
	private:
		CHelpWidget *m_helper;
		CHelpBrowser *m_helpBrowser;
		
		DActionManager *m_actionManager;
		
		AConnector *m_connector;
	
};

#endif
