/* Clase: GCLCrearCliente 
 * Autor: CetiSoft
 * Version: 0.0.1
 * Fecha de creacion: 15/07/2004
 * Fecha de modificacion: 10/08/2004
 * Relacion con objetos:  es un QGroupBox  contiene una GCLTabla
 * Descripcion: esta clase crea/obtiene los clientes de la empresa
 *
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
#ifndef GCLCREARCLIENTE_H
#define GCLCREARCLIENTE_H

#include <qwidget.h>
#include <qtable.h>
#include <qlabel.h> 
#include <qlayout.h> 
#include <qcombobox.h> 
#include <qlineedit.h> 
#include <qgroupbox.h> 
#include <qpushbutton.h>
#include <qstringlist.h>

#include "guitabla.h"

namespace qpcgui
{
	/**
	@author cetiSoft
	*/
	
	class GCLCrearCliente : public QGroupBox
	{
		Q_OBJECT
		private:
			QComboBox *gccDepartamento, *gccCiudad, *gccTelefono;
			QLabel *gccPNombre, *gccPIdent, *gccPTelefono, *gccPDireccion, *gccPCiudad, *gccPDepartamento;
			QLineEdit *gccLNombre,*gccLIdent, /**gccLTelefono,*/ *gccLDireccion;
			sbgui::GUITabla *gccTabla;
			QWidget *gccFormulario;
			QPushButton *insertar;
			QStringList listaDeDatos;
			
		public:
			GCLCrearCliente(QWidget *padre = 0, const char *nombre = 0);
			~GCLCrearCliente();
			void gccCrearFormulario();
			void gccCrearTabla();
		protected:
			QGridLayout *gccGridBase;
			QGridLayout *gccGridFormulario;
			
		private slots:
			void gccClikedInsertar();
			void gccSelectDepartamento(int);
	};
}
#endif
