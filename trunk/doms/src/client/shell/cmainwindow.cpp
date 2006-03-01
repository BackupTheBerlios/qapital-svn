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

#include "dtabwidget.h"
#include <QLabel>
#include <QTimer>

#include "cconnectdialog.h"

#include <ddebug.h>

CMainWindow::CMainWindow() : DMainWindow()
{
	setWindowTitle(tr("The client"));
	
	QTimer::singleShot(1000, this, SLOT(showConnectDialog()));
}


CMainWindow::~CMainWindow()
{
}

void CMainWindow::showConnectDialog()
{
	CConnectDialog connectionDialog;
	if ( connectionDialog.exec() != QDialog::Rejected )
	{
		dDebug() << connectionDialog.user() << " " << connectionDialog.password();
	}
}


