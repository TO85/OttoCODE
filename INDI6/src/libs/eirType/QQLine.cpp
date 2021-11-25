#include "QQLine.h"

QQPoint QQLine::center() const
{
    return QQPoint((p1().x() + p2().x()) / 2,
                   (p1().y() + p2().y()) / 2);
}

qreal QQLine::lengthF(const qreal ifEmpty) const
{
    if (isEmpty()) return ifEmpty;
    return sqrt(qreal((rise() * rise()) + (run() * run())));
}

QQString QQLine::toDebugString() const
{
    return QString("{QQLine: %1~%2 Center=%3 Length=%4 Slope=%5}")
            .arg(p1().toDebugString(), p2().toDebugString(), center().toDebugString())
            .arg(length()).arg(slope().toString());
}

/* -------------------------- non-member ------------------------- */

QQLine operator + (const QQLine ln, const QQPoint dxy)
{
    QQLine result = ln;
    result.translate(dxy);
    return result;
}

QDebug operator << (QDebug dbg, const QQLine ln)
{
    dbg << ln.toDebugString(); return dbg;
}
