/***************************************************************************
 *   Copyright (C) 2006 by David Cuadrado                                  *
 *   krawek@gmail.com                                                      *
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


#include "cmodulewidget.h"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QToolButton>
#include <QHeaderView>
#include <QTimer>


#include <dtreewidgetsearchline.h>

#include "global.h"
#include <ddebug.h>

#include "cselectpackage.h"
#include "cinsertpackage.h"
#include "cdeletepackage.h"
#include "cupdatepackage.h"
#include "cattributeparser.h"

CModuleWidget::CModuleWidget(const QString &moduleMame, QWidget *parent) : QWidget(parent), m_isDirty(false)
{
	QVBoxLayout *layout = new QVBoxLayout(this);
	
	QHBoxLayout *search = new QHBoxLayout;
	
	QToolButton *button = new QToolButton;
	button->setIcon( QIcon(THEME_DIR+"/icons/clear_right.png"));
	
	
	search->addWidget(button);
	
	m_pTree = new DTreeListWidget;
	
	m_pSearch = new DTreeWidgetSearchLine(this, m_pTree);
	
// 	connect(m_pSearch->searchLine();
	
	search->addWidget( m_pSearch );
	
	m_pSearch->setSearchColumns(QList<int>() << 0 );
	
	layout->addLayout(search);
	
	layout->addWidget(m_pTree);
	
	
	connect(button, SIGNAL(clicked()), m_pSearch, SLOT(clear()));
	connect(button, SIGNAL(clicked()), this, SLOT(fill()));
	
	m_pTree->setEditable(false);
}


CModuleWidget::~CModuleWidget()
{
}

CModuleButtonBar *CModuleWidget::addButtonBar(int flags)
{
	CModuleButtonBar *bar = new CModuleButtonBar(flags);
	boxLayout()->addWidget( bar );
	
	return bar;
}

QBoxLayout *CModuleWidget::boxLayout()
{
	return qobject_cast<QVBoxLayout *>(layout());
}

void CModuleWidget::setup(const ModuleInfo &module)
{
	D_FUNCINFO;
	
	// TODO: guardar los campos de la BD
	
	QStringList headers;
	QStringList tables, attributes;
	QString where;
	QTreeWidgetItem *data = new QTreeWidgetItem();
	
	int count = 0;
	foreach(StringPair info, module.listInfo)
	{
		data->setText(count, info.first);
		data->setData(count, Field, info.second);
		
		headers << info.first;
		++count;
	}
	
	m_pTree->setHeaderLabels(headers);
	m_pTree->setHeaderItem(data);
	
	m_pTree->header()->show();
	
	m_pModuleInfo = module;
	
	QTimer::singleShot(500, this, SLOT(fill()));
}

void CModuleWidget::addItem(const QStringList &cols)
{
	QTreeWidgetItem *item = new QTreeWidgetItem(m_pTree);
	int count = 0;
	foreach(QString str, cols)
	{
		item->setText(count, str);
		count++;
	}
}


void CModuleWidget::setOperationResult(const QList<XMLResults> &results)
{
	D_FUNCINFO << results.count();
	
	if ( results.count() > 1 )
	{
		m_pTree->clear();
	}
	
	QTreeWidgetItem *data = m_pTree->headerItem();
	
	foreach(XMLResults res, results)
	{
		QStringList itemData;
		for( int col = 0; col < data->columnCount(); col++ )
		{
			QString fld = data->data(col, Field).toString();
			DBField field = CAttributeParser::parseField( fld );
			
			if ( res.contains( field.name ) )
			{
				itemData << res[field.name];
			}
		}
		
		if ( !itemData.isEmpty() )
		{
			addItem( itemData );
		}
	}
	// Volvemos a llenar la lista....
	if ( m_isDirty )
	{
		fill();
	}
}

void CModuleWidget::fill()
{
	D_FUNCINFO;
	
	m_isDirty = false;
	
	m_pTree->clear();
	
	QStringList tables, attributes;
	QString where;
	
	foreach(StringPair info, m_pModuleInfo.listInfo)
	{
		if ( info.second.contains("->"))
		{
			QPair<DBField,DBField> field = CAttributeParser::parseFKField( info.second );
			
			if ( ! tables.contains(field.first.table) )
			{
				tables << field.first.table;
			}
			if ( ! tables.contains( field.second.table ) )
			{
				tables << field.second.table;
			}
			attributes << TABLE_DOT_ATT(field.first);
			
			m_pPrimaryKey = field.first;
			
			where = TABLE_DOT_ATT(field.second)+"="+TABLE_DOT_ATT(field.first);
		}
		else
		{
			DBField field = CAttributeParser::parseField( info.second );
			
			if ( ! tables.contains( field.table ) )
			{
				tables << field.table;
			}
			
			attributes << TABLE_DOT_ATT(field);
		}
	}
	
	// Llenamos la lista!
	
	CSelectPackage select(tables, attributes);
	if ( !where.isEmpty() )
	{
		select.setWhere( where);
	}
	
	emit requestOperation( this, &select);
}


void CModuleWidget::removeCurrentItem()
{
	D_FUNCINFO;
	CDeletePackage deleteSqlPkg(m_pPrimaryKey.table);
	
	QString current = currentKey();
	
	deleteSqlPkg.setWhere(m_pPrimaryKey.name+"="+current);
	
	m_isDirty = true;
	
	emit requestOperation( this, &deleteSqlPkg);
}

QString CModuleWidget::currentKey() const
{
	if ( ! m_pTree->currentItem() ) return QString();
	
	QString current = m_pTree->currentItem()->text( column(m_pPrimaryKey) );
	return current;
}



int CModuleWidget::column(const QString &header) const
{
	QTreeWidgetItem *item = m_pTree->headerItem();
	
	for(int i = 0; i < item->columnCount(); i++)
	{
		if ( item->text(i) == header )
		{
			return i;
		}
	}
	
	return -1;
}

int CModuleWidget::column(const DBField &field) const
{
	QTreeWidgetItem *item = m_pTree->headerItem();
	
	for(int i = 0; i < item->columnCount(); i++)
	{
		QString dataField = item->data(i, Field).toString();
		
		if ( dataField.toLower().contains(field.name) ) // FIXME: Esto tiene grandes probabilidades de fallar
		{
			return i;
		}
	}
	
	return -1;
}

QString CModuleWidget::id() const
{
	return m_pModuleInfo.key;
}

