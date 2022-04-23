#include "QQMainWindow.h"

#include <QApplication>
#include <QMenu>
#include <QMenuBar>
#include <QTimer>

#include <ActionManager>
#include <QQString>

QQMainWindow::QQMainWindow(QApplication *pApp)
    : mpApplication(pApp)
    , mpActionManager(new ActionManager(this))
{
    setObjectName("QQMainWindow");
}

const QApplication * QQMainWindow::gui() const
{
    Q_CHECK_PTR(this);
    Q_ASSERT(mpApplication);
    qDebug() << Q_FUNC_INFO << objectName() << mpApplication->objectName();
    return mpApplication;
}

const QCoreApplication *QQMainWindow::core() const
{
    Q_CHECK_PTR(this);
    Q_ASSERT(mpApplication);
    qDebug() << Q_FUNC_INFO << objectName() << mpApplication->objectName();
    return (QCoreApplication *)(mpApplication);
}

const QObject *QQMainWindow::object()
{
    Q_CHECK_PTR(this);
    const QObject * result=nullptr;
    result = qobject_cast<QObject *>(this);
    Q_ASSERT(result);
    return result;
}

ActionManager *QQMainWindow::actions() const
{
    Q_CHECK_PTR(this);
    Q_ASSERT(mpActionManager);
    qDebug() << Q_FUNC_INFO << objectName() << mpActionManager->objectName();
    return mpActionManager;
}

QAction *QQMainWindow::action(const Key key)
{
    Q_CHECK_PTR(this);
    Q_ASSERT(actions()->contains(key));
    return actions()->action(key);
}

QMenu *QQMainWindow::menu(const Key key)
{
    Q_CHECK_PTR(this);
    Q_ASSERT(mKeyMenuMap.contains(key));
    return mKeyMenuMap.value(key);
}

QMenu * QQMainWindow::addMenu(const Key key, const QQString &text)
{
    Q_CHECK_PTR(this);
    Q_ASSERT(mpActionManager);
    qDebug() << Q_FUNC_INFO << objectName() << mpActionManager->objectName();
    if (mKeyMenuMap.contains(key)) return menu(key);                    /* /====\ */
    const QString tMenuText = text.isEmpty() ? ("&"+key.last()) : text;
    QMenu * result = new QMenu(tMenuText, this);
    QAction * pMenuAction = mpActionManager->add(key, tMenuText);
    pMenuAction->setMenu(result);
    menuBar()->addMenu(result);
    mKeyMenuMap.insert(key, result);
    return result;
}

void QQMainWindow::setup()
{
    Q_CHECK_PTR(this);
    qDebug() << Q_FUNC_INFO << objectName();
    setupStart();
    setupActions();
    setupConnections();
    setupMenus();
    setupToolbars();
    setupWidgets();
    setupFinish();
    emit setupComplete();
}

void QQMainWindow::exit()
{
    QTimer::singleShot(10, qApp, &QCoreApplication::quit);
}

void QQMainWindow::setupStart()
{
    qDebug() << Q_FUNC_INFO << objectName();

}

void QQMainWindow::setupActions()
{
    qDebug() << Q_FUNC_INFO << objectName();

}

void QQMainWindow::setupConnections()
{
    qDebug() << Q_FUNC_INFO << objectName();

}

void QQMainWindow::setupMenus()
{
    qDebug() << Q_FUNC_INFO << objectName();
}

void QQMainWindow::setupToolbars()
{
    qDebug() << Q_FUNC_INFO << objectName();

}


void QQMainWindow::setupWidgets()
{
    qDebug() << Q_FUNC_INFO << objectName();

}

void QQMainWindow::setupFinish()
{
    qDebug() << Q_FUNC_INFO << objectName();
    menuBar()->show();

}
