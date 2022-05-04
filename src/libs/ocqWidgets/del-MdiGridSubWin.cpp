#include "MdiGridSubWin.h"

#include <QtDebug>

#include <QQGridLayout>
#include <QQMdiArea>

hold-MdiGridSubWin::hold-MdiGridSubWin(const Key &aKey, QQMdiArea * parent, Qt::WindowFlags flags)
    : QMdiSubWindow((QWidget *)(parent), flags)
    , mpMdiArea(parent)
    , mKey(aKey)
    , mpGridLayout(new QQGridLayout(this))
    , mpGridWidget(new QWidget(this))
{
    Q_CHECK_PTR(this);
    Q_CHECK_PTR(mpMdiArea);
    Q_CHECK_PTR(mpGridLayout);
    Q_CHECK_PTR(mpGridWidget);
    mpGridLayout->setObjectName("GridLayout:" + key());
    mpGridWidget->setObjectName("GridWidget:" + key());
    setObjectName("MdiSubWinGrid:" + key());
    qDebug() << Q_FUNC_INFO << objectName() << mpMdiArea->objectName() << objectName()
             << mpGridLayout->objectName() << mpGridWidget->objectName();
    setAttribute(Qt::WA_DeleteOnClose);
}

QQMdiArea *hold-MdiGridSubWin::mdiArea()
{
    Q_CHECK_PTR(this);
    Q_CHECK_PTR(mpMdiArea);
    qDebug() << Q_FUNC_INFO << objectName() << mpMdiArea->objectName();
    return mpMdiArea;
}

QQGridLayout *hold-MdiGridSubWin::grid()

{
    Q_CHECK_PTR(this);
    Q_CHECK_PTR(mpGridLayout);
//    qDebug() << Q_FUNC_INFO << objectName() << mpGridLayout->objectName();
    return mpGridLayout;
}

QWidget *hold-MdiGridSubWin::gridWidget()
{
    Q_CHECK_PTR(this);
    Q_CHECK_PTR(mpGridWidget);
    qDebug() << Q_FUNC_INFO << objectName() << mpGridWidget->objectName();
    return mpGridWidget;
}
void hold-MdiGridSubWin::setup()
{
    Q_CHECK_PTR(this);
    qDebug() << Q_FUNC_INFO << objectName() << gridWidget()->objectName() << grid()->objectName();
    gridWidget()->setLayout(grid());
    setWidget(gridWidget());
    setWindowTitle(title());
    update();
    show();
}
