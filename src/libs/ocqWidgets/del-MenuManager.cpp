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
    qDebug() << Q_FUNC_INFO;
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

QMenu * MenuManager::primary(const Key &key, const String &text)
{
    qDebug() << Q_FUNC_INFO << key.toQString() << text
             << mKeyMenuMap.contains(key) << key.last();
    if (mKeyMenuMap.contains(key)) return mKeyMenuMap.value(key);       /* /====\ */
    QMenu *pMenu = bar()->addMenu(text.isEmpty() ? "&"+key.last().toQString() : text);
    Q_ASSERT(pMenu);
    mKeyMenuMap.insert(key, pMenu);
    return pMenu;
}

QAction * MenuManager::add(const Key &key, const String &text)
{
    QAction * result=nullptr;
    const Key tMenuKey = key.first(-1);
    const String tText = text.notEmpty() ? text : ("&"+key.last());
    qDebug() << Q_FUNC_INFO << key.toQString() << text << tMenuKey;
    qDebug() << dumpKeyMenuMap();
    QMenu *pMenu = nullptr;
    if (mKeyMenuMap.contains(tMenuKey))
    {
        pMenu = mKeyMenuMap.value(key.first(-1));
    }
    else
    {
        pMenu = primary(tMenuKey, tText);
        mKeyMenuMap.insert(tMenuKey, pMenu);
    }
    Q_ASSERT(pMenu);
    if (pMenu)
    {
        result = pMenu->addAction(tText);
        actions()->add(key, result);
    }
    return result;
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

StringList MenuManager::dumpKeyMenuMap() const
{
    StringList result;
    for (Key key : mKeyMenuMap.keys())
        result << String("<%1> = <%2>").arg(key).arg(mKeyMenuMap.value(key)->title());
    return result;
}
