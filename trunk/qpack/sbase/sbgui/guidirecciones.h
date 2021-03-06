/* Clase: GUIDirecciones
 * Autor: CetiSoft
 * Version: 0.0.1
 * Fecha de creacion: 14/08/2004
 * Fecha de modificacion: 15/08/2004
 * Relacion con objetos:
 * Descripcion:  
 * 		Esta clase se encarga de pedir las direcciones.
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

#ifndef GUIDIRECCIONES_H
#define GUIDIRECCIONES_H

#include <qvgroupbox.h> 
#include <qwidget.h>
#include <qpushbutton.h>
#include <qtable.h>
#include <qlabel.h> 
#include <qlayout.h>
#include <qcombobox.h> 
#include <qlineedit.h> 
#include <qpushbutton.h>
#include <qstringlist.h>
#include <qframe.h>

#include "guiformularios.h"


namespace sbgui
{
	/**
	 * @author CetiSoft
	 */
	class GUIDirecciones : public GUIFormularios
	{
		Q_OBJECT
	
		private:
			QLabel *descripcion, *direccion, *departamento, *municipio;
			QLineEdit *capturaDescripcion,*capturaDireccion;
			QComboBox *selecionarDepartamento, *selecionarMunicipio;
			QFrame *formulario;
			QStringList encabezado, listaDeDatos;
	
		public:
			GUIDirecciones(QWidget *parent = 0, const char *name = 0);
			~GUIDirecciones();
			void crearFormulario(QStringList cabecera);
			QStringList obtenerDatos();
			
		public slots:
			void clickedInsertar();
			void departamentoSelecionado(int);
		
		protected:
			QGridLayout * gridFormulario;
	};
}
#endif
