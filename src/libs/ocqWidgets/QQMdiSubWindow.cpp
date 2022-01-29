#include "QQMdiSubWindow.h"

#include <QtDebug>

#include <QQMdiArea>

QQMdiSubWindow::QQMdiSubWindow(QQMdiArea *parent, Qt::WindowFlags flags)
    : QMdiSubWindow((QWidget *)(parent), flags)
{
    setObjectName("QQMdiSubWindow");
    qDebug() << Q_FUNC_INFO << parent->objectName();
    setAttribute(Qt::WA_DeleteOnClose);
}

void QQMdiSubWindow::setup()
{
    qDebug(Q_FUNC_INFO);
}
