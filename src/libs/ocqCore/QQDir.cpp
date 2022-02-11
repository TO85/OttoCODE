#include "QQDir.h"

#include <Sortable>

bool QQDir::equal(const QQDir &other) const
{
    return Sortable(it()) == Sortable(other);
}

bool QQDir::less(const QQDir &other) const
{
    return Sortable(it()) < Sortable(other);
}

String QQDir::lastPath() const
{
    return String(path()).lastSection();
}
