/* Clase: GCLogin
 * Autor: CetiSoft
 * Version: 0.0.1
 * Fecha de creacion: 19/06/2004
 * Fecha de modificacion:
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

#include "gclogin.h"

GCLogin::GCLogin(QWidget *parent, const char *name) : QGroupBox (parent, name)
{
	frameLogin = new QFrame(this);
	frameLogin->setFrameStyle(QFrame::Box | QFrame::Plain);
	frameLogin->setLineWidth( 2 );
	
	gclFrameLayout =  new QGridLayout( frameLogin, 3, 3);
//	gclFrameLayout->setAlignment(Qt::AlignCenter);
	gclFrameLayout->setRowSpacing(0, 10);
	gclFrameLayout->setRowSpacing(3, 10);
	gclFrameLayout->setColSpacing(0, 20);
	gclFrameLayout->setColSpacing(3, 20);

	selector = new GCLSelectUser(this);
	connect (selector, SIGNAL(clicked(QIconViewItem*)), SLOT(usuarioEscogido(QIconViewItem *)) ),
	selector->leerUsuarios();
	
	crearEntradas();
	
	gclLayout =  new QGridLayout( this, 3, 3);
	gclLayout->setRowSpacing(0, 10);
	gclLayout->setRowSpacing(3, 10);
	gclLayout->setColSpacing(0, 30);
	gclLayout->setColSpacing(3, 30);	
	gclLayout->setAlignment(Qt::AlignCenter);
	
	gclLayout->addWidget(selector, 0,1);
	gclLayout->addWidget(frameLogin, 1,1 );
	gclLayout->addWidget(continuar, 2,1);
}

GCLogin::~GCLogin()
{
}

/**
Esta funcion crea los widgets de entrada
*/
void GCLogin::crearEntradas()
{
	gclCapturarUsuario = new QLineEdit(frameLogin);
	gclCapturarUsuario->setMaxLength( 10 );
	gclCapturarUsuario->setMaximumWidth ( 80 );
	gclCapturarUsuario->setMinimumWidth( 60 ) ;
	
	gclCapturarPassword = new QLineEdit(frameLogin);
	gclCapturarPassword->setMaxLength(10);
	gclCapturarPassword->setMinimumWidth(60) ;
	gclCapturarPassword->setMaximumWidth(80) ;
	gclCapturarPassword->setEchoMode(QLineEdit::Password);
	
	gclLabelUsuario = new QLabel( tr("Usuario: "), frameLogin);
	gclLabelUsuario->setBuddy( gclCapturarUsuario );
	
	gclLabelPassword = new QLabel( tr("Contraseña: "), frameLogin);
	gclLabelPassword->setBuddy( gclCapturarPassword );
	
	continuar = new QPushButton( tr("continuar ->"), this);
//	continuar->setMaximumWidth(80) ;
	connect(continuar, SIGNAL(clicked() ), SLOT( gclContinuar() ) );
	
	gclFrameLayout->addWidget(gclLabelUsuario, 1, 0);
	gclFrameLayout->addWidget(gclCapturarUsuario, 1 ,1);
	gclFrameLayout->addWidget(gclLabelPassword, 2, 0);
	gclFrameLayout->addWidget(gclCapturarPassword, 2, 1);
}

void GCLogin::gclContinuar()
{	
	login = gclCapturarUsuario->text();
	password = gclCapturarPassword->text();
	emit gclFueClickeado();
}

QString GCLogin::obtenerLogin()
{
	return login;
}

QString GCLogin::obtenerPassword()
{
	return password;
}

// Slot: usuarioEscogido
// Descripcion: sirve para obtener el texto del usuario escogido.
void GCLogin::usuarioEscogido(QIconViewItem *item)
{
	if (item)
		gclCapturarUsuario->setText(item->text() );
}
