#include "QQMdiSubWindow.h"

QQMdiSubWindow::QQMdiSubWindow(const KeySeg & key, QWidget *parent, Qt::WindowFlags flags)
    : QMdiSubWindow(parent, flags)
{
    setObjectName("QQMdiSubWindow:" + key);
}
