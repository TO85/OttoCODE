#include "QQPointF.h"

#include <cmath>

bool QQPointF::fuzzyCompare(const QQPointF &other) const
{
    return qFuzzyCompare(x(), other.x())
            && qFuzzyCompare(y(), other.y());
}

int QQPointF::distanceI(const QQPoint other) const
{
    int dx = other.x() - x(), dy = other.y() - y();
    qreal dxF = qreal(dx), dyF = qreal(dy);
    return qRound64(sqrt((dxF * dxF) + (dyF * dyF)));
}

qreal QQPointF::distance(const QQPointF other) const
{
    qreal dx = other.x() - x(), dy = other.y() - y();
    return sqrt((dx * dx) + (dy * dy));
}
