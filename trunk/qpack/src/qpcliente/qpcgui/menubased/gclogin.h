/* Clase: 	GCLogin
 * Autor: CetiSoft					
 * Version: 0.0.1					
 * Fecha de creacion: 19/06/2004		
 * Fecha de modificacion:
 * Relacion con objetos:
 * Descripcion:  ventana de logeo
 *
*/

/********************************************************************************
 *   Copyright (C) 2004 by CetiSoft                                        	*
 *   cetisoft@linuxmail.org                                                	*
 *                                                                         	*
 *   This program is free software; you can redistribute it and/or modify  	*
 *   it under the terms of the GNU General Public License as published by  	*
 *   the Free Software Foundation; either version 2 of the License, or     	*
 *   (at your option) any later version.                                   	*
 *                                                                         	*
 *   This program is distributed in the hope that it will be useful,       	*
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        	*
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the        	*
 *   GNU General Public License for more details.                          	*
 *                                                                         	*
 *   You should have received a copy of the GNU General Public License     	*
 *   along with this program; if not, write to the                         	*
 *   Free Software Foundation, Inc.,                                       	*
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             	*
 *******************************************************************************/

#ifndef GCLOGIN_H
#define GCLOGIN_H

/**
 * @TODO: hacer un selector de usuarios al estilo kdm con qiconview.
*/

#include <qgroupbox.h> 
#include <qwidget.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qlayout.h>
#include <qpushbutton.h>
#include <qiconview.h> 
#include <iostream>

#include "gclselectuser.h"

namespace qpcgui
{
	/**
	 * @TODO: Comtemplar la posibilidad de colocar esta clase en sbgui.
	* @author CetiSoft
	*/
	
	class GCLogin : public QGroupBox
	{
		Q_OBJECT
		private:
			QLabel *gclLabelEmpresa, *gclLabelUsuario, *gclLabelPassword;
			QLineEdit *gclCapturarEmpresa, *gclCapturarUsuario, *gclCapturarPassword;
			QPushButton *continuar, *salir;
			QFrame *frameLogin;
			GCLSelectUser *selector;
			QString empresa, login, password;
			
		public:
			GCLogin(QWidget *parent = 0, const char *name = 0);
			~GCLogin();
			void crearEntradas();
			QString obtenerLogin();
			QString obtenerPassword();
			QString obtenerEmpresa();
			
		public slots:
			void gclContinuar();
			void usuarioEscogido(QIconViewItem *);
			
		signals:
			void gclFueClickeado();
		
		protected:
			QGridLayout *gclLayout;
			QGridLayout *gclFrameLayout;
	
	};
}
#endif
