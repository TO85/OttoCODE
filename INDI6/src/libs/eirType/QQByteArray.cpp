#include "QQByteArray.h"

#include <eirXfr/Debug.h>

#include "QQStringList.h"

QQByteArray::QQByteArray(const quint64 aU64)
{
    resize(sizeof(aU64));
    memcpy(data(), &aU64, size());
}

QQString QQByteArray::toString(const int first) const
{
    return QQString::formatMessage4Var("Count=%1 >%2<", count(),
                                       (count() < first) ? mid(0) : (mid(0, first-4) + " ..."));
}

QQStringList QQByteArray::segment(const int segmentBytes) const
{
    QQStringList result;
    QQByteArray tCopy = it();
    while (tCopy.notEmpty())
        result.append(tCopy.takeRight(segmentBytes).toString().toQString());
    return result;
}

QQByteArray QQByteArray::takeRight(const int aCount)
{
    QQByteArray result = right(aCount);
    chop(aCount);
    return result;
}

QQString QQByteArray::toInfoString(const int first) const
{
    QQByteArray tBA = left(first);
    QQString tMore = (first < count()) ? "<+" : "";
    return isNull() ? "{null}" : QQString("%1:%2 %3")
        .formatMessage(count(), tBA.toHex()+tMore, tBA.toString().print()+tMore);
}

QQString QQByteArray::toDebugString(const int first) const
{
    return "{QQByteArray: " + toString(first) + "}";
}
