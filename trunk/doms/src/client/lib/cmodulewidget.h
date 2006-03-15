//
// C++ Interface: cmodulewidget
//
// Description: 
//
//
// Author: David Cuadrado <krawek@gmail.com>, (C) 2006
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef CMODULEWIDGET_H
#define CMODULEWIDGET_H

#include <qwidget.h>

/**
	@author David Cuadrado <krawek@gmail.com>
*/
class CModuleWidget : public QWidget
{
	Q_OBJECT;
	public:
		CModuleWidget(const QString &moduleMame, QWidget *parent = 0);
		~CModuleWidget();
};

#endif
