#include "FileTaskMenu.h"

#include <QCoreApplication>

FileTaskMenu::FileTaskMenu(const QString &title, QWidget *parent)
    : BaseTaskMenu(title, parent)
{

}

void FileTaskMenu::setup()
{
    QAction * pNewAction = addItem(tr("&New"));
    connect(pNewAction, &QAction::triggered, this, &FileTaskMenu::FileNewTask);
    QAction * pOpenAction = addItem(tr("&Open"));
    connect(pOpenAction, &QAction::triggered, this, &FileTaskMenu::FileOpenTask);
    QAction * pExitAction = addItem(tr("E&xit"));
    connect(pExitAction, &QAction::triggered, qApp, &QCoreApplication::quit);
}
