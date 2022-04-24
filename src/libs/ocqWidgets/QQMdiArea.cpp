#include "QQMdiArea.h"

#include <QtDebug>

#include <QQMainWindow>

#include "MdiGridSubWin.h"

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

MdiGridSubWin *QQMdiArea::subWin(const Key &key)
{
    MdiGridSubWin * result = nullptr;
    Q_CHECK_PTR(this);
    Q_ASSERT(contains(key));
    result = mKeySubWinMap.value(key);
    Q_CHECK_PTR(result);
    qDebug() << Q_FUNC_INFO << objectName() << result->objectName();
    return result;
}

bool QQMdiArea::contains(const Key &key)
{
    return mKeySubWinMap.contains(key);
}

void QQMdiArea::registerSubWin(MdiGridSubWin * pSubWin)
{
    Q_CHECK_PTR(this);
    Q_ASSERT(pSubWin);
    qDebug() << Q_FUNC_INFO << objectName() << pSubWin->objectName();
    addSubWindow(pSubWin->gridWidget());
}
