/* Clase: GUIMenus
 * Autor: CetiSoft
 * Version: 0.0.1
 * Fecha de creacion: 18/6/2004
 * Fecha de modificacion: 14/7/2004
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

#include "guimenus.h"

/*
GUIMenus:

*/
sbgui::GUIMenus::GUIMenus(QWidget *padre, const char *nombre, int filas, int columnas, int mnid)
 : QButtonGroup(padre, nombre), gmnFilas(filas) , gmnColumnas(columnas), mnid(mnid)
{
	gmnGridBase = new QGridLayout(this, filas-1, columnas-1, 10);
	
	generarMenus(filas, columnas);
	
	this->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::MinimumExpanding, false);
}

sbgui::GUIMenus::GUIMenus(QWidget *padre, const char *nombre, GUILectorXml *handler, int mnid ) : QButtonGroup(padre, nombre), mnid(mnid)
{
	qDebug((QString("[construyendo GUIMenus %1]").arg(mnid)));

	gmnFilas = handler->obtenerFilas(mnid);
	gmnColumnas = handler->obtenerColumnas(mnid);
	
	gmnGridBase = new QGridLayout(this, gmnFilas - 1, gmnColumnas - 1, 10);
	
	//std::cout << "Filas: " << gmnFilas << " Columnas: " << gmnColumnas << std::endl;
	
//	std::cerr << "Antes de obtener" << std::endl;
	QStringList listaDeNombres = (QStringList) handler->obtenerListaDeTexto(mnid);
	listaDeFunciones = (QStringList) handler->obtenerListaDeFunciones(mnid);
//	std::cerr << "Despues de obtener" << std::endl;
	
	int gmnContador = 0;

	for(int i = 0 ; i < gmnFilas; i++)
	{
		for (int j = 0 ; j < gmnColumnas; j++)
		{
//			std::cerr << "En el for de guimenus.cpp" << std::endl;
			QPushButton *botonTmp = new QPushButton (listaDeNombres[gmnContador], this);
			gmnGridBase->addWidget(botonTmp,i,j);
			this->insert(botonTmp, gmnContador);
			losBotones.append(botonTmp);
			botonTmp->setMinimumSize(40,30);
//			botonTmp->setMaximumSize(1000,60);
			botonTmp->resize(80,50);
			
			botonTmp->setSizePolicy(QSizePolicy::MinimumExpanding,QSizePolicy::MinimumExpanding, false);
			gmnContador++;
		}
	}
	setSizePolicy(QSizePolicy::MinimumExpanding,QSizePolicy::MinimumExpanding, false);
	qDebug("[GUIMenus construido]");
}


/*
~GUIMenus:
*/

sbgui::GUIMenus::~GUIMenus()
{
	qDebug("[GUIMenus destruido]");
}

// generarMenus()
// Esta funcion se encarga de generar menus de n filas por m columnas
void sbgui::GUIMenus::generarMenus(int n, int m)
{
	int gmnContador = 0;
	for(int i = 0 ; i < n; i++)
	{
		for (int j = 0 ; j < m; j++)
		{
			QPushButton *botonTmp = new QPushButton ("", this);
			gmnGridBase->addWidget(botonTmp,i,j);
			this->insert(botonTmp, gmnContador);
			gmnContador++;
			losBotones.append(botonTmp);
			botonTmp->setMinimumSize(40,30);
			botonTmp->resize(80,50);
			
			botonTmp->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred, false);
		}
	}
}

/*
gmnDesabilitar:

*/

void sbgui::GUIMenus::gmnDesabilitar()
{
	ListaDeBotones::iterator iterador, ultimo = losBotones.end();
		
	for(iterador=losBotones.begin(); !(iterador==ultimo); iterador++)
	{
		(*iterador)->setDisabled(true); 
	}
}

/*

gmnCambiarTexto:


void GUIMenus::gmnCambiarTexto(QString nuevotexto)
{
	if(tipo)
	{
		std::cout << "error" << std::endl;
	}
	
	ListaDeBotones::iterator iterador, ultimo = losBotones.end();
	for(iterador = losBotones.begin(); !(iterador == ultimo); iterador++)
	{
		(*iterador)->setText(nuevotexto);
	}
}*/

/*
gmnCambiarTextoDeBoton
	Esta funcion sirve para cambiar el texto al boton que le corresponda el id.
*/
void sbgui::GUIMenus::gmnCambiarTextoDeBoton(QString nuevotexto, int id)
{
	if(0 > id || id > gmnFilas * gmnColumnas)
		std::cout << "error1" << std::endl; // hay que lanzar una excepcion que la captura el logger
	
	for(uint i = 0; i <= losBotones.count(); i++ )
	{
		if (i == id)
		{
			QPushButton *tmp = losBotones[id];
			tmp->setText(nuevotexto);
			break;
		}
	}
}

// gmnNumeroDeBotones
// Retorna el numero de botones

int sbgui::GUIMenus::gmnNumeroDeBotones()
{
	return losBotones.count();
}

int sbgui::GUIMenus::gmnId() const
{
	return mnid;
}
