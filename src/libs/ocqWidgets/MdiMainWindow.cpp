#include "MdiMainWindow.h"

#include <MdiGridWidget>

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


void MdiMainWindow::addSubWindow(MdiGridWidget *pSubWinWidget)
{
    Q_ASSERT(pSubWinWidget);
    qDebug() << Q_FUNC_INFO << objectName() << pSubWinWidget->objectName();
    mSubWinWidgetKeyMap.insert(pSubWinWidget->key(), pSubWinWidget);
}


void MdiMainWindow::windowTabbed()
{
    Q_ASSERT(this);
    Q_ASSERT(mdiArea());
    qDebug() << Q_FUNC_INFO << objectName();
    mdiArea()->setViewMode(QMdiArea::TabbedView);
}

void MdiMainWindow::windowSubView()
{
    Q_ASSERT(this);
    Q_ASSERT(mdiArea());
    qDebug() << Q_FUNC_INFO << objectName();
    mdiArea()->setViewMode(QMdiArea::SubWindowView);
}
