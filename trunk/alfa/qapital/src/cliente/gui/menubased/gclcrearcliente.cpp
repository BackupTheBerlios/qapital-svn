/* Clase: GCLCrearCliente
 * Autor: CetiSoft
 * Version: 0.0.1
 * Fecha de creacion: 15/07/2004
 * Fecha de modificacion:10/8/2004
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
#include "gclcrearcliente.h"
#include "iostream"

/*
falta hacer que todos los datos del cliente se escriban en la gccTablaDatos
*/
GCLCrearCliente::GCLCrearCliente(QWidget *padre, const char *nombre)
 : QGroupBox(padre, nombre)
{
	gccGridBase = new QGridLayout(this,3,1);
	gccCrearFormulario();
//	gccCrearTabla();
	insertar = new QPushButton("insetar", this);
	gccGridBase->addWidget(insertar,3,1);
	connect(insertar, SIGNAL(clicked()), this, SLOT(gccClikedInsertar()));
}

GCLCrearCliente::~GCLCrearCliente()
{
}

void GCLCrearCliente::gccCrearFormulario()
{
	gccFormulario = new QWidget(this, "formulario central");
	gccGridFormulario = new QGridLayout(gccFormulario, 6,2, 10);
	gccPNombre = new QLabel(tr("Nombre"), gccFormulario);
	gccLNombre = new QLineEdit(gccFormulario);
	gccPNombre->setBuddy(gccLNombre);
	
	gccGridFormulario->addWidget(gccPNombre,0,0);
	gccGridFormulario->addWidget(gccLNombre,0,1);
	
	gccPIdent = new QLabel(tr("Nit/C.C"), gccFormulario);
	gccLIdent = new QLineEdit(gccFormulario);
	gccPIdent->setBuddy(gccLIdent);

	gccGridFormulario->addWidget(gccPIdent,1,0);
	gccGridFormulario->addWidget(gccLIdent,1,1);
	
	gccPDireccion = new QLabel(tr("Dirección"),gccFormulario);
	gccLDireccion = new QLineEdit(gccFormulario);
	gccPDireccion->setBuddy(gccLDireccion);

	gccGridFormulario->addWidget(gccPDireccion,2,0);
	gccGridFormulario->addWidget(gccLDireccion,2,1);
	
	gccPTelefono = new QLabel(tr("Telefono"), gccFormulario);
	gccTelefono = new QComboBox(true, gccFormulario);
	gccPTelefono->setBuddy(gccTelefono);

	gccGridFormulario->addWidget(gccPTelefono,3,0);
	gccGridFormulario->addWidget(gccTelefono,3,1);
	
	gccPCiudad = new QLabel(tr("Ciudad"), gccFormulario);
	gccCiudad = new QComboBox( false, gccFormulario);
	gccPCiudad->setBuddy(gccCiudad);
	gccCiudad->setEnabled(false);
	gccGridFormulario->addWidget(gccPCiudad,5,0);
	gccGridFormulario->addWidget(gccCiudad,5,1);
	
	gccPDepartamento = new QLabel(tr("Departamento"), gccFormulario);
	gccDepartamento = new QComboBox( FALSE, gccFormulario);
	connect(gccDepartamento, SIGNAL(activated(int)), this, SLOT(gccSelectDepartamento(int)));
	connect(gccDepartamento, SIGNAL(highlighted(int)), this, SLOT(gccSelectDepartamento(int)));

	gccDepartamento->insertItem(tr("Valle"));
	gccDepartamento->insertItem(tr("SDF"));
	
	gccGridFormulario->addWidget(gccPDepartamento,4,0);
	gccGridFormulario->addWidget(gccDepartamento,4,1);
	
	//c1->insertStringList ( const QStringList & list, int index = -1 )
	//saber como vamos a meter las ciudades y departamentos
	gccGridBase->addWidget(gccFormulario,1,1);
}

void GCLCrearCliente::gccCrearTabla()
{
//	gccTabla = new GUITabla(10, 6, this);
// 	gccGridBase->addWidget(gccTabla,2,1);
// 	gccTabla->setNoEditable();
// 	gccTabla->horizontalHeader()->setLabel( 0, tr( "nombre" ) );
// 	gccTabla->horizontalHeader()->setLabel( 1, tr( "doc ident" ) );
// 	gccTabla->horizontalHeader()->setLabel( 2, tr( "direccion" ) );
// 	gccTabla->horizontalHeader()->setLabel( 3, tr( "telefono" ) );
// 	gccTabla->horizontalHeader()->setLabel( 4, tr( "depatamento") );
// 	gccTabla->horizontalHeader()->setLabel( 5, tr( "ciudad" ) );
}


void GCLCrearCliente::gccSelectDepartamento(int index)
{
	gccCiudad->setEnabled(true);
	gccCiudad->clear();
	//falta definir las listas de ciudades puede ser incluida en un xml o en la base de datos
	
	switch(index)
        {
		case 0:
			gccCiudad->insertItem(tr("Cali")); // cidudad->insertStringList(ciudadesValle) siendo index == 0
		break;
		
		case 1:
			gccCiudad->insertItem(tr("otra")); // cidudad->insertStringList(ciudadesValle) siendo index == 0
		break;
			default: std::cout << "GCLCrearCliente:gccSelectDepartamento" << std::endl;; // sistema de errores
		break;
	}
}

void GCLCrearCliente::gccClikedInsertar()
{
	//falta: validar datos
	listaDeDatos.append(gccLNombre->text());
	listaDeDatos.append(gccLIdent->text());
	listaDeDatos.append(gccLDireccion->text());
	listaDeDatos.append(gccTelefono->text(gccTelefono->currentItem ())); ///esto hay que arreglarlo
	listaDeDatos.append(gccDepartamento->text(gccDepartamento->currentItem ()));
	listaDeDatos.append(gccCiudad->text(gccCiudad->currentItem()));
//	gccTabla->llenarTabla(listaDeDatos);
}

