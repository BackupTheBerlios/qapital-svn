#include "gclprincipal.h"
#include <qapplication.h>
#include "gclcrearcliente.h"
#include "guihelp.h"
#include <iostream>

int main( int argc, char **argv )
{
	QApplication app( argc, argv );
	//GUIHelp qpMainWindow(0);
	GCLPrincipal qpMainWindow(0, 0,"sad");
	//qpMainWindow.resize( menus.sizeHint()  );
	
	app.setMainWidget( &qpMainWindow );
	qpMainWindow.show();
        return app.exec();
}
