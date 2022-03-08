#include "QQDir.h"

#include <Sortable>

bool QQDir::isNull() const
{
    return it() == nullDir();
}

QString QQDir::lastPath() const
{
    const QString tPath = path();
    return tPath.isEmpty() ? QString() : tPath.split('/').last();
}

QDir QQDir::smNullDir = QQDir("/nul");

