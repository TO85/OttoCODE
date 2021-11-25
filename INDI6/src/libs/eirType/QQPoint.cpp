#include "QQPoint.h"

#include <eirXfr/Debug.h>

#include "QQLine.h"
#include "QQPointF.h"

const QQPoint QQPoint::scmInvalid(INT_MIN, INT_MIN);

QQPointF QQPoint::toPointF() const
{
    return QQPointF(xF(), yF());
}

int QQPoint::distance(const QQPoint other) const
{
    return QQLine(it(), other).length();
}

qreal QQPoint::distanceF(const QQPoint other) const
{
    int dx = other.x() - x();
    int dy = other.y() - y();
    qreal result = sqrt(qreal(dx * dx) + qreal(dy * dy));
    TRACEQFI << other << it() << dx << dy << result;
    return result;
}

QString QQPoint::toDebugString() const
{
    return QString("{QQPoint: %1,%2}").arg(x()).arg(y());
}

uint qHash(const QQPoint &pt, uint seed)
{
    uint result = qHash(pt.x(), seed);
    result = qHash(pt.y(), result);
    return result;
}

