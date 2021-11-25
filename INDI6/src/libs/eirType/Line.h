#pragma once
#include "eirType.h"

#include "Boolean.h"
#include "QQLine.h"
#include "QQPoint.h"
#include "Slope.h"

class EIRTYPE_EXPORT Line
{
public:
    Line() = default;
    Line(const QQPoint pt1, const QQPoint pt2, const bool topDown=true);
    Line(const QQLine ln, const bool topDown=true);
    Line(const Slope slope, const QQPoint pt, const bool topDown=true);
    Line(const Line &other) = default;
    ~Line() = default;
    Line &operator = (const Line &other) = default;
    void ctor();

    QQPoint point1() const { return cmPoint1; }
    QQPoint point2() const { return cmPoint2; }
    QQPoint center() const { return mCenter; }
    Slope slope() const { return mSlope; }
    qreal yInterceptF() const { return mYInterceptF; }

    int y(const int x) const;
    bool notValid() const { return point1().notValid() || point2().notValid(); }
    bool isValid() const { return ! notValid(); }
    bool isNull() const { return isValid() && (point1().x() == point2().x()); }
    bool isFlat() const { return isValid() && (point1().y() == point2().y()); }
    bool isVertical() const { return isValid() && (point1().x() == point2().x()); }
    int deltaX() const { return point2().x() - point1().x(); }
    int deltaY() const { return point2().y() - point1().y(); }
    int topDownMultiplier() const { return cmTopDown ? -1 : +1; }
    int run() const { return deltaX(); }
    int rise() const { return topDownMultiplier() * deltaY(); }
    int fall() const { return -1 * rise(); }
    Rational slide() const { return Rational(Rational::Term(fall()), Rational::Term(run())); }
    int xIntercept() const;
    QQLine segmentFromLeft(const int fromX, const int toX) const;
    QQLine segment(const int x1, const int x2);

private:
    const QQPoint cmPoint1;
    const QQPoint cmPoint2;
    const Boolean cmTopDown;
    QQLine mLine;
    QQPoint mCenter;
    Slope mSlope;
    qreal mYInterceptF;
};

