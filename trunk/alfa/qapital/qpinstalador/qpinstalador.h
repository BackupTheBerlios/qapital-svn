/***************************************************************************
 *   Copyright (C) 2004 by krawek                                          *
 *   krawek@linuxmail.org                                                  *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/
#ifndef QPINSTALADOR_H
#define QPINSTALADOR_H

#include <qwizard.h>
#include <qapplication.h>
#include <qframe.h>
#include <qlabel.h>
#include <qlayout.h>
#include <iostream>
#include <qpushbutton.h>
#include <qprocess.h>
#include <qtextview.h>
#include <qpixmap.h>
#include <qlineedit.h>
#include <qprogressbar.h>
#include <qvgroupbox.h>
#include <qtimer.h>

/**
Gui encargado de instalar Qapital

@author krawek
*/

class QPInstalador : public QWizard
{
	Q_OBJECT
	
	private:
		QLabel *tituloLabel;
		
		QVGroupBox *config;
		QLabel *ruta, *llenar;
		QLineEdit *qppath;
		QLineEdit *qpinstall;
		
		QVGroupBox *frameCompilador;
		QTextView *compilar;
		QProgressBar *progress;
		QTimer *timer;
		int pasos;
		
		QProcess *proc;
		QString qapitalPath; // Esta variable se lee en el widget de configuracion.
	
	public:
	    	QPInstalador(QWidget *parent = 0, const char *name = 0);
	    	~QPInstalador();
		void next();
	
	public slots:
		void leerSalida();
		void leerError();
		void crearTitulo();
		void crearConfig();
		void aumentar();
	
	protected:
		QGridLayout *configLayout;
		QGridLayout *compiladorLayout;
};

#endif
