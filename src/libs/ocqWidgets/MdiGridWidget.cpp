#include "MdiGridWidget.h"

#include <QtDebug>

MdiGridWidget::MdiGridWidget(const Key &key, QQMdiArea *parent, Qt::WindowFlags flags)
    : MdiSubWinWidget(key, parent, flags)
    , mpGridLayout(new QGridLayout())
    , mKey(key)
{
    setObjectName("MdiGridWindow:"+key.last().toQString());
    qDebug() << Q_FUNC_INFO << key.toQString() << parent->objectName();
    layout()->setObjectName("MdiGridWindow:QGridLayout");
}

QGridLayout *MdiGridWidget::layout() const
{
    Q_ASSERT(this);
    Q_ASSERT(mpGridLayout);
//    qDebug() << Q_FUNC_INFO << objectName() << mpGridLayout->objectName();;
    return mpGridLayout;
}

void MdiGridWidget::setup()
{
    Q_ASSERT(this);
    qDebug() << Q_FUNC_INFO << objectName();
    setWindowTitle(key().last().toQString());
    MdiSubWinWidget::setup();

}

