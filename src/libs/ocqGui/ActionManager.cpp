#include "ActionManager.h"

#include <QtDebug>
#include <QAction>
#include <QMetaMethod>

ActionManager::ActionManager(QObject *parent)
    : QObject{parent}
{
    setObjectName("ActionManager");
    qDebug(Q_FUNC_INFO);
}

bool ActionManager::contains(const Key &key) const
{
    return mKeyActionMap.contains(key);
}

QAction *ActionManager::action(const Key &key) const
{
    return mKeyActionMap.value(key);
}

bool ActionManager::connect(const Key &key, const QObject *actor, const QByteArray &signature)
{
    bool result = false;
    const QAction *pAction = action(key);
    QMetaMethod actionMethod = method(pAction, "triggered()");
    QMetaMethod actorMethod = method(actor, signature);
    if (actionMethod.isValid() && actorMethod.isValid())
        result = QObject::connect(pAction, actionMethod, actor, actorMethod);
    return result;
}

QAction *ActionManager::add(const Key &key, const QString &text)
{
    QAction *pAction = new QAction(text.isEmpty() ? key.last().toString() : text, this);
    add(key, pAction);
    return pAction;
}

void ActionManager::add(const Key &key, QAction *action)
{
    action->setObjectName("ActionManager:"+key.toString());
    mKeyActionMap.insert(key, action);
    emit actionAdded(key, action);
}

QMetaMethod ActionManager::method(const QObject *object, const QByteArray &signature)
{
    qDebug() << Q_FUNC_INFO << object->objectName() << signature;
    const QMetaObject *pMetaObject = object->metaObject();
    const int nMethods = pMetaObject->methodCount();
    for (int ix = pMetaObject->methodOffset(); ix < nMethods; ++ix)
    {
        const QMetaMethod ixMethod = pMetaObject->method(ix);
        const QByteArray ixSignature = ixMethod.methodSignature();
        if (signature == ixSignature)
            return ixMethod;                                            /* /====\ */
    }
    return QMetaMethod();
}
