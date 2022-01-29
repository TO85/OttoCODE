#include "MdiGridWindow.h"

#include <QtDebug>

MdiGridWindow::MdiGridWindow(const Key &key, QQMdiArea *parent, Qt::WindowFlags flags)
    : QQMdiSubWindow(parent, flags)
    , mpGridLayout(new QGridLayout())
    , mKey(key)
{
    setObjectName("MdiGridWindow:"+key.last());
    qDebug() << Q_FUNC_INFO << key.toString() << parent->objectName();
    layout()->setObjectName("MdiGridWindow:QGridLayout");
    setWindowTitle(key.last());
}

void MdiGridWindow::setup()
{
    qDebug(Q_FUNC_INFO);
    QQMdiSubWindow::setup();
}

