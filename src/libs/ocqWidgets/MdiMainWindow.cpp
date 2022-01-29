#include "MdiMainWindow.h"

#include <MdiGridWindow>

MdiMainWindow::MdiMainWindow(QApplication *pApp)
    : QQMainWindow(pApp)
    , mpMdiArea(new QQMdiArea(this))
{
    setObjectName("MdiMainWindow");
    setCentralWidget(mpMdiArea);
}

QQMdiArea *MdiMainWindow::mdiArea() const
{
    Q_ASSERT(mpMdiArea);
    return mpMdiArea;
}


void MdiMainWindow::addSubWindow(MdiGridWindow *pSubWindow)
{
    mSubWindowKeyMap.insert(pSubWindow->key(), pSubWindow);
}


void MdiMainWindow::windowTabbed()
{
    mpMdiArea->setViewMode(QMdiArea::TabbedView);
}

void MdiMainWindow::windowSubView()
{
    mpMdiArea->setViewMode(QMdiArea::SubWindowView);
}
