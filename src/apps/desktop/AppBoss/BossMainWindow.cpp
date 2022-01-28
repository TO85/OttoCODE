#include "BossMainWindow.h"

#include <QtGui/QAction>
#include <QtWidgets/QMdiArea>
#include <QtWidgets/QToolBar>

BossMainWindow::BossMainWindow(QApplication *pApp)
    : MdiMainWindow(pApp)
{
    setObjectName("MainWindow");
    setWindowTitle("TORC AppBoss");
    QToolBar *pMainToolBar = addToolBar("Main");
    pMainToolBar->addAction("About Qt");
    pMainToolBar->addAction("About TORC");
    pMainToolBar->addAction("About AppBoss");
}

BossMainWindow::~BossMainWindow()
{
}

void BossMainWindow::setup()
{

}

void BossMainWindow::setupMenus()
{

}

void BossMainWindow::setupFinish()
{

}
