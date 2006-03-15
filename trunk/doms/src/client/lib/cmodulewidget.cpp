//
// C++ Implementation: cmodulewidget
//
// Description: 
//
//
// Author: David Cuadrado <krawek@gmail.com>, (C) 2006
//
// Copyright: See COPYING file that comes with this distribution
//
//

#include "cmodulewidget.h"
#include <QVBoxLayout>
#include <QLabel>

CModuleWidget::CModuleWidget(const QString &moduleMame, QWidget *parent) : QWidget(parent)
{
	QVBoxLayout *layout = new QVBoxLayout(this);
	
	layout->addWidget(new QLabel("Este es el modulo: "+moduleMame));
}


CModuleWidget::~CModuleWidget()
{
}


