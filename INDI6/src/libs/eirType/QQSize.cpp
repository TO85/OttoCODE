#include "QQSize.h"

#include <eirXfr/Debug.h>


int QQSize::index(const QQPoint pt) const
{
    return (pt.y() * width()) + pt.x();
}

QQSize QQSize::scaled(const Rational r) const
{
     return QQSize((Rational(Rational::Term(width()),  1) * r).round(),
                   (Rational(Rational::Term(height()), 1) * r).round());
}

void QQSize::set(const int aWidth, const QQSize aAspect)
{
    setWidth(aWidth);
    setHeight(aAspect.aspect().inverted().multiplied(aWidth));
}

QQString QQSize::toDebugString() const
{
    return QQString("{QQSize:Ww%1xH%2 Area=%3}").
            arg(width()).arg(height()).arg(area());
}

/* --------------------------- non-member ---------------------------- */

bool operator < (const QQSize &lhs, const QQSize &rhs)
{
    if (lhs.area() == rhs.area())
        if (lhs.width() == rhs.width())
            return lhs.height() < rhs.height();
        else
            return lhs.width() < rhs.width();
    else
        return lhs.area() < rhs.area();
}


