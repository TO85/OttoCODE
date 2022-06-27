#include "Actions.h"

#include <QAction>

BaseActions::BaseActions(QObject *parent)
    : QObject{parent}
{

}

QAction *BaseActions::action(const Key keyName) const
{
    return mKeyActionMap.value(keyName);
}

void BaseActions::add(const Key keyName, QAction *pAction)
{
    pAction->setObjectName("Action:" + keyName());
    mKeyActionMap.insert(keyName, pAction);
}
