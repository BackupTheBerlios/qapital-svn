/* Clase: GCLPrincipal
 * Autor: CetiSoft
 * Version: 0.0.1
 * Fecha de creacion: 15/7/2004
 * Fecha de modificacion: 15/08/2004
 * Relacion con objetos:
 * Descripcion: Esta clase contiene la instancia de la ventana principal.
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
 
#ifndef GCLPRINCIPAL_H
#define GCLPRINCIPAL_H

#include <qvgroupbox.h> 
#include <qwidget.h>
#include <qmainwindow.h>
#include <qlabel.h>
#include <qwidgetstack.h> 
#include <qtoolbar.h>
#include <qtoolbutton.h>
#include <iostream>
#include <qfile.h>
#include <qxml.h>
#include <qmessagebox.h>
#include <qtimer.h>

#include "sbqpack.h"
#include "sbgui.h"
#include "clnred.h"


#include "gclcrearcliente.h"
#include "gclogin.h"
#include "gclconfiguraempresa.h"

typedef QValueList<GUIMenus*> ListaDeMenus;

/**
@author cetiSoft
*/

class GCLPrincipal : public QMainWindow
{
	Q_OBJECT

	private:
		const int NUMERO_DE_BOTONES;	
		int idActual;			
		GUIMenus *gcpEntrada;
		GUIMenus *gcpSegundo;
		ListaDeMenus menus;
		QWidgetStack *gcpContenedor;
		QVGroupBox *gcpFrame;
		GUIBarraIconos *gcpBarraIconos;
		GCLCrearCliente *gcpClientes;
		GCLogin *ventanaLogin;
		GUITitulo *gcpTitulo;
		GUIHelp *ayuda;
		GCLConfiguraEmpresa *configurarEmpresa;
		ClnRed *conexion;
		
	public:
		GCLPrincipal(ClnRed * cnx, QWidget *parent = 0, const char *name = 0);
		~GCLPrincipal();
		bool conectar();
				
	public slots:
		void gcpCambiarWidget(uint );
		void gcpCambiarWidget(GUIMenus *);
		void gcpBotonClickeado(int );
		void gcpContinuar();
		void gcpAnadirWidget(QWidget *nuevo, int id);
		void gcpEnviarAuth();
				
	protected:
		//QGridLayout *gcpGridBase;
		void init();
		void crearMenus();
		void crearBarras();
		void crearFormas();
};

#endif
