#include "guiprincipal.h"
#include <qapplication.h>
#include <iostream>

int main( int argc, char **argv )
{
	QApplication a( argc, argv );

	GUIPrincipal menus(0,"sad");
	//menu.cambiarTexto("primero");

	/*menu.cambiarTextoUno("0", 0);
	menu.cambiarTextoUno("1", 1);
	menu.cambiarTextoUno("2", 2);
	menu.cambiarTextoUno("3", 3);
	menu.cambiarTextoUno("4", 4);
	menu.cambiarTextoUno("100", 100);
	*/
	//menu.desabilitar();
	menus.resize( menus.sizeHint()  );
	//menus.setminimumSizeHint();
	
	menus.setCaption( "menu" );
	a.setMainWidget( &menus );
	menus.show();
        return a.exec();
}
