/* Clase: GCLPrincipal
 * Autor: CetiSoft
 * Version: 0.0.1
 * Fecha de creacion: 15/07/2004
 * Fecha de modificacion: 15/08/2004
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
 
 
#include "gclprincipal.h"
#include <qapplication.h>

//using namespace qapital;

/**
 * Constructor
*/

qpcgui::GCLPrincipal::GCLPrincipal( qpcred::ClnRed *cnx, QWidget *parent, const char *name) : QMainWindow(parent, name), NUMERO_DE_BOTONES(4), idActual(0), conexion(cnx)
{
	qDebug( "[Construyendo GCLPrincipal]" );
	setCaption(sbqpcliente::APPNAME + " v" + sbqpcliente::VERSION );
	setIcon(QPixmap(sbqpack::GUIDATADIR + QString("iconos/qplogo.png")) );
	this->init();
//	this->crearMenus();
	this->crearBarras();
}

/**
Destructor
*/
qpcgui::GCLPrincipal::~GCLPrincipal()
{
	qDebug( "[GCLPrincipal destruido]" );
}

/**
Descripcion: Esta funcion sirve para inicializar la GUI de la ventana principal
*/
void qpcgui::GCLPrincipal::init()
{
	gcpFrame = new QVGroupBox(this);
	gcpTitulo = new sbgui::GUITitulo(gcpFrame, "Titulo", sbqpack::GUIDATADIR + "iconos/qplogo1.png", sbqpcliente::VERSION);

	ventanaLogin = new GCLogin(gcpFrame);
	connect(ventanaLogin, SIGNAL(gclFueClickeado()), SLOT(gcpContinuar()) );

	setCentralWidget(gcpFrame);
	gcpFrame->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred, false);
	statusBar();
	if ( conexion )
		conexion->conectar();
	show();
}

/**
Esta funcion se encarga de crear los menus
*/

void qpcgui::GCLPrincipal::crearMenus()
{
	QFile *archivoXML = new QFile(sbqpcliente::XMLCLIENTDATADIR + "guimenus.xml");
	QXmlInputSource *source = new QXmlInputSource( archivoXML );
	QXmlSimpleReader reader;
	sbgui::GUILectorXml *handler = new sbgui::GUILectorXml();
	reader.setContentHandler( handler );
	
	if ( ! reader.parse( source, true ) )
	{
		qDebug("GCLPrincipal/GCLPrincipal: No se pudo leer el XML");
	}
	
	std::cout << "Numero de menus: " << handler->obtenerNumeroDeMenus() << std::endl;
	for (int i = 0; i < handler->obtenerNumeroDeMenus(); i++)
	{
		gcpEntrada = new sbgui::GUIMenus(gcpFrame, "Menu/XML", handler, i);
		gcpEntrada->resize( gcpEntrada->sizeHint() );
		connect(gcpEntrada,SIGNAL(clicked(int)),this,SLOT(gcpBotonClickeado(int)) );
		menus.append( gcpEntrada );
		gcpContenedor->addWidget( gcpEntrada, i );
	}
}

/**
esta funcion se encarga de crear las barras de herramientas, en el momento esta incompleta, se leera de un archivo XML.
*/
void qpcgui::GCLPrincipal::crearBarras()
{
	gcpBarraIconos = new sbgui::GUIBarraIconos(this, "barra", NUMERO_DE_BOTONES);
	gcpBarraIconos->setMovingEnabled(false);
	gcpBarraIconos->setOffset ( 10 );
	
	gcpBarraIconos->gbrPonerIcono(sbqpack::GUIDATADIR + "iconos/back.png", 0);
	gcpBarraIconos->gbrPonerIcono(sbqpack::GUIDATADIR + "iconos/next.png", 1);
	gcpBarraIconos->gbrPonerIcono(sbqpack::GUIDATADIR + "iconos/frameprint.png", 2);
	gcpBarraIconos->gbrPonerIcono(sbqpack::GUIDATADIR + "iconos/error.png", 3);
	
	moveDockWindow(gcpBarraIconos,Qt::DockBottom);
	
	connect(gcpBarraIconos,SIGNAL(gbrClicked(int )),this,SLOT(gcpBotonClickeado(int)));
}

/**
crea las formas de la interfaz.
*/
void qpcgui::GCLPrincipal::crearFormas()
{
	ayuda = new sbgui::GUIHelp(0);
	configurarEmpresa = new GCLConfiguraEmpresa(0);
}

/**
Muestra el widget especificado.
@param id: identificador del widget.
*/
void qpcgui::GCLPrincipal::gcpCambiarWidget(uint id)
{
	if ( id < menus.count() )
	{
		idActual = id;
		gcpContenedor->raiseWidget( id );
	} else
		qDebug("gclprincipal.cpp: gcpCambiarWidget(): error cambiando el widget.");
}

/**
Funcion sobrecargada, cambia el widget especificado
*/
void qpcgui::GCLPrincipal::gcpCambiarWidget(sbgui::GUIMenus *menu)
{
	idActual = menu->gmnId();
	gcpContenedor->raiseWidget( menu );
}

/**
Aqui se hace la autentificacion del usuario. (falta).
@todo
- Se debe crear el archivo XML con los usuairos habituales.
- Se debe completar la autentificacion, recibir el paquete ACP proveniente del ST.
*/

void qpcgui::GCLPrincipal::gcpContinuar()
{
	// FALTA: "DBMidas" debe ser leido de ventanaLogin!!
	this->conectar();
	QTimer::singleShot(100, this, SLOT(gcpEnviarAuth()) );
}

bool qpcgui::GCLPrincipal::conectar()
{
	if ( ! conexion )
		return false;
	if (! conexion->estaConectado())
	{
		conexion->conectar();
	} 
	return conexion->estaConectado();
}
	
void qpcgui::GCLPrincipal::gcpEnviarAuth()
{
	sbxml::SbXmlCNX cnxXML("DBMidas", ventanaLogin->obtenerLogin(), ventanaLogin->obtenerPassword() );
	
	if ( conexion->estaConectado() )
	{
		conexion->clnEnviarAlServer(cnxXML);
		
		gcpContenedor = new QWidgetStack(gcpFrame, "contenedor");
		gcpContenedor->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding, false);
		crearMenus();
		crearFormas();

		delete ventanaLogin;
		gcpContenedor->show();
	}	
}

void qpcgui::GCLPrincipal::gcpAnadirWidget(QWidget *nuevo, int id)
{
	gcpContenedor->addWidget(nuevo, id);
}


/*
gcpBotonClickeado:
*/
void qpcgui::GCLPrincipal::gcpBotonClickeado(int id)
{
	for (uint i = 0; i < menus.count(); i++)
	{
		if(QObject::sender() == menus[i] )
		{
			std::cout << "Menu id: " << menus[i]->gmnId() << std::endl;
			switch((int) (menus[i]->gmnId()) )
			{
				// Menu inicial
				case 0:
				{
					switch(id)
					{
						// Contabilidad
						case 0:
						{
							//std::cout << id << std::endl;
							gcpCambiarWidget (menus[1]);
							break;
						}
						//Configurar empresa
						case 1:
						{
							//std::cout << id << std::endl;
							//gcpCambiarWidget (menus[3]);
							configurarEmpresa->show();
							break;
						}
						
						// Ayuda
						case 3:
						{
							//std::cout << id << std::endl;
							ayuda->show();
							break;
						}
					}
					break;
				}
				// Menu contable
				case 1:
				{
					//std::cout << id << std::endl;
					gcpCambiarWidget ( menus[2] );
					break;
				}
				
				// Menu de acciones nuevo/editar/borrar/consultar
				case 2:
				{
//					switch(id)
//					{
//					}
					break;
				}
				
				/*case 3:
				{
					switch(id)
					{
						case 0:
						{
							GUIFormularioGeneral *confEmpresa = new GUIFormularioGeneral(0);
							confEmpresa->show();
							break;
						}
						case 1:
						{
							GUIDirecciones *confEmpresa = new GUIDirecciones(0);
							confEmpresa->show();
							break;
						}
						break;
						case 2:
						{
							GUITelefonos *confEmpresa = new GUITelefonos(0);
							confEmpresa->show();
							break;
						}
						
						case 3:
						{
							GUIEMail *confEmpresa = new GUIEMail(0);
							confEmpresa->show();
							break;
						}
						
					}
				}*/
				
				default:
				{
					std::cout << "error" << std::endl; // sistema de errores
					break;
				}
			}
			break;
		}
	}

	if( QObject::sender() == gcpBarraIconos )
	{
		switch(id)
		{
			case 0:
			{
				std::cout << idActual - 1 << std::endl;
				this->gcpCambiarWidget( idActual - 1);
				break;
			}
			case 1:
			{
				std::cout << idActual + 1 << std::endl;
				this->gcpCambiarWidget( idActual + 1 );
				break;
			}
			case 2:
			{
				break;
			}
			case 3:
			{
				QApplication::exit(0);
				break;
			}
		}
	}
}

