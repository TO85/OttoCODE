#include "DetectRect.h"

#include <eirType/ObjectType.h>
#include <eirXfr/Debug.h>


void DetectRect::unite(const DetectRect other)
{
    rect().unite(other.rect());
    mScore += other.score();

}

QString DetectRect::toDebugString() const
{
    return QString("{DetectRect>Type=%3(%4), Rect=%1, Score=%2, Base=%5<DetectRect}")
            .arg(rect().toDebugString()).arg(score())
            .arg(type().name()).arg(type().value())
            .arg(base().toDebugString());
}

/* ------------------------- non-member ------------------------ */

bool operator == (const DetectRect &lhs, const DetectRect &rhs)
{
    if (lhs.rect().equals(rhs.rect()))                  return false;
    if (lhs.base().equals(rhs.base()))                  return false;
    if (lhs.type().value() != lhs.type().value())       return false;
    if (lhs.score() != lhs.score())                     return false;
    return true;
}

uint qHash(const DetectRect &dr, uint seed)
{
    uint result = qHash(dr.rect().center(), seed);
    result = qHash(dr.rect().size(), result);
    result = qHash(dr.score(), result);
    return result;
}

QDebug operator << (QDebug dbg, const DetectRect &dr)
{
    dbg << dr.toDebugString(); return dbg;
}
