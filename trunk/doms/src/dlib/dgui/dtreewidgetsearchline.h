/* This file is part of the KDE libraries
   Copyright (c) 2003 Scott Wheeler <wheeler@kde.org>
   Copyright (c) 2005 Rafal Rzepecki <divide@users.sourceforge.net>
   Copyright (c) 2006 Hamish Rodda <rodda@kde.org>

   This library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Library General Public
   License version 2 as published by the Free Software Foundation.

   This library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Library General Public License for more details.

   You should have received a copy of the GNU Library General Public License
   along with this library; see the file COPYING.LIB.  If not, write to
   the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.
*/

#ifndef DTREEWIDGETSEARCHLINE_H
#define DTREEWIDGETSEARCHLINE_H

#include <QModelIndex>

#include <dgui/dclicklineedit.h>

class QTreeWidget;
class QTreeWidgetItem;
class QToolButton;

/**
 * This class makes it easy to add a search line for filtering the items in
 * listviews based on a simple text search.
 *
 * No changes to the application other than instantiating this class with
 * appropriate QTreeWidgets should be needed.
 */

class Q_GUI_EXPORT DTreeWidgetSearchLine : public DClickLineEdit
{
    Q_OBJECT

    Q_PROPERTY(Qt::CaseSensitivity caseSensitity READ caseSensitivity WRITE setCaseSensitivity)
    Q_PROPERTY(bool keepParentsVisible READ keepParentsVisible WRITE setKeepParentsVisible)

public:

    /**
     * Constructs a DTreeWidgetSearchLine with \a treeWidget being the QTreeWidget to
     * be filtered.
     *
     * If \a treeWidget is null then the widget will be disabled until listviews
     * are set with setTreeWidget(), setTreeWidgets() or added with addTreeWidget().
     */
    DTreeWidgetSearchLine(QWidget *parent = 0, QTreeWidget *treeWidget = 0);

    /**
     * Constructs a DTreeWidgetSearchLine with \a treeWidgets being the list of
     * pointers to QTreeWidgets to be filtered.
     *
     * If \a treeWidgets is empty then the widget will be disabled until listviews
     * are set with setTreeWidget(), setTreeWidgets() or added with addTreeWidget().
     */
    DTreeWidgetSearchLine(QWidget *parent,
                        const QList<QTreeWidget *> &treeWidgets);


    /**
     * Destroys the DTreeWidgetSearchLine.
     */
    virtual ~DTreeWidgetSearchLine();

    /**
     * Returns true if the search is case sensitive.  This defaults to false.
     *
     * @see setCaseSensitive()
     */
    Qt::CaseSensitivity caseSensitivity() const;

    /**
     * Returns the current list of columns that will be searched.  If the
     * returned list is empty all visible columns will be searched.
     *
     * @see setSearchColumns
     */
    QList<int> searchColumns() const;

    /**
     * If this is true (the default) then the parents of matched items will also
     * be shown.
     *
     * @see setKeepParentsVisible()
     */
    bool keepParentsVisible() const;

    /**
     * Returns the listview that is currently filtered by the search.
     * If there are multiple listviews filtered, it returns 0.
     *
     * @see setTreeWidget(), treeWidgets()
     */
    QTreeWidget *treeWidget() const;

    /**
     * Returns the list of pointers to listviews that are currently filtered by
     * the search.
     *
     * @see setTreeWidgets(), addTreeWidget(), treeWidget()
     */
    const QList<QTreeWidget *> &treeWidgets() const;

public slots:
    /**
     * Adds a QTreeWidget to the list of listviews filtered by this search line.
     * If \a tw is null then the widget will be disabled.
     *
     * @see treeWidget(), setTreeWidgets(), removeTreeWidget()
     */
    void addTreeWidget(QTreeWidget *tw);

    /**
     * Removes a QTreeWidget from the list of listviews filtered by this search
     * line. Does nothing if \a tw is 0 or is not filtered by the quick search
     * line.
     *
     * @see listVew(), setTreeWidgets(), addTreeWidget()
     */
    void removeTreeWidget(QTreeWidget *tw);

    /**
     * Updates search to only make visible the items that match \a s.  If
     * \a s is null then the line edit's text will be used.
     */
    virtual void updateSearch(const QString &s = QString());

    /**
     * Make the search case sensitive or case insensitive.
     *
     * @see caseSenstivity()
     */
    void setCaseSensitivity(Qt::CaseSensitivity cs);

    /**
     * When a search is active on a list that's organized into a tree view if
     * a parent or ancesestor of an item is does not match the search then it
     * will be hidden and as such so too will any children that match.
     *
     * If this is set to true (the default) then the parents of matching items
     * will be shown.
     *
     * @see keepParentsVisible
     */
    void setKeepParentsVisible(bool v);

    /**
     * Sets the list of columns to be searched.  The default is to search all,
     * visible columns which can be restored by passing \a columns as an empty
     * list.
     * If listviews to be filtered have different numbers or labels of columns
     * this method has no effect.
     *
     * @see searchColumns
     */
    void setSearchColumns(const QList<int> &columns);

    /**
     * Sets the QTreeWidget that is filtered by this search line, replacing any
     * previously filtered listviews.  If \a tw is null then the widget will be
     * disabled.
     *
     * @see treeWidget(), setTreeWidgets()
     */
    void setTreeWidget(QTreeWidget *tw);

    /**
     * Sets QTreeWidgets that are filtered by this search line, replacing any
     * previously filtered listviews.  If \a tws is empty then the widget will
     * be disabled.
     *
     * @see treeWidgets(), addTreeWidget(), setTreeWidget()
     */
    void setTreeWidgets(const QList<QTreeWidget *> &tw);


  protected:

    /**
     * Returns true if \a item matches the search \a s.  This will be evaluated
     * based on the value of caseSensitive().  This can be overridden in
     * subclasses to implement more complicated matching schemes.
     */
    virtual bool itemMatches(const QTreeWidgetItem *item, const QString &s) const;

    /**
    * Re-implemented for internal reasons.  API not affected.
    */
    virtual void contextMenuEvent( QContextMenuEvent*e );

    /**
     * Updates search to only make visible appropriate items in \a treeWidget.  If
     * \a treeWidget is null then nothing is done.
     */
    virtual void updateSearch(QTreeWidget *treeWidget);

    /**
     * Connects signals of this listview to the appropriate slots of the search
     * line.
     */
    virtual void connectTreeWidget(QTreeWidget *);
    /**
     * Disconnects signals of a listviews from the search line.
     */
    virtual void disconnectTreeWidget(QTreeWidget *);

    /**
     * Checks columns in all listviews and decides whether choosing columns to
     * filter on makes any sense.
     *
     * Returns false if either of the following is true:
     * * there are no listviews connected,
     * * the listviews have different numbers of columns,
     * * the listviews have only one column,
     * * the listviews differ in column labels.
     *
     * Otherwise it returns true.
     *
     * @see setSearchColumns()
     */
    virtual bool canChooseColumnsCheck();

protected slots:
    /**
     * When keys are pressed a new search string is created and a timer is
     * activated.  The most recent search is activated when this timer runs out
     * if another key has not yet been pressed.
     *
     * This method makes @param search the most recent search and starts the
     * timer.
     *
     * Together with activateSearch() this makes it such that searches are not
     * started until there is a short break in the users typing.
     *
     * @see activateSearch()
     */
    void queueSearch(const QString &search);

    /**
     * When the timer started with queueSearch() expires this slot is called.
     * If there has been another timer started then this slot does nothing.
     * However if there are no other pending searches this starts the list view
     * search.
     *
     * @see queueSearch()
     */
    void activateSearch();

private:

    /**
     * This is used after changing the list of listviews. If choosing columns
     * doesn't make sense, it forces filtering over all columns.
     *
     * @see canChooseColumnsCheck()
     */
    void checkColumns();

    /**
     * This is used in case parent items of matching items shouldn't be
     * visible.  It hides all items that don't match the search string.
     */
    void checkItemParentsNotVisible(QTreeWidget *treeWidget);

    /**
     * This is used in case parent items of matching items should be visible.
     * It makes a recursive call to all children.  It returns true if at least
     * one item in the subtree with the given root item is visible.
     */
    bool checkItemParentsVisible(QTreeWidgetItem* item);

private slots:
    void rowsInserted(const QModelIndex & parent, int start, int end) const;
    void treeWidgetDeleted( QObject *treeWidget );
    void slotColumnActivated(QAction* action);
    void slotAllVisibleColumns();

private:
    class DTreeWidgetSearchLinePrivate;
    DTreeWidgetSearchLinePrivate *d;
};

/**
 * Creates a widget featuring a DTreeWidgetSearchLine, a label with the text
 * "Search" and a button to clear the search.
 */
class Q_GUI_EXPORT DTreeWidgetSearchLineWidget : public QWidget
{
    Q_OBJECT

public:
    /**
     * Creates a DTreeWidgetSearchLineWidget for \a treeWidget with \a parent as the
     * parent.
     */
    DTreeWidgetSearchLineWidget(QWidget *parent = 0, QTreeWidget *treeWidget = 0);

    /**
     * Destroys the DTreeWidgetSearchLineWidget
     */
    ~DTreeWidgetSearchLineWidget();

    /**
     * Returns a pointer to the search line.
     */
    DTreeWidgetSearchLine *searchLine() const;
    
    /**
     * Sets the erase icon
     */
    void setEraseIcon(const QIcon &icon);

protected slots:
    /**
     * Creates the widgets inside of the widget.  This is called from the
     * constructor via a single shot timer so that it it guaranteed to run
     * after construction is complete.  This makes it suitable for overriding in
     * subclasses.
     */
    virtual void createWidgets();

protected:
    /**
     * Creates the search line.  This can be useful to reimplement in cases where
     * a DTreeWidgetSearchLine subclass is used.
     *
     * It is const because it is be called from searchLine(), which to the user
     * doesn't conceptually alter the widget.
     */
    virtual DTreeWidgetSearchLine *createSearchLine(QTreeWidget *treeWidget) const;

private:
    class DTreeWidgetSearchLineWidgetPrivate;
    DTreeWidgetSearchLineWidgetPrivate *d;
};

#endif


