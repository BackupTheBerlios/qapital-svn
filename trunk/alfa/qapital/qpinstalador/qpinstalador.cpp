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
#include "qpinstalador.h"

QPInstalador::QPInstalador(QWidget *parent, const char *name)
 : QWizard(parent, name), pasos(0)
{
	crearTitulo();
	crearConfig();
	
	frameCompilador = new QVGroupBox(this);
//	compiladorLayout = new QGridLayout (frameCompilador, 2,2 );
//	configLayout->setRowSpacing(2, 70);
	
	compilar = new QTextView(frameCompilador);
	compilar->resize(300,400);
	
	progress = new QProgressBar(58, frameCompilador);
	
	addPage(frameCompilador, "compilando");
	
	resize(sizeHint() );
	show();
	
	timer = new QTimer(this);
	connect(timer, SIGNAL(timeout()), this, SLOT(aumentar()) );
}


QPInstalador::~QPInstalador()
{
	std::cout << "[destruyendo]" << std::endl;
/*	if (proc)
	{
		if (proc->isRunning() )
		{
			proc->kill();
		}
	}
*/
}

void QPInstalador::crearTitulo()
{
	tituloLabel = new QLabel("Aqui queda la presentacion", this);
	tituloLabel->setAlignment (Qt::AlignCenter);
	tituloLabel->setPixmap( QPixmap("artwork/presentacion.png"));
	
	addPage(tituloLabel, "Qapital v0.0.1a");
}

void QPInstalador::crearConfig()
{
	config = new QVGroupBox(this);
	
	llenar = new QLabel(tr("Por favor llene los siguientes campos: "), config);
	
	ruta = new QLabel( tr("Fuentes: "), config);
	qppath = new QLineEdit(config);
	qppath->setText("../qapital/");	

	addPage(config, "Configuracion...");
}

void QPInstalador::next()
{
	std::cout << "Se presiono next() " << std::endl;
	if (currentPage() == tituloLabel )
	{
		showPage(config);
	}
	else if (currentPage() == config )
	{
		std::cout << "Compilando...\n";
		showPage(frameCompilador);
		proc = new QProcess(this);
		std::cout << "Ruta: " << qppath->text() << std::endl;
		QDir dir(qppath->text());
		proc->setWorkingDirectory(dir);
	
		connect( proc, SIGNAL(readyReadStdout()), this, SLOT(leerSalida()) );
		connect (proc, SIGNAL(readyReadStderr()), this, SLOT(leerError()) );
	
		progress->setProgress(progress->progress() + 1);
		proc->addArgument("qmake");
		if ( ! proc->start() ) 
		{
			std::cout << "No se pudo ejecutar qmake\n";
		}
	
		proc = new QProcess(this);
		proc->setWorkingDirectory(dir);
		connect( proc, SIGNAL(readyReadStdout()), this, SLOT(leerSalida() ));
		connect (proc, SIGNAL(readyReadStderr()), this, SLOT(leerError() ));	
		
		resize(sizeHint() );
		
		proc->addArgument("make");
		if ( ! proc->start() )
		{
			std::cout << "no se pudo compilar\n";		
		}
		progress->setProgress(progress->progress() + 1);
		timer->start(5000, false);
	} else
		std::cerr << "La pagina siguiente no fue encontrada!" << std::endl;
}

void QPInstalador::leerSalida()
{
	compilar->append( proc->readStdout() );
}

void QPInstalador::leerError()
{
	compilar->append (proc->readStderr() );
}

void QPInstalador::aumentar()
{
	std::cout << "Aumentar!" << std::endl;
	if (proc && progress)
	{
		if (proc->isRunning() )
		{
			progress->setProgress(progress->progress() + 1);
		}
		else
		{
			progress->setProgress(progress->totalSteps () );
			timer->stop();
			setFinishEnabled(frameCompilador, true);
			connect ((QPushButton*) finishButton (), SIGNAL(clicked()), proc, SLOT(tryTerminate ()) );
		}
		
		if (proc->isRunning() && progress->progress () == progress->totalSteps() )
			progress->setTotalSteps(progress->totalSteps () + 1 );
	}
}


int main(int argc, char **argv)
{
	QApplication app(argc, argv);
	QPInstalador installer;
	app.setMainWidget(&installer);
	
	installer.show();
	
	return app.exec();
}

