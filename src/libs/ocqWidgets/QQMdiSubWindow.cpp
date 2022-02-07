#include "QQMdiSubWindow.h"

#include <QtDebug>

#include <QQMdiArea>

QQMdiSubWindow::QQMdiSubWindow(QQMdiArea *parent, Qt::WindowFlags flags)
    : QMdiSubWindow((QWidget *)(parent), flags)
    , mpMdiArea(parent)
{
    setObjectName("QQMdiSubWindow");
    qDebug() << Q_FUNC_INFO << parent->objectName() << mpMdiArea->objectName();
    setAttribute(Qt::WA_DeleteOnClose);
}

QQMdiArea *QQMdiSubWindow::mdiArea()
{
    Q_ASSERT(this);
    Q_ASSERT(mpMdiArea);
    qDebug() << Q_FUNC_INFO << objectName() << mpMdiArea->objectName();
    return mpMdiArea;
}

void QQMdiSubWindow::setup()
{
    Q_ASSERT(this);
    qDebug() << Q_FUNC_INFO << objectName();
    mdiArea()->addSubWindow(this);
}
