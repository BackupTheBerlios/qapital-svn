/* Clase: GUIMenus
 * Autor: CetiSoft
 * Version: 0.0.1
 * Fecha de creacion: 18/6/2004
 * Fecha de modificacion: 14/7/2004
 * Relacion con objetos: 	es un QButtonGroup
 * Descripcion:	 Esta clase es la base para la construccion de  menus de botones a partir de la cantidad de filas y columnas.
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


#ifndef GUIMENUS_H
#define GUIMENUS_H

#include <qstringlist.h> 
#include <qbuttongroup.h> 
#include <qlayout.h>
#include <qstring.h> 
#include <qvaluelist.h>
#include <qradiobutton.h> 
#include <qpushbutton.h> 
#include <iostream>
#include <guilectorxml.h>
#include <qfile.h>
#include <qiodevice.h>
#include <qstringlist.h>
#include <guilectorxml.h>

typedef QValueList<QPushButton*> ListaDeBotones;
typedef QValueList<QRadioButton*> ListaDeRadio;


namespace sbgui
{
/**
	@author CetiSoft
 */

	class GUIMenus : public QButtonGroup
	{
		Q_OBJECT
		private:
			int gmnFilas, gmnColumnas;
			const int mnid;
			ListaDeBotones losBotones;
			ListaDeRadio losRadios;
			void generarMenus(int, int);
			QStringList listaDeFunciones;
	
		public:
			GUIMenus(QWidget *padre = 0, const char *nombre = 0, int filas = 0, int columnas = 0, int mnid = -1);
		
			// Constructor de menus con XML
			GUIMenus(QWidget *padre, const char *nombre, GUILectorXml *, int mnid);
			~GUIMenus();
			void gmnDesabilitar();
			//void gmnCambiarTexto(QString);
			void gmnCambiarTextoDeBoton(QString , int);
			int gmnNumeroDeBotones();
			int gmnId() const;
		
		protected:
			QGridLayout *gmnGridBase;
	};
}
#endif
