/* Clase: GUITelefonos
 * Autor: CetiSoft
 * Version: 0.0.1
 * Fecha de creacion: 14/08/2004
 * Fecha de modificacion: 15/08/2004
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

#include "guitelefonos.h"

GUITelefonos::GUITelefonos(QWidget *parent, const char *name) : GUIFormularios(parent, name)
{
	encabezado << tr("Descripcion") << tr("Telefono") << tr("Departamento") << tr("Municipio") << tr("Tipo de Telefono");
	crearTabla(encabezado);
	crearFormulario(encabezado);
	crearBotones();
	qDebug( "[GUITelefonos consturido]" );
}


GUITelefonos::~GUITelefonos()
{
	qDebug( "[GUITelefonos destruido]" );
}


void GUITelefonos::crearFormulario(QStringList cabecera)
{
	formulario = new QFrame(this);
	gridFormulario = new QGridLayout(formulario,4,1);
	
	descripcion= new QLabel( cabecera[0], formulario);
	capturaDescripcion = new QLineEdit(formulario);
	gridFormulario->addWidget(descripcion,0,0);
	gridFormulario->addWidget(capturaDescripcion,0,1);
	
	telefono = new QLabel(cabecera[1], formulario);
	capturaTelefono = new QLineEdit(formulario);
	gridFormulario->addWidget(telefono,1,0);
	gridFormulario->addWidget(capturaTelefono,1,1);
	
	departamento = new QLabel(cabecera[2] , formulario);
	selecionarDepartamento= new QComboBox(false, formulario);
	selecionarDepartamento->insertItem(tr("Valle")); //aqui se inserta la lista de departamentos
	
	connect(selecionarDepartamento, SIGNAL(activated(int)), this, SLOT(departamentoSelecionado(int)));
	connect(selecionarDepartamento, SIGNAL(highlighted(int)), this, SLOT(departamentoSelecionado(int)));
	
	gridFormulario->addWidget(departamento,2,0);
	gridFormulario->addWidget(selecionarDepartamento,2,1);
	
	municipio = new QLabel(cabecera[3] , formulario);
	selecionarMunicipio= new QComboBox(false,formulario);
	gridFormulario->addWidget(municipio,3,0);
	gridFormulario->addWidget(selecionarMunicipio,3,1);
	selecionarMunicipio->setEnabled(false);
	
	tipoTelefono = new QLabel(cabecera[4], formulario);
	selecionarTipo= new QComboBox(false,formulario);
	selecionarTipo->insertItem(tr("Fijo"));
	selecionarTipo->insertItem(tr("Celular"));
	gridFormulario->addWidget(tipoTelefono,4,0);
	gridFormulario->addWidget(selecionarTipo,4,1);

}

void GUITelefonos::departamentoSelecionado(int index)
{
	selecionarMunicipio->setEnabled(true);
	selecionarMunicipio->clear();
	//falta tomar las lista de los municipios y departamentos de la base de datos
	
	switch(index)
        {
		case 0:
			selecionarMunicipio->insertItem(tr("Cali")); // cidudad->insertStringList(ciudadesValle) siendo index == 0
		break;
		
		case 1:
			selecionarMunicipio->insertItem(tr("otra")); // cidudad->insertStringList(ciudadesValle) siendo index == 0
		break;
			default: std::cout << "GUIDirecciones:departamentoSelecionado error" << std::endl;; // sistema de errores
		break;
	}
}

void GUITelefonos::clickedInsertar()
{
	listaDeDatos.append(capturaDescripcion->text());
	listaDeDatos.append(capturaTelefono->text());
	listaDeDatos.append(selecionarDepartamento->text(selecionarDepartamento->currentItem ()));
	listaDeDatos.append(selecionarMunicipio->text(selecionarDepartamento->currentItem ()));
	listaDeDatos.append(selecionarTipo->text(selecionarTipo->currentItem() ));	
	tabla->llenarTabla(listaDeDatos);
	capturaDescripcion->setText("");
	capturaTelefono->setText("");
}
