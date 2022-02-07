#include "DirectoryTreeWidget.h"

DirectoryTreeWidget::DirectoryTreeWidget(QWidget *parent)
    : QTreeWidget(parent)
{
    setObjectName("DirectoryTreeWidget");
}

DirectoryTreeWidget::Item::Item(const QQDir &dir)
    : mDir(dir)
{
    setText(0, dir.lastPath());
}
