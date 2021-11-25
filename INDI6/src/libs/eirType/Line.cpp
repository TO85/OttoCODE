#include "Line.h"

#include <eirXfr/Debug.h>

Line::Line(const QQPoint pt1, const QQPoint pt2, const bool topDown)
    : cmPoint1(pt1)
    , cmPoint2(pt2)
    , cmTopDown(topDown)

{
    TRACEQFI << pt1 << pt2 << topDown;
    ctor();
}

Line::Line(const QQLine ln, const bool topDown)
    : cmPoint1(ln.p1())
    , cmPoint2(ln.p2())
    , cmTopDown(topDown)
{
    TRACEQFI << ln << topDown;
    ctor();
}

Line::Line(const Slope slope, const QQPoint pt, const bool topDown)
    : cmPoint1(pt)
    , cmPoint2(pt + QQPoint(slope.run(), slope.rise()))
    , cmTopDown(topDown)
{
    TRACEQFI << slope << pt << topDown;
    ctor();
}

void Line::ctor()
{
    mLine = QQLine(point1(), point2());
    mCenter = mLine.center();
    mSlope = Slope(deltaY(), deltaX());
    mYInterceptF = point1().y() - (mSlope * Rational(Rational::Term(point1().x()), 1));
    qreal yInterceptF2 = point2().y() - (mSlope * Rational(Rational::Term(point2().x())));
    TRACEQFI << "mLine:" << mLine << "mCenter:" << mCenter << "mSlope:" << mSlope
             << "mYInterceptF:" << mYInterceptF << yInterceptF2;
    REXPECT(cmTopDown.isValid());
    REXPECT(qAbs(mYInterceptF - yInterceptF2) < 0.002);
}

int Line::y(const int x) const
{
    int r = qRound((slope() * Rational(Rational::Term(x), 1)).toReal() + yInterceptF());
    TRACEQFI << "r = qRound(slope() * qreal(x)) + yInterceptF()"
             << r << slope() << x << yInterceptF();
    return r;
}

QQLine Line::segmentFromLeft(const int fromX, const int width) const
{
    int fX = point1().x() + fromX;
    int tX = fX + width;
    QQPoint fromPoint(fX, y(fX));
    QQPoint   toPoint(tX, y(tX));
    QQLine ln(fromPoint, toPoint);
    TRACEQFI << fromX << width << "mLine" << mLine << "mCenter" << mCenter
             << "mSlope" << mSlope << "mYInterceptF" << mYInterceptF << "result" << ln;
    return ln;
}

QQLine Line::segment(const int x1, const int x2)
{
    QQPoint p1(x1, y(x1));
    QQPoint p2(x2, y(x2));
    QQLine ln(p1, p2);
    TRACEQFI << x1 << x2 << ln;
    return ln;
}


int Line::xIntercept() const
{
    MUSTDO(it); return INT_MIN;

}

