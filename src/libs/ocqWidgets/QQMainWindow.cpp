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

const QApplication * QQMainWindow::gui() const
{
    Q_ASSERT(this);
    Q_ASSERT(mpApplication);
    qDebug() << Q_FUNC_INFO << objectName() << mpApplication->objectName();
    return mpApplication;
}

const QCoreApplication *QQMainWindow::core() const
{
    Q_ASSERT(this);
    Q_ASSERT(mpApplication);
    qDebug() << Q_FUNC_INFO << objectName() << mpApplication->objectName();
    return (QCoreApplication *)(mpApplication);
}

ActionManager *QQMainWindow::actions() const
{
    Q_ASSERT(this);
    Q_ASSERT(mpActionManager);
    qDebug() << Q_FUNC_INFO << objectName() << mpActionManager->objectName();
    return mpActionManager;
}

MenuManager *QQMainWindow::menus() const
{
    Q_ASSERT(this);
    Q_ASSERT(mpMenuManager);
//    qDebug() << Q_FUNC_INFO << objectName() << mpMenuManager->objectName();;
    return mpMenuManager;
}

void QQMainWindow::setup()
{
    Q_ASSERT(this);
    qDebug() << Q_FUNC_INFO << objectName();
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
