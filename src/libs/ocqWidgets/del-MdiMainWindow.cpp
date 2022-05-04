#include "MdiMainWindow.h"

#include <QApplication>

#include <ActionManager>

#include "hold-MdiGridSubWin.h"
#include "QQMdiArea.h"

hold-MdiMainWindow::hold-MdiMainWindow(QWidget *parent, Qt::WindowFlags flags)
    : QQMainWindow(parent, flags)
    , mpMdiArea(new QQMdiArea(this))
{
    setParent(parent);
    Q_UNUSED(flags);
    setObjectName("MdiMainWindow");
    setCentralWidget(mpMdiArea);
    mpMdiArea->setViewMode(QMdiArea::TabbedView);
}

QObject * hold-MdiMainWindow::object()
{
    return qobject_cast<QObject *>(this);
}

QQMdiArea * hold-MdiMainWindow::mdiArea() const
{
    Q_CHECK_PTR(mpMdiArea);
    return mpMdiArea;
}

void hold-MdiMainWindow::add(const QQFileInfo &fileInfo)
{
    Q_CHECK_PTR(this);
    qDebug() << Q_FUNC_INFO << objectName() << fileInfo;
}

void hold-MdiMainWindow::add(hold-MdiGridSubWin *pSubWinWidget)
{
    Q_CHECK_PTR(this);
    Q_CHECK_PTR(pSubWinWidget);
    qDebug() << Q_FUNC_INFO << objectName() << pSubWinWidget->objectName();
    mSubWinWidgetKeyMap.insert(pSubWinWidget->key(), pSubWinWidget);
}

void hold-MdiMainWindow::setupActions()
{
    Q_CHECK_PTR(this);
    qDebug() << Q_FUNC_INFO << objectName();
    actions()->add("Window/SubWindow", "Sub &Window");
    actions()->add("Window/Tabbed", "&Tabbed");
}

void hold-MdiMainWindow::setupConnections()
{
    Q_CHECK_PTR(this);
    qDebug() << Q_FUNC_INFO << objectName();
    actions()->connectSlot("Window/SubWindow", this, "windowSubView()", true);
    actions()->connectSlot("Window/Tabbed", this, "windowTabbed()", true);
}


void hold-MdiMainWindow::windowTabbed()
{
    Q_CHECK_PTR(this);
    Q_ASSERT(mdiArea());
    qDebug() << Q_FUNC_INFO << objectName();
    mdiArea()->setViewMode(QMdiArea::TabbedView);
}

void hold-MdiMainWindow::windowSubView()
{
    Q_CHECK_PTR(this);
    Q_ASSERT(mdiArea());
    qDebug() << Q_FUNC_INFO << objectName();
    mdiArea()->setViewMode(QMdiArea::SubWindowView);
}
