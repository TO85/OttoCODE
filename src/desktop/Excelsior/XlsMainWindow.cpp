#include "XlsMainWindow.h"

#include <QtDebug>

XlsMainWindow::XlsMainWindow(QApplication *pApp)
    : MdiMainWindow(pApp)
{
    setObjectName("Excelsior:MainWindow");
    qDebug() << Q_FUNC_INFO;
}
