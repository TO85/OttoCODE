#include "QQDir.h"

#include <Sortable>

bool QQDir::isNull() const
{
    return it() == nullDir();
}

String QQDir::lastPath() const
{
    return String(path()).lastSection();
}

QDir QQDir::smNullDir = QQDir("/nul");

