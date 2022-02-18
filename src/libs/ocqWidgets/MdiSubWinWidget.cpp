#include "MdiSubWinWidget.h"

#include <QtDebug>

#include <QQMdiArea>

MdiSubWinWidget::MdiSubWinWidget(const Key &aKey, QQMdiArea *parent, Qt::WindowFlags flags)
    : QWidget((QWidget *)(parent), flags)
    , mpMdiArea(parent)
    , mKey(aKey)
{
    Q_ASSERT(this);
    Q_ASSERT(mpMdiArea);
    setObjectName("QQMdiSubWindow:" + key());
    qDebug() << Q_FUNC_INFO << objectName() << mpMdiArea->objectName();
    setAttribute(Qt::WA_DeleteOnClose);
}

QQMdiArea *MdiSubWinWidget::mdiArea()
{
    Q_ASSERT(this);
    Q_ASSERT(mpMdiArea);
    qDebug() << Q_FUNC_INFO << objectName() << mpMdiArea->objectName();
    return mpMdiArea;
}

void MdiSubWinWidget::setup()
{
    Q_ASSERT(this);
    qDebug() << Q_FUNC_INFO << objectName();
}
