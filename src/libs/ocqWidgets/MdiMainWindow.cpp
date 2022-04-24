#include "MdiMainWindow.h"

#include <QApplication>

#include <ActionManager>

#include "MdiGridSubWin.h"
#include "QQMdiArea.h"

MdiMainWindow::MdiMainWindow(QWidget *parent, Qt::WindowFlags flags)
    : QQMainWindow(parent, flags)
    , mpMdiArea(new QQMdiArea(this))
{
    setParent(parent);
    Q_UNUSED(flags);
    setObjectName("MdiMainWindow");
    setCentralWidget(mpMdiArea);
    mpMdiArea->setViewMode(QMdiArea::TabbedView);
}

QObject * MdiMainWindow::object()
{
    return qobject_cast<QObject *>(this);
}

QQMdiArea * MdiMainWindow::mdiArea() const
{
    Q_CHECK_PTR(mpMdiArea);
    return mpMdiArea;
}

void MdiMainWindow::add(const QQFileInfo &fileInfo)
{
    Q_CHECK_PTR(this);
    qDebug() << Q_FUNC_INFO << objectName() << fileInfo;
}

void MdiMainWindow::add(MdiGridSubWin *pSubWinWidget)
{
    Q_CHECK_PTR(this);
    Q_CHECK_PTR(pSubWinWidget);
    qDebug() << Q_FUNC_INFO << objectName() << pSubWinWidget->objectName();
    mSubWinWidgetKeyMap.insert(pSubWinWidget->key(), pSubWinWidget);
}

void MdiMainWindow::setupActions()
{
    Q_CHECK_PTR(this);
    qDebug() << Q_FUNC_INFO << objectName();
    actions()->add("Window/SubWindow", "Sub &Window");
    actions()->add("Window/Tabbed", "&Tabbed");
}

void MdiMainWindow::setupConnections()
{
    Q_CHECK_PTR(this);
    qDebug() << Q_FUNC_INFO << objectName();
    actions()->connectSlot("Window/SubWindow", this, "windowSubView()", true);
    actions()->connectSlot("Window/Tabbed", this, "windowTabbed()", true);
}


void MdiMainWindow::windowTabbed()
{
    Q_CHECK_PTR(this);
    Q_ASSERT(mdiArea());
    qDebug() << Q_FUNC_INFO << objectName();
    mdiArea()->setViewMode(QMdiArea::TabbedView);
}

void MdiMainWindow::windowSubView()
{
    Q_CHECK_PTR(this);
    Q_ASSERT(mdiArea());
    qDebug() << Q_FUNC_INFO << objectName();
    mdiArea()->setViewMode(QMdiArea::SubWindowView);
}
