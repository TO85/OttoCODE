#include "MainWindow.h"

#include <QApplication>
#include <QtWidgets/QAction>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>

#include <eirExe/ActionManager.h>
#include <eirWgt/QQStackedLayout.h>
//#include "../../../../INDI6/src/libs/eirExe/ActionManager.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , mpActions(new ActionManager(this))
    , mpStack(new QQStackedLayout(this))
{
    setObjectName("MainWindow");
    setWindowTitle("TORC AppBoss");
    QMenuBar *pMainMenu = menuBar();
    QMenu *pHelpMenu = pMainMenu->addMenu("&Help");
    actions()->add("Help/AboutQt", pHelpMenu->addAction("About Qt", &QApplication::aboutQt));
    actions()->add("Help/AboutTORC", pHelpMenu->addAction("About TORC"));
    actions()->add("Help/AboutAppBoss", pHelpMenu->addAction("About AppBoss"));
    actions()->action("Help/AboutTORC")->setDisabled(true);
    actions()->action("Help/AboutAppBoss")->setDisabled(true);
}

MainWindow::~MainWindow()
{
    mpActions->deleteLater();
    mpStack->deleteLater();
}


