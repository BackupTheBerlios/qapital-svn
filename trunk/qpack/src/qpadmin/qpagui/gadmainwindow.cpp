/***************************************************************************
 *   Copyright (C) 2004 by David Cuadrado - Juliana Davila                 *
 *   krawek@gmail.com gobolindo@gmail.com                                  *
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

#include "gadmainwindow.h"

//using namespace sbqpack;

/**
Construye la ventana principal
 */
qpagui::GADMainWindow::GADMainWindow() : GUIMdiMainWindow(), printer(0)
{
	INIQPC;
	QPopupMenu *file = new QPopupMenu( this );
	menuBar()->insertItem( tr("&Archivo"), file );
	setUsesBigPixmaps(false);
	this->setIcon(QPixmap(sbqpack::GUIDATADIR+"/img/logo.png"));

	file->insertItem( tr("&Salir"), qApp, SLOT( closeAllWindows() ), CTRL+Key_Q );

	ventanas = new QPopupMenu( this );
	ventanas->setCheckable( true );

	connect( ventanas, SIGNAL( aboutToShow() ),this, SLOT( ordenarVentanas() ) );
	menuBar()->insertItem( tr("&Ventanas"), ventanas );

	menuBar()->insertSeparator();
	QPopupMenu * help = new QPopupMenu( this );
	menuBar()->insertItem( tr("&Ayuda"), help );

	help->insertItem( tr("&Sobre"), this, SLOT( about() ), Key_F1);
	help->insertItem( tr("Sobre &Qt"), this, SLOT( aboutQt()) );
	
	statusBar(); // crea la barra de status vacia.
	statusBar()->message(tr("Aplicacion iniciada."),4000 );
	
	vbox = new QVBox(this,0);
	vbox->setFrameStyle( QFrame::StyledPanel | QFrame::Sunken );
	setCaption( tr("QApital: Aplicacion administrativa") );
	setCentralWidget(vbox);
	ws = new QWorkspace( vbox );
	ws->setScrollBarsEnabled(true);

	consola = new GADConsola(this);
	moveDockWindow(consola, Qt::DockBottom);
	
	herramientas = new GADPanelDeHerramientas(this);
	moveDockWindow(herramientas, Qt::DockLeft);
	
	ws->showMaximized();
}

/**
 * Destructor
 */
qpagui::GADMainWindow::~GADMainWindow()
{
	if ( printer )
		delete printer;
	FINQPC;
}

/**
 * Funcion que muestra una dialog con los creditos de las librerias Qt.
 */
void qpagui::GADMainWindow::aboutQt()
{
	QMessageBox::aboutQt( this, tr("QApital: Aplicacion administrativa") );
}

/**
Funcion que muestra una dialogo con los creditos de la aplicacion.
 */
void qpagui::GADMainWindow::about()
{
	QMessageBox::about( this, "QApital", tr("<h3><b>QPAdmin: Aplicacion administrativa</b></h3><p>Este programa hace parte de QApital, esta aplicacion administra el servidor y el sistema en general.</p>"));    
}

/**
Ordena las ventans al interior del MDI.
 */
void qpagui::GADMainWindow::ordenarVentanas()
{
	ventanas->clear();
	int cascada = ventanas->insertItem(tr("&Cascada"), ws, SLOT(cascade() ) );
	int tiled = ventanas->insertItem(tr("&Lleno"), ws, SLOT(tile() ) );
	
	if ( ws->windowList().isEmpty() )
	{
		ventanas->setItemEnabled( cascada, false );
		ventanas->setItemEnabled( tiled, false );
	}
	
	ventanas->insertSeparator();
	QWidgetList windows = ws->windowList();
	for ( int i = 0; i < int(windows.count()); ++i )
	{
		int id = ventanas->insertItem(windows.at(i)->caption(),this, SLOT( ventanaActivada( int ) ) );
		ventanas->setItemParameter( id, i );
		ventanas->setItemChecked( id, ws->activeWindow() == windows.at(i) );
	}
}

/**
Da focus a una ventana activada
 */
void qpagui::GADMainWindow::ventanaActivada( int id )
{
	QWidget* w = ws->windowList().at( id );
	if ( w )
		w->showNormal();
	w->setFocus();
}

/**
 * Este es el slot principal, esta funcion hace parte del motor de la GUI y enlaza por el nombre dado en el archivo XML una accion determinada.
 * @b NOTA: Esta funcion hace parte del motor de creacion de GUI en base a XML.
 */
void qpagui::GADMainWindow::slotPrincipal()
{
	// Aqui se agregan todas las acciones que se deseen
	QString actionName = QObject::sender()->name();
	std::cout << actionName << std::endl;
	
	if (actionName == "exit")
	{
		qApp->closeAllWindows(); 
	}
}
 

