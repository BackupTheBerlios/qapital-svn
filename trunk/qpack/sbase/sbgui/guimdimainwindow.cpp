/* Clase: GUIMdiMainWindow
 * Autor: CetiSoft
 * Version: 0.0.1
 * Fecha de creacion: /08/2004
 * Fecha de modificacion:
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

#include "guimdimainwindow.h"

/**
 * Constructor por defecto
 */
sbgui::GUIMdiMainWindow::GUIMdiMainWindow()
	: QMainWindow(0, QObject::tr("Ventana Principal"), WType_TopLevel), parser(0)
{
}

/**
 * Destructor
 */
sbgui::GUIMdiMainWindow::~GUIMdiMainWindow()
{
}

/**
 * Pone el XML de la interfaz.
 * @b NOTA: esta funcion hace parte del motor de creacion de GUI en base a archivos XML.
 */
void sbgui::GUIMdiMainWindow::ponerXML(const QString &filestr)
{
	QFile file(filestr);
	if (! file.open(IO_ReadOnly))
	{
		std::cerr << "GADMainWindow::ponerXML(): Error abriendo el archivo " << filestr << std::endl;
		return;
	}
	
	QXmlInputSource sourceXML(file);
	file.close();
	parser = new GUIMdiXMLParser();
	QXmlSimpleReader reader;
	reader.setContentHandler( parser );
	if ( ! reader.parse( &sourceXML, true ) )
	{
		std::cerr << "GADMainWindow::ponerXML(): No se pudo analizar" << std::endl;
	}
}

/**
 * Funcion encargada de crear la GUI.
 * @b NOTA: esta funcion hace parte del motor de creacion de GUI en base a archivos XML.
 */
void sbgui::GUIMdiMainWindow::crearGUI()
{
	if( parser )
	{
		QStringList nombres = parser->obtenerNombres();
		HashMenu menusInfo = parser->obtenerMenus();

		for(uint i = 0; i < nombres.count(); i++)
		{
			QToolBar *toolBarTmp = new QToolBar(this, nombres[i]);
			moveDockWindow(toolBarTmp, Qt::DockTop);

			toolBarTmp->show();

			QStringList *strlistTmp = menusInfo.find((nombres)[i]);
			
			if (strlistTmp == 0)
			{
				std::cout << "GADMainWindow::crearGUI(): Error" << std::endl;
				return;
			}

			for (uint j = 0; j < strlistTmp->count(); j+=3)
			{
				QAction *actTmp = new QAction(toolBarTmp, (*strlistTmp)[j]);
				connect( actTmp, SIGNAL( activated() ) , this, SLOT( slotPrincipal() ) );
				
				// FIXME: colocar la ruta bien.
				QPixmap pm( sbqpack::GUIDATADIR + (*strlistTmp)[j+1]);
				if ( ! pm.isNull() )
					actTmp->setIconSet( pm );
				
				actTmp->setToolTip( (*strlistTmp)[j+2] );
				
				actTmp->addTo(toolBarTmp);
			}
		}
	}
}
