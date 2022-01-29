#include "QQMdiArea.h"

#include <QtDebug>

#include <QQMainWindow>

QQMdiArea::QQMdiArea(QMainWindow *pMain)
    : QMdiArea(pMain->centralWidget())
{
    qDebug() << Q_FUNC_INFO;

}
