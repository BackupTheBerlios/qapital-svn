#ifndef SBLOGGER_H
#define SBLOGGER_H

#include <qdir.h>
#include <qprocess.h>
#include <qtextstream.h>
#include <qdatetime.h>
#include <qvaluelist.h>
#include <qobject.h>
#include <unistd.h>
#include <iostream>

#define QPINFO(s) std::cout << "\033[1;32m * \033[0;0m" << s << std::endl;
#define QPWARN(s) std::cout << "\033[1;33m" << " * " << "\033[0;0m" << s << std::endl;
#define QPERROR(s) std::cout << "\033[1;31m" << " * " << "\033[0;0m" << s << std::endl;

class SBLogger : public QObject
{        
  	private:
		Q_UINT16 entidad;
		
		QString salvarFechaLog;
	       	QString salvarHoraLog;
		
		QString RUTA_LOGS;
 		QString RUTA_DEFECTO_SERVIDOR; 
 		QString RUTA_DEFECTO_CLIENTE; 
 		QString FORMATEO_DEFECTO_HORA;
 		QString FORMATEO_DEFECTO_FECHA;
		
		QString textoAloguear;
	       	QString UBICACION;
	       	QString PRIORIDAD;
	       	QString NIVEL;
		Q_UINT16 nivel;
		Q_UINT16 prioridad;
					
	public:
		SBLogger(Q_UINT16 nivel, QString ruta);
               ~SBLogger();
	      
	       	QString rutaLogServidor();
	       	QString rutaLogCliente();   
	       	QString fechaLog();
	       	QString horaLog();
	       	QString obtenerNivel();
	       	
		void salvarLog(Q_UINT16 nivel, Q_UINT16 entidad, QString texto);   
		
		enum Prioridad { QP_INFO = 0 , QP_WARNING,  QP_ERROR };
		enum Nivel { LOGFILE = 0 , VERBOSEFILE, VERBOSE  };
		enum Entidades { CLIENTE = 0 , ADMIN, SERVIDOR , NONE  };
	
	protected:
	       	void asignarPrioridad( Q_UINT16 );
	       	void asignarNivel( Q_UINT16 );
		void ponerEntidad(Q_UINT16 donde);
		void guardarEnArchivo();
	       	void mostrarEnPantalla(QString mensaje);
		void iniciarLogger();
};

#endif
