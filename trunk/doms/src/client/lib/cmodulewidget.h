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

#ifndef CMODULEWIDGET_H
#define CMODULEWIDGET_H

#include <qwidget.h>

#include <QTreeWidget>
#include <dtreelistwidget.h>

#include "cmodulebuttonbar.h"
#include "global.h"

#include "cdatabaserequesteriface.h"

class DTreeWidgetSearchLine;
class QBoxLayout;
class CSqlPackageBase;

/**
 * Clase base para la interfaz de todos los modulos
 * @author David Cuadrado \<krawek@gmail.com\>
*/
class CModuleWidget : public QWidget, public CDatabaseRequesterIface
{
	Q_OBJECT;
	public:
		enum UserRoles
		{
			Field = 38
		};
		
		CModuleWidget(const QString &moduleMame, QWidget *parent = 0);
		~CModuleWidget();
		
		CModuleButtonBar *addButtonBar(int flags);
		
		void setup(const ModuleInfo &module);
		
		QBoxLayout *boxLayout();
		
		void addItem(const QStringList &cols);
		
		virtual void setOperationResult(const QList<XMLResults> &results);
		
		int column(const QString &header) const;
		int column(const DBField &field) const;
		
		
		QString currentKey() const;
		
		QString id() const;
		
	public slots:
		virtual void fill();
		virtual void removeCurrentItem();
		
	signals:
		void requestForm(const QString &module, int formId, const QString &key = QString() );
		void message(Msg::Type, const QString &message);
		void requestOperation(CModuleWidget *self, const CSqlPackageBase *sql );
		
	protected:
		DTreeListWidget *m_pTree;
		DTreeWidgetSearchLine *m_pSearch;
		ModuleInfo m_pModuleInfo;
		DBField m_pPrimaryKey;
		
	private:
		bool m_isDirty;
};

#endif
