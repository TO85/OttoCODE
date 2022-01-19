#include "LancealotMainWindow.h"

#include <QtGui/QAction>
#include <QtWidgets/QMdiArea>
#include <QtWidgets/QToolBar>

#include "BaseMdiWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , mpMdiArea(new QMdiArea(this))
{
    setObjectName("MainWindow");
    Q_ASSERT(qobject_cast<QMdiArea *>(mpMdiArea));
    mpMdiArea->setObjectName("MdiArea");
    setWindowTitle("TORC AppBoss");
    QToolBar *pMainToolBar = addToolBar("Main");
    pMainToolBar->addAction("About Qt");
    pMainToolBar->addAction("About TORC");
    pMainToolBar->addAction("About AppBoss");
    setCentralWidget(mpMdiArea);
}

MainWindow::~MainWindow()
{
    mpMdiArea->deleteLater();
}

void MainWindow::addSubWindow(BaseMdiWindow *pSubWindow)
{
    mTitleSubWindowMap.insert(pSubWindow->title(), pSubWindow);
}

