/* Clase: GUITelefonos
 * Autor: CetiSoft
 * Version: 0.0.1
 * Fecha de creacion: 14/08/2004
 * Fecha de modificacion:15/08/2004
 * Relacion con objetos:
 * Descripcion: 
 *		Esta clase se encarga de pedir los telefonos.
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
//  *                                                                         	*
 *   You should have received a copy of the GNU General Public License     	*
 *   along with this program; if not, write to the                         	*
 *   Free Software Foundation, Inc.,                                       	*
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             	*
 *******************************************************************************/

#ifndef GUITELEFONOS_H
#define GUITELEFONOS_H

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
/**
@author CetiSoft
*/
class GUITelefonos : public  GUIFormularios
{
	Q_OBJECT
	
	private:
		QLabel *descripcion, *telefono, *departamento, *municipio, *tipoTelefono;
		QLineEdit *capturaDescripcion,*capturaDireccion, *capturaTelefono;
		QComboBox *selecionarDepartamento, *selecionarMunicipio, *selecionarTipo;
		QFrame *formulario;
		QStringList encabezado, listaDeDatos;
		
	public:
		GUITelefonos(QWidget *parent = 0, const char *name = 0);
		~GUITelefonos();
		void crearFormulario(QStringList cabecera);

		
	public slots:
		void clickedInsertar();
		void departamentoSelecionado(int);
	
	protected:
		QGridLayout * gridFormulario;

};

#endif
