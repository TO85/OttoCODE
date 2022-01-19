#include "MenuManager.h"

MenuManager::MenuManager(ActionManager *actions)
    : QObject{actions}
    , mpActionManager(actions)
{
    setObjectName("MenuManager");
    qDebug("MenuManager::MenuManager()");
}
