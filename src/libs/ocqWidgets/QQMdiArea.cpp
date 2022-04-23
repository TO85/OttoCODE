#include "QQMdiArea.h"

#include <QtDebug>

#include <MdiSubWinWidget>
#include <QQMainWindow>

QQMdiArea::QQMdiArea(QMainWindow *pMain)
{
    Q_CHECK_PTR(this);
    Q_ASSERT(pMain);
    setObjectName("QQMdiArea");
    qDebug() << Q_FUNC_INFO << pMain->objectName();

}

void QQMdiArea::addSubWinWidget(const MdiSubWinWidget *pSubWinWidget)
{
    Q_CHECK_PTR(this);
    Q_ASSERT(pSubWinWidget);
    qDebug() << Q_FUNC_INFO << pSubWinWidget->objectName();
    QMdiArea::addSubWindow((QWidget *)(pSubWinWidget));
}
