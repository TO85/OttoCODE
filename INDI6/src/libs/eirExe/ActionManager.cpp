#include "ActionManager.h"

#include <QtWidgets/qaction.h> // TODO why?

#include <eirXfr/Debug.h>

ActionManager::ActionManager(QObject *parent)
    : QObject(parent)
{
    setObjectName("ActionManager");
    TRACEQFI << QOBJNAME(parent) << QOBJNAME(this);
}

QAction *ActionManager::action(const MultiName &aName)
{
    return mNameActionDMap.at(aName);
}

void ActionManager::add(const MultiName &aName, QAction *pAction)
{
    AEXPECTPTR(pAction);
    TRACEQFI << QOBJNAME(this) << aName() << QOBJNAME(pAction) << pAction->text();
    setObjectName("ActionManager:" + aName);
    mNameActionDMap.insertUnique(aName, pAction);
}

QAction *ActionManager::add(const MultiName &aName)
{
    return add(aName, aName.lastSegment().toString());
}

QAction *ActionManager::add(const MultiName &aName, const QQString &aText)
{
    QAction * result = new QAction(aText, this);
    add(aName, result);
    return result;
}
