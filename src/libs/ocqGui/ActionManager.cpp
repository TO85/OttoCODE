#include "ActionManager.h"

#include <QtDebug>
#include <QAction>
#include <QMetaMethod>

#include <Key>


ActionManager::ActionManager(QObject *parent)
    : QObject{parent}
{
    setObjectName("ActionManager");
    qDebug() << Q_FUNC_INFO;
}

bool ActionManager::contains(const Key &key) const
{
    return mKeyActionMap.contains(key);
}

QAction *ActionManager::action(const Key &key) const
{
    qDebug() << Q_FUNC_INFO << key.toQString();
    Q_ASSERT(contains(key));
    return mKeyActionMap.value(key);
}

bool ActionManager::connectSlot(const Key &key, const QObject *actor,
                                const QByteArray &signature,
                                const bool scanParents)
{
    Q_ASSERT(actor);
    qDebug() << Q_FUNC_INFO << key.toQString() << actor->objectName() << signature << scanParents;
    Q_ASSERT(contains(key));
    bool result = false;
    const QAction *pAction = action(key);
    Q_ASSERT(pAction);
    QMetaMethod actionMethod = method(pAction, "triggered()");
    QMetaMethod actorMethod = method(actor, signature, scanParents);
    Q_ASSERT(actionMethod.isValid());
    Q_ASSERT(actorMethod.isValid());
    if (actionMethod.isValid() && actorMethod.isValid())
        result = QObject::connect(pAction, actionMethod, actor, actorMethod);
    Q_ASSERT(result);
    return result;
}

QAction *ActionManager::add(const Key &key, const QQString &text)
{
    qDebug() << Q_FUNC_INFO << key.toQString() << text;
    QQString tActionText = text.isEmpty() ? ("&"+key.last()) : text;
    QAction *pAction = new QAction(tActionText);
    add(key, pAction);
    return pAction;
}

void ActionManager::add(const Key &key, QAction *action)
{
    Q_ASSERT(action);
    action->setObjectName("ActionManager:"+key.toQString());
    qDebug() << Q_FUNC_INFO << key.toQString() << action->objectName();
    mKeyActionMap.insert(key, action);
    emit actionAdded(key, action);
}

QMetaMethod ActionManager::method(const QObject *object,
                                  const QByteArray &signature,
                                  const bool scanParents)
{
    Q_ASSERT(object);
    qDebug() << Q_FUNC_INFO << object->objectName() << signature;
    QMetaMethod result;
    const QMetaObject *pMetaObject = object->metaObject();
    const int nMethods = pMetaObject->methodCount();
    for (int ix = scanParents ? 0 : pMetaObject->methodOffset();
         (ix < nMethods) && ( ! result.isValid());
         ++ix)
    {
        const QMetaMethod ixMethod = pMetaObject->method(ix);
        const QByteArray ixSignature = ixMethod.methodSignature();
        if (signature == ixSignature)
            result = ixMethod;
    }
    qDebug() << result.name() << result.parameterNames();
    return result;
}

