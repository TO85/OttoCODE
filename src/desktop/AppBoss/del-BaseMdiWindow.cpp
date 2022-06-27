#include "BaseMdiWindow.h"

BaseMdiWindow::BaseMdiWindow(const QString &title, QMdiArea *parent, Qt::WindowFlags flags)
    : QMdiSubWindow((QWidget *)(parent), flags)
    , mpMdiArea(parent)
    , mTitle(title)
{
    setObjectName("BaseMdiWindow");
    setWindowTitle(title);
}
