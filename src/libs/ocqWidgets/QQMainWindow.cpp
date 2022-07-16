#include "QQMainWindow.h"

#include <QApplication>
#include <QMenu>
#include <QMenuBar>
#include <QTimer>

#include <QQString>

QQMainWindow::QQMainWindow(QWidget *parent, Qt::WindowFlags flags)
    : QMainWindow(parent, flags)
{
    Q_CHECK_PTR(this);
    setObjectName("QQMainWindow");
}

const QApplication * QQMainWindow::gui() const
{
    Q_CHECK_PTR(qApp);
    return (QApplication *)(qApp);
}

const QObject *QQMainWindow::object()
{
    Q_CHECK_PTR(this);
    const QObject * result=nullptr;
    result = qobject_cast<QObject *>(this);
    Q_ASSERT(result);
    return result;
}

QMenu *QQMainWindow::menu(const Key key)
{
    Q_ASSERT(mKeyMenuMap.contains(key));
    return mKeyMenuMap.value(key);
}

QMenu * QQMainWindow::addMenu(const Key key, const QQString &text)
{
    qDebug() << Q_FUNC_INFO << objectName();
    if (mKeyMenuMap.contains(key)) return menu(key);                    /* /====\ */
    const QString tMenuText = text.isEmpty() ? ("&"+key.last()) : text;
    QMenu * result = new QMenu(tMenuText, this);
    menuBar()->addMenu(result);
    mKeyMenuMap.insert(key, result);
    return result;
}

void QQMainWindow::setup()
{
    Q_CHECK_PTR(this);
    qDebug() << Q_FUNC_INFO << objectName();
    emit setupComplete();
}

void QQMainWindow::exit()
{
    QTimer::singleShot(10, qApp, &QCoreApplication::quit);
}

