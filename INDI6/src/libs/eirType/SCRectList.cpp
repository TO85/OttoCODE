#include "SCRectList.h"

#include <QtDebug>

#include <eirXfr/Debug.h>

QDebug operator<<(QDebug dbg, const SCRectList &scrcs)
{
    dbg << "SCRectList" << scrcs.count() << "elements: ";
    foreach (SCRect scrc, scrcs) dbg << scrc.toDebugString();
    return dbg;
}


SCRect &SCRectList::at(const int ix)
{
    EXPECT(isValidIndex(ix));
    return operator[](ix);
}

SCRect SCRectList::at(const int ix) const
{
    EXPECT(isValidIndex(ix));
    return operator[](ix);
}

QVector<QRect> SCRectList::toQRectVector() const
{
    QVector<QRect> qrv;
    foreach (SCRect scrc, *this) qrv << scrc.toQRect();
    return qrv;
}

SCRect SCRectList::unified() const
{
    QQRect urect = first().toRect();
    foreach (SCRect scrc, mid(1)) urect |= scrc;
    TRACEQFI << mid(0) << urect;
    return urect;
}

QQStringList SCRectList::toStringList() const
{
    QQStringList result;
    result << "SCRectList:";
    foreach (SCRect scrc, it())
        result << scrc.toDebugString();
    return result;
}
