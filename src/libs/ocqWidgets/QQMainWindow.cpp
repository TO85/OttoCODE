#include "QQMainWindow.h"

#include <QApplication>

#include <ActionManager>
#include <MenuManager>

QQMainWindow::QQMainWindow(QApplication *pApp)
    : mpApplication(pApp)
    , mpActionManager(new ActionManager(pApp))
    , mpMenuManager(new MenuManager(this, mpActionManager, this))
{
    setObjectName("QQMainWindow");
}

void QQMainWindow::setup()
{
    setupStart();
    setupMenus();
    setupActions();
    setupConnections();
    setupWidgets();
    setupFinish();
    emit setupComplete();
}

void QQMainWindow::setupStart()
{

}

void QQMainWindow::setupMenus()
{

}

void QQMainWindow::setupActions()
{

}

void QQMainWindow::setupConnections()
{

}

void QQMainWindow::setupWidgets()
{

}

void QQMainWindow::setupFinish()
{

}
