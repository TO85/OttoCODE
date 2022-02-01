#include "MdiGridWindow.h"

#include <QtDebug>

MdiGridWindow::MdiGridWindow(const Key &key, QQMdiArea *parent, Qt::WindowFlags flags)
    : QQMdiSubWindow(parent, flags)
    , mpGridLayout(new QGridLayout())
    , mKey(key)
{
    setObjectName("MdiGridWindow:"+key.last().toQString());
    qDebug() << Q_FUNC_INFO << key.toQString() << parent->objectName();
    layout()->setObjectName("MdiGridWindow:QGridLayout");
    setWindowTitle(key.last().toQString());
}

void MdiGridWindow::setup()
{
    qDebug(Q_FUNC_INFO);
    QQMdiSubWindow::setup();
}

