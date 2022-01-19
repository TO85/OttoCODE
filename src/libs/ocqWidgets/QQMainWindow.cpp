#include "QQMainWindow.h"

#include <QApplication>

#include <ActionManager>

QQMainWindow::QQMainWindow(QApplication *app)
    : mpApplication(app)
    , mpActionManager(new ActionManager(app))
{
    setObjectName("QQMainWindow");
}
