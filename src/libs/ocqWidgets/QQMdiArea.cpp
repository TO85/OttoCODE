#include "QQMdiArea.h"

#include <QtDebug>

#include <QQMainWindow>

QQMdiArea::QQMdiArea(QQMainWindow *pMain)
{
    Q_CHECK_PTR(this);
    Q_CHECK_PTR(pMain);
    setObjectName("QQMdiArea");
    qDebug() << Q_FUNC_INFO << objectName() << pMain->objectName();

}

QQMainWindow * QQMdiArea::mainWindow()
{
    Q_CHECK_PTR(this);
    Q_CHECK_PTR(mpMainWindow);
    qDebug() << Q_FUNC_INFO << objectName() << mpMainWindow->objectName();
    return mpMainWindow;
}


bool QQMdiArea::contains(const Key &key)
{
    return mKeySubWindowMap.contains(key);
}

void QQMdiArea::registerSubWin(QMdiSubWindow * pSubWin)
{
    Q_CHECK_PTR(this);
    Q_ASSERT(pSubWin);
    qDebug() << Q_FUNC_INFO << objectName() << pSubWin->objectName();
    addSubWindow(pSubWin);
}
