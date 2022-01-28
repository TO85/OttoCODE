#include "MainWindow.h"

#include <QtDebug>

MainWindow::MainWindow(QApplication *pApp)
    : MdiMainWindow(pApp)
{
    setObjectName("Excelsior:MainWindow");
    qDebug() << Q_FUNC_INFO;
}
