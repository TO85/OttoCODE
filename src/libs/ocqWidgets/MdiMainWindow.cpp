#include "MdiMainWindow.h"

#include <MdiGridWindow>

MdiMainWindow::MdiMainWindow(QApplication *pApp)
    : QQMainWindow(pApp)
    , mpMdiArea(new QQMdiArea(this))
{
    setObjectName("MdiMainWindow");
    setCentralWidget(mpMdiArea);
    mpMdiArea->setViewMode(QMdiArea::TabbedView);
}

QQMdiArea *MdiMainWindow::mdiArea() const
{
    Q_ASSERT(mpMdiArea);
    return mpMdiArea;
}


void MdiMainWindow::addSubWindow(MdiGridWindow *pSubWindow)
{
    Q_ASSERT(pSubWindow);
    qDebug() << Q_FUNC_INFO << pSubWindow->objectName();
    mSubWindowKeyMap.insert(pSubWindow->key(), pSubWindow);
}


void MdiMainWindow::windowTabbed()
{
    Q_ASSERT(this);
    qDebug() << Q_FUNC_INFO << objectName();
    mpMdiArea->setViewMode(QMdiArea::TabbedView);
}

void MdiMainWindow::windowSubView()
{
    Q_ASSERT(this);
    qDebug() << Q_FUNC_INFO << objectName();
    mpMdiArea->setViewMode(QMdiArea::SubWindowView);
}
