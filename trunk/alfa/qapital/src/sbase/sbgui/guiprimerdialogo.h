/* Clase: GUIPrimerDialogo
 * Autor: CetiSoft
 * Version: 0.0.1
 * Fecha de creacion: 10/02/2005
 * Fecha de modificacion: 11/02/2005
 * Relacion con objetos: es un QWizard
 * Descripcion: Esta clase es una ventana para crear la configuracion del cliente la primera vez que se ejecuta la aplicacion
 */

/********************************************************************************
 *   Copyright (C) 2004 by CetiSoft                                            *
 *   cetisoft@linuxmail.org                                                    *
 *                                                                             *
 *   This program is free software; you can redistribute it and/or modify      *
 *   it under the terms of the GNU General Public License as published by      *
 *   the Free Software Foundation; either version 2 of the License, or         *
 *   (at your option) any later version.                                       *
 *                                                                             *
 *   This program is distributed in the hope that it will be useful,           *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of            *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the             *
 *   GNU General Public License for more details.                              *
 *                                                                             *
 *   You should have received a copy of the GNU General Public License         *
 *   along with this program; if not, write to the                             *
 *   Free Software Foundation, Inc.,                                           *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.                 *
 *******************************************************************************/
#ifndef GUIPRIMERDIALOGO_H
#define GUIPRIMERDIALOGO_H

#include <qwizard.h>
#include <qlabel.h>
#include <qvbox.h>
#include <qhbox.h>
#include <qlistview.h>
#include <qimage.h>
#include <qpixmap.h>
#include <qbitmap.h>
#include <qfile.h>
#include <qvbuttongroup.h> 
#include <qpushbutton.h>
#include <iostream>
#include <qstring.h>
#include <qlineedit.h>
#include <qframe.h>
#include <qlayout.h> 

#include "sbgui.h"

/**
@short Esta clase es una ventana para crear la configuracion del cliente la primera vez que se ejecuta la aplicacion
@author CetiSoft
*/

class GUIPrimerDialogo : public QWizard
{
	Q_OBJECT
	private:
		QVBox *introduccion,*paginaUno, *paginaDos;
		QGridLayout *gridRed;
		QFrame *red;
		QLabel *textoIntroduccion, *displayTipoInterfaz, *puerto, *host, *explicaUno, *explicaDos;
		QHBox *tipoInterfaz;
		QVButtonGroup *listaInterfaces;
		QPushButton *mdi, *menues;
		QPixmap pixmap;
		QLineEdit *catPuerto, *catHost;
		int tipo;
		
	public:
		GUIPrimerDialogo( const char *nombre = 0 );
		~GUIPrimerDialogo();
		int interfazElegida();
		QString obtenerPuerto();
		QString obtenerHost();
		
	public slots:
		void selecionTipo(int id);
	
	protected:
		void crearIntroduccion();
		void crearTipoInterfaz();
		void crearConfigRed();
	
};

#endif


