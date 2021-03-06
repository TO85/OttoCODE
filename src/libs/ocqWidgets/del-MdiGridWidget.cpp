#include "MdiGridWidget.h"

#include <QtDebug>

MdiGridWidget::MdiGridWidget(const Key &key, QQMdiArea *parent, Qt::WindowFlags flags)
    : MdiSubWinGrid(key, parent, flags)
    , mpGridLayout(new QGridLayout())
    , mKey(key)
{
    setObjectName("MdiGridWindow:"+key.last().toQString());
    qDebug() << Q_FUNC_INFO << key.toQString() << parent->objectName();
    layout()->setObjectName("MdiGridWindow:QGridLayout");
}

QGridLayout *MdiGridWidget::layout() const
{
    Q_CHECK_PTR(this);
    Q_ASSERT(mpGridLayout);
//    qDebug() << Q_FUNC_INFO << objectName() << mpGridLayout->objectName();;
    return mpGridLayout;
}

void MdiGridWidget::setup()
{
    Q_CHECK_PTR(this);
    qDebug() << Q_FUNC_INFO << objectName();
    setWindowTitle(key().last().toQString());
    MdiSubWinGrid::setup();

}

