#include "QQVariantList.h"

#include <eirXfr/Debug.h>

int QQVariantList::resize(const int newCount)
{
    TRACEQFI << newCount << count();
    while (count() < newCount)
        append(QQVariant());
    while (newCount < count())
        removeLast();
    return count();
}
