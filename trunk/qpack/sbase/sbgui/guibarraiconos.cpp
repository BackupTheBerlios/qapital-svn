/* Clase: GUIBarraIconos
 * Autor: CetiSoft
 * Version: 0.0.1
 * Fecha de creacion: 
 * Fecha de modificacion:
*/

/*
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 */
#include "guibarraiconos.h"
#include <qaction.h>
#include <qapplication.h>

/**
 * Nombre    : GUIBarraIconos
 * Finalidad : GUIBarraIconos: aquii lleno la barra de iconos con QToolButton tantos como se quieran
*/

sbgui::GUIBarraIconos::GUIBarraIconos( QMainWindow * padre , const char * nombre, int numBotones )
 : QToolBar(padre, nombre), gbrBotones(numBotones)
{
//	QAction *action = new QAction(QPixmap("parlante.png"),"Bleee", CTRL+Key_S, this );
//	connect(action, SIGNAL(activated() ), this, SLOT( gbrSlot() ) );
//	action->addTo(this);
	
	for(int i = 0 ; i < numBotones; i++)
	{
		//GUIBotonIcono *tmp = new GUIBotonIcono(i, this,QString("botonTemporal%1").arg(i) );
		GUIBotonIcono *botonTmp = new GUIBotonIcono(i, this, "name" );
		connect(botonTmp, SIGNAL(gbiBotonClikeado(int)), this, SIGNAL(gbrClicked(int)));
		//tmp->setTextPosition(QToolButton::BesideIcon);
	//setWidget(botonTmp);
		botonTmp->addTo(this);
		losBotones.append(botonTmp);
	}
	//setMargin ( -1 );
	setLabel("este es el label");
}

 void sbgui::GUIBarraIconos::GUIBarraIconos( QMainWindow * padre , const char * nombre, QString archivoXml)
{
}



/**
 * Nombre    : ~GUIBarraIconos
 * Finalidad : destructor 
 */

sbgui::GUIBarraIconos::~GUIBarraIconos()
{
}


/**
 * Nombre    : gbrPonerIcono
 * Finalidad : esta funcion le coloca un icono a el boton que se quiera
*/

void sbgui::GUIBarraIconos::gbrPonerIcono(QString fileName, int id)
{
	if(id < 0 || id > gbrBotones)
		std::cout << "error1" << std::endl; // hay que lanzar una excepcion que la captura ek logger
	
	else
	{
		for(uint i = 0; i <= losBotones.count(); i++ )
		{
			if (i == id)
			{
				QPixmap gbrPixmap(fileName);
				QIconSet gbrIcono(gbrPixmap);
				GUIBotonIcono *botonTmp = losBotones[i];
				botonTmp->setIconSet(gbrIcono);
				break;
			}
		}
	}
}


void GUIBarraIconos::gbrPonerTexto (QString texto, int id)
{
	if(id < 0 || id > gbrBotones)
		std::cout << "guibarraiconocs.cpp: gbrPonerTexto(): el id no corresponde." << std::endl; // hay que lanzar una excepcion que la captura el logger
	
	else
	{
		for(uint i = 0; i <= losBotones.count(); i++ )
		{
			if (i == id)
			{
				GUIBotonIcono *botonTmp = losBotones[i];
				botonTmp-> setText(texto);
				break;
			}
		}
	}
}

//gbrInsertar:
void GUIBarraIconos::gbrFueClickeado(int id)
{
	emit gbrClicked( id );
}

