/* Clase: GUITabla
 * Autor: CetiSoft
 * Version: 0.0.1
 * Fecha de creacion: 10/08/2004
 * Fecha de modificacion:15/08/2004
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

#include "guitabla.h"

GUITabla::GUITabla(int filas, QStringList encabezado, QWidget *parent, const char *name)
:QTable(parent, name)
{
	QHeader *header = horizontalHeader();
	{	
		header->setMovingEnabled(true);
		setNumCols(encabezado.count());
		setNumRows(filas);
		for(uint i = 0; i < encabezado.count(); i++)
		{ 
			header->setLabel( i, tr(encabezado[i]) );
			adjustColumn(i);
		}
		connect(this, SIGNAL(valueChanged(int,int) ), SLOT(ajustarTamano(int, int)));
		show();
	}
	setReadOnly ( true );
}


GUITabla::~GUITabla()
{
}

void GUITabla::ajustarTamano(int fila, int columna)
{
	adjustColumn(columna);
	if (fila + 1 == numRows())
	{
		insertRows ( fila+1, 10);
	}
}

//implementar llenarFila

void GUITabla::llenarTabla(QStringList strlist)
{
	int cont = 0;
	for ( uint f = 0; f < strlist.count() / numCols(); f++)
	{
		for ( uint c = 0; c < numCols(); c++)
		{
			setText ( f, c, strlist[cont ]);
			adjustColumn(c);
			cont++;
		}
	}
}

QStringList GUITabla::obtenerDatos()
{
	QStringList datos;
	int cont = 0;
	for ( int f = 0; f < numRows() / numCols(); f++)
	{
		for (int c = 0; c < numCols(); c++)
		{
			datos.append(text( f, c));
			adjustColumn(c);
			cont++;
		}
	}
	return datos;
}

void GUITabla::removerFilaSeleccionada()
{
	for(int fila = 0; fila <= numRows(); fila++)
	{
		if ( isRowSelected( fila, false))
		{
			removeRow(fila);
			insertRows(numRows(), 1);
			break;
		}
		
		else
		{
			qDebug("GUIFormularios::removerFilaSeleccionada() no hay ninguna fila seleccionada");
		}
	}
}

