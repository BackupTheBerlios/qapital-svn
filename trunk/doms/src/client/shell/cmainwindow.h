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

#include "cconnector.h"
#include "cformmanager.h"

#include "global.h"

/**
 * Ventana principal de la aplicacion cliente
 * @author David Cuadrado <krawek@gmail.com>
*/
class CMainWindow : public DMainWindow
{
	Q_OBJECT;
	public:
		CMainWindow();
		~CMainWindow();
		
		QSize sizeHint() const { return QSize(600,600); };
		
	private:
		void setupMenu();
		
	private slots:
		void showConnectDialog();
		void loadTestForm();
		void addForm(QWidget *form, const QString &title);
		
	private:
		CConnector *m_connector;
		CFormManager *m_formManager;
};

#endif
