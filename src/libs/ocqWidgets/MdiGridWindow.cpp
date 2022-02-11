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

QGridLayout *MdiGridWindow::layout() const
{
    Q_ASSERT(this);
    Q_ASSERT(mpGridLayout);
//    qDebug() << Q_FUNC_INFO << objectName() << mpGridLayout->objectName();;
    return mpGridLayout;
}

void MdiGridWindow::setup()
{
    Q_ASSERT(this);
    qDebug() << Q_FUNC_INFO << objectName();
    QQMdiSubWindow::setup();
}

