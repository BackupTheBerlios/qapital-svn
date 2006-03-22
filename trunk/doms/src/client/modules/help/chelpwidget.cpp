/***************************************************************************
 *   Copyright (C) 2005 by David Cuadrado <krawek@gmail.com>               *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 ***************************************************************************/

#include "chelpwidget.h"
#include <qlayout.h>
#include <qtabwidget.h>
#include <qdom.h>
#include <qfile.h>
#include <qmap.h>

#include "ddebug.h"

#include <QLocale>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QHeaderView>

#include "dglobal.h"

CHelpWidget::CHelpWidget(QWidget *parent) : CModuleWidget(tr("Help"), parent)
{
	setWindowIcon(QPixmap(THEME_DIR+"/icons/help.png"));
	
	connect(m_pTree, SIGNAL(itemClicked ( QTreeWidgetItem *, int )), this, SLOT(tryToLoadPage(QTreeWidgetItem *, int)));
	
// 	m_pTree->setRootIsDecorated(true);
// 	m_pTree->addColumn(tr("Topics"));
	
	m_helpPath = QDir(DATA_DIR);
	
	QDomDocument document;
	
	dDebug() << m_helpPath.path();
	
	QFile file( m_helpPath.path()+"/help.xml" );
	
	if ( file.open( QIODevice::ReadOnly ) )
	{
		if ( document.setContent(&file) )
		{
			QDomElement root = document.documentElement();
			
			QDomNode section = root.firstChild();
			while( !section.isNull() )
			{
				QDomElement element = section.toElement();
				if( !element.isNull() )
				{
					if ( element.tagName() == "Section" )
					{
						QTreeWidgetItem *item = new QTreeWidgetItem(m_pTree);
						item->setText(0, element.attribute("title"));
						
						QDomNode subSection = element.firstChild();
						while( ! subSection.isNull())
						{
							QDomElement element2 = subSection.toElement();
							if ( !element2.isNull() )
							{
								if ( element2.tagName() == "SubSection" )
								{
									QTreeWidgetItem *subitem = new QTreeWidgetItem(item);
									subitem->setText(0, element2.attribute("title"));
									
									m_files.insert(subitem, element2.attribute("file"));
								}
							}
							subSection = subSection.nextSibling();
						}
					}
				}
				section = section.nextSibling();
			}
		}
		else
		{
			qDebug("CHelpWidget::Can't set contents");
		}
		file.close();
	}
	else
	{
		qDebug("CHelpWidget::Can't open");
	}
	
	m_pTree->setEditable( false );
}

CHelpWidget::~CHelpWidget()
{
}

void CHelpWidget::tryToLoadPage(QTreeWidgetItem *item, int)
{
	if ( item )
	{
		QString fileName = m_files[item];
		if ( ! fileName.isNull() )
		{
			loadPage(item->text(0), m_helpPath.path()+"/"+ fileName);
		}
	}
}

void CHelpWidget::loadPage(const QString &title, const QString &filePath)
{
	dDebug() << "Loading: "+filePath;
/*	
	QFile file(filePath);
	QFileInfo finfo(file);
	
	if ( finfo.exists() && !finfo.isDir() && file.open( QIODevice::ReadOnly | QIODevice::Text ) )
	{
		QTextStream ts(&file);
		
		QString document = "";
		while( ! ts.atEnd() )
		{
			document += ts.readLine();
		}
		
		file.close();
		
		if ( document != "" )*/
	emit pageLoaded(title, filePath);
// 	}
	
}

QString CHelpWidget::helpPath () const
{
	return m_helpPath.path();
}
