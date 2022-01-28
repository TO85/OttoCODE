#include "ActionManager.h"

#include <QtDebug>
#include <QAction>

ActionManager::ActionManager(QObject *parent)
    : QObject{parent}
{
    setObjectName("ActionManager");
    qDebug("ActionManager::ActionManager()");
}

bool ActionManager::contains(const Key &key) const
{
    return mKeyActionMap.contains(key);
}

QAction *ActionManager::action(const Key &key) const
{
    return mKeyActionMap.value(key);
}

QAction *ActionManager::add(const Key &key, const QString &text)
{
    QAction *pAction = new QAction(text.isEmpty() ? key.last().toString() : text, this);
    add(key, pAction);
    return pAction;
}

void ActionManager::add(const Key &key, QAction *action)
{
    mKeyActionMap.insert(key, action);
    emit actionAdded(key, action);
}
