#include "MenuManager.h"

#include <QApplication>
#include <QMenuBar>

#include <ActionManager>

#include "QQMainWindow.h"

MenuManager::MenuManager(QQMainWindow *main, ActionManager *actions, QObject *parent)
    : QObject{parent}
    , mpMainWindow(main)
    , mpActionManager(actions)
{
    setObjectName("MenuManager");
    qDebug("MenuManager::MenuManager()");
}

QQMainWindow *MenuManager::main() const
{
    return mpMainWindow;
}

QMenuBar *MenuManager::bar() const
{
    return main()->menuBar();
}

QMenu *MenuManager::menu(const Key &key) const
{
    return mKeyMenuMap.value(key);
}

QAction *MenuManager::action(const Key &key) const
{
    return mpActionManager->action(key);
}

QAction *MenuManager::add(const Key &key)
{
    QAction * result = mpActionManager->add(key);
    return result;
}

bool MenuManager::add(const Key &key, QAction *action)
{
    bool result = false;
    QMenu * pMenu = mKeyMenuMap.value(key.first(-1));
}
