#include "BaseTaskMenu.h"

#include <QAction>

BaseTaskMenu::BaseTaskMenu(QWidget *parent)
    : QMenu(parent)
{

}

BaseTaskMenu::BaseTaskMenu(const QString &title, QWidget *parent)
    : QMenu(title, parent)
{

}

BaseTaskMenu::BaseTaskMenu(const QString &title, const QIcon &ico, QWidget *parent)
    : QMenu(title, parent)
{
    icon(ico);
}

void BaseTaskMenu::icon(const QIcon &i)
{
    setIcon(i);
}

QAction *BaseTaskMenu::addItem(const QString &title, const QIcon &icon)
{
    QAction * result = new QAction(icon, title, this);
    addAction(result);
    return result;
}
