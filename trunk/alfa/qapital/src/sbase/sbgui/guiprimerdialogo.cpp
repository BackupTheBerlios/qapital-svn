/* Archivo: GUIPrimerDialogo
 * Autor: CetiSoft
 * Version: 0.0.1
 * Fecha de creacion: 10/02/2005
 * Fecha de modificacion: 11/02/2005
 * Descripcion:
 *     Esta clase es una ventana para crear la configuracion del cliente la primera vez que se ejecuta la aplicacion
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

 
#include "guiprimerdialogo.h"
/**
* Constructor 
* @param nombre: El nombre del objeto
*/
GUIPrimerDialogo::GUIPrimerDialogo(const char *nombre)
 : QWizard(0, nombre, false, 0), tipo(0)
{
	qDebug("[Costruyendo GUIPrimerDialogo]");
	//TODO: Hacer un dialogo para elegir el idioma
	//TODO: validar Datos
	crearIntroduccion();
	crearConfigRed();
	crearTipoInterfaz();
	setFinishEnabled (paginaDos , true);
}

/**
* Destructor
*/
GUIPrimerDialogo::~GUIPrimerDialogo()
{
	qDebug("[Destruyendo GUIPrimerDialogo]");
}


/**
* Esta funcion se encarga de crear la primera pantalla del dialogo la cual contiene una pequeÃ±a introduccion
*/
void GUIPrimerDialogo::crearIntroduccion()
{
	introduccion = new QVBox(this, tr("introducciÃ³n"));
	textoIntroduccion = new QLabel(introduccion);
	textoIntroduccion->setText(tr("<H3>Qapital Cliente</H3> </BR></BR> QApital es un programa para el manejo contable, basado en estandar <a href=http://www.kazak.ws/midas>Midas</a></br></br>" ));
	textoIntroduccion->setMargin (10);
	addPage(introduccion, tr("<H1><div align=\"center\"> Introduccion </div></H1>"));
}

/**
* Esta funcion se encarga de crear el dialogo en el cual se escoge el tipo de Interfaz
*/
void GUIPrimerDialogo::crearTipoInterfaz()
{
	paginaDos = new QVBox(this);
	explicaDos = new QLabel(paginaDos);
	explicaDos->setText("Escoge el tipo de interfaz de tu preferencia");
	tipoInterfaz = new QHBox(paginaDos, "tipoInterfaz");
	listaInterfaces = new QVButtonGroup(tipoInterfaz);
	//FIXME: PENSAR EN COMO IDENTIFICAR LOS ICONOS  
	menues = new QPushButton(tr("Menues"), listaInterfaces, "Menues");
	menues->setDisabled(true);
	mdi = new QPushButton(tr("MDI"), listaInterfaces,"MDI");
	connect( listaInterfaces, SIGNAL(clicked(int)), SLOT(selecionTipo(int)));
	displayTipoInterfaz = new QLabel(tipoInterfaz);
	displayTipoInterfaz->setText(tr("Menues"));
	displayTipoInterfaz->setMargin (10);
	addPage(paginaDos, "<H1><div align=\"center\"> Tipo de interfaz </div></H1>");
}

/**
* Esta funcion que se encarga de cambiar el screenshot segun la interfaz eleguida
*/
void GUIPrimerDialogo::selecionTipo(int id)
{
	//FIXME: cambiar este metodo para que carge las imagenes
	std::cout <<  " " << id;
	switch (id)
	{
		case 0:
		{
			//TODO: hacer las imagenes a colocar en el visualizador de tipos de interfaz
			displayTipoInterfaz->setText(tr("Menues"));
			mdi->setEnabled(true);
			menues->setDisabled(true);
			tipo = SBGui::MenuBased;
			break;
		}
		case 1:
		{
			displayTipoInterfaz->setText(tr("MDI"));
			mdi->setDisabled(true);
			menues->setEnabled(true);
			tipo = SBGui::MDIBased;
			break;
		}
	}
}

/**
* Esta funcion se encarga de crear el dialogo en el cual configura la red
*/
void GUIPrimerDialogo::crearConfigRed()
{
	paginaUno = new QVBox(this);
	explicaUno = new QLabel(paginaUno );
	explicaUno->setText("<p>Llena los campos del servidor en donde se encuentra corriendo el servidor de transacciones y el puerto respectivo</p><br>");
	red = new QFrame(paginaUno, "red");
	gridRed = new QGridLayout(red, 2, 2,5,5);
	host = new QLabel(red);
	host->setText(tr("host:"));
	gridRed->addWidget( host, 1, 1);
	catHost = new QLineEdit(red);
	gridRed->addWidget( catHost, 1, 2); 
	
	puerto = new QLabel(red);
	gridRed->addWidget( puerto, 2, 1);
	puerto->setText(tr("puerto:"));
	catPuerto = new QLineEdit(red);
	catPuerto->setText("9117");
	gridRed->addWidget( catPuerto, 2, 2);
	
	addPage(paginaUno, tr("<H1><div align=\"center\"> Configuracion de la red. </div></H1>"));
}


/**
* Esta funcion retorna la interfaz elegida
*/
int GUIPrimerDialogo::interfazElegida()
{
	return tipo;
}

/**
* Esta funcion retorna el host
*/
QString GUIPrimerDialogo::obtenerHost()
{
	return catHost->text();
}

/**
* Esta funcion retorna el puerto
*/
QString GUIPrimerDialogo::obtenerPuerto()
{
	return catPuerto->text();
}

