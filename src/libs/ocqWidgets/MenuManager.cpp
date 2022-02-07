#include "MenuManager.h"

#include <QApplication>
#include <QMenuBar>

#include <ActionManager>

#include "QQMainWindow.h"

MenuManager::MenuManager(QQMainWindow *main, ActionManager *actions, QObject *parent)
    : QObject{parent}
    , mpMainWindow(main)
    , mpActionManager(actions)
    , mpMenuBar(mpMainWindow->menuBar())
{
    setObjectName("MenuManager");
    qDebug(Q_FUNC_INFO);
}

QQMainWindow *MenuManager::main() const
{
    Q_ASSERT(mpMainWindow);
    return mpMainWindow;
}

QMenuBar *MenuManager::bar() const
{
    Q_ASSERT(main()->menuBar());
    return main()->menuBar();
}

QMenu *MenuManager::menu(const Key &key) const
{
    Q_ASSERT(mKeyMenuMap.contains(key));
    return mKeyMenuMap.value(key);
}

ActionManager *MenuManager::actions() const
{
    Q_ASSERT(mpActionManager);
    return mpActionManager;
}

QAction *MenuManager::action(const Key &key) const
{
    Q_ASSERT(mpActionManager);
    Q_ASSERT(mpActionManager->contains(key));
    return mpActionManager->action(key);
}

QMenu * MenuManager::addPrimary(const Key &key, const String &text)
{
    qDebug() << Q_FUNC_INFO << key.toQString() << text;
    if (mKeyMenuMap.contains(key)) return mKeyMenuMap.value(key);       /* /====\ */
    QMenu *pMenu = bar()->addMenu(text.isEmpty() ? "&"+key.last().toQString() : text);
    mKeyMenuMap.insert(key, pMenu);
    return pMenu;
}

QAction *MenuManager::add(const Key &key, const String &text)
{
    qDebug() << Q_FUNC_INFO << key.toQString() << text;
    QMenu *pMenu = mKeyMenuMap.value(key.first(-1));
    if (nullptr == pMenu) return nullptr;                               /* /====\ */
    QAction *pAction = pMenu->addAction(text.isEmpty() ? "&"+key.last().toQString() : text);
    actions()->add(key, pAction);
    return pAction;
}

bool MenuManager::add(const Key &key, QAction *action)
{
    qDebug() << Q_FUNC_INFO << key.toQString() << action->objectName();
    Q_ASSERT(false); // MUSTDO if used
    QMenu * pMenu = mKeyMenuMap.value(key.first(-1));
    if (nullptr == pMenu) return false;                                /* /====\ */
    pMenu->addAction(action);
    return true;
}
