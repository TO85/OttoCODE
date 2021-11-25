#include "SCRect.h"

#include <QtDebug>
#include <QtCore/QDataStream>

#include <eirType/Success.h>
#include <eirXfr/Debug.h>

bool SCRect::contains(const QQPoint &pt) const
{
#ifdef QT_DEBUG
    Success success;
    int lx = left(), rx = right(), ty = top(), by = bottom();
    int cx = center().x(), cy = center().y(), px = pt.x(), py = pt.y();
    success.expect(lx <= px);
    success.expect(px <= rx);
    success.expect(ty <= py);
    success.expect(py <= by);
    success.validate();
    TRACEQFI << toDebugString() << Qt::endl
             << QString("{contains(%1)> L%2 <= X%3 (CX%4) <= R%5 && B%6 <= Y%7 (CY%8) <= T%9 returns %10<}")
                        .arg(pt.toDebugString()) // 1
                        .arg(lx).arg(px).arg(cx).arg(rx) // 2,3,4,5
                        .arg(by).arg(py).arg(cy).arg(ty).arg(success.toString()); // 6,7,8,9,10
    EXPECTEQ(toRect().contains(pt), success());
    return success;
#else
    return toRect().contains(pt);
#endif
}

bool SCRect::intersects(const SCRect &other) const
{
    QRect thisRect = toRect();
    QRect otherRect = other.toQRect();
    QRect isectRect = thisRect.intersected(otherRect);
    bool result = thisRect.intersects(otherRect);
    TRACEQFI << result;
    TRACE << QQRect(thisRect) << QQRect(otherRect) << QQRect(isectRect);
    TRACE << toDebugString() << other << SCRect(isectRect);
    return result;
}

QQPointF SCRect::relative(const QPoint pt) const
{
    return QPointF(qreal(pt.x() - center().x()) / width(),
                   qreal(pt.y() - center().y()) / height());
}

QQLineF SCRect::relative(const QQLine ln) const
{
    return QQLineF(relative(ln.p1()), relative(ln.p2()));
}

Rational SCRect::overlapRatio(const SCRect &other) const
{
    Rational result(0);
    QQRect thisRect = toRect();
    QQRect otherRect = other.toRect();
    QQRect interRect;
    if ( ! thisRect.intersects(otherRect)) return result;               /* /========\ */

    if (thisRect.area() > otherRect.area())
    {
        interRect = thisRect.intersected(otherRect);
        result.set(interRect.area(), thisRect.area());
    }
    else
    {
        interRect = otherRect.intersected(thisRect);
        result.set(interRect.area(), otherRect.area());
    }
    TRACEQFI << toDebugString() << other.toDebugString() << interRect << result;
    return result;
}

bool SCRect::equals(const SCRect &other) const
{
    return size() == other.size()  && center() == other.center();
}

SCRect SCRect::scaled(const qreal f, const int clip) const
{
    TRACEQFI << toDebugString() << f << clip;
    unsigned mask = ~(powerOfTwoDown(clip) - 1);
    qreal sw = qreal(width()) * f, sh = qreal(height()) * f;
    int iw = int(sw), ih = int(sh);
    TRACE << sw << sh << iw << ih << Qt::hex << iw << ih << Qt::dec;
    int w = iw & mask, h = iw & mask;
    SCRect result(QSize(w, h), center());
    TRACE << Qt::hex << mask << Qt::dec << result;
    return result;
}

SCRect SCRect::squaredByArea() const
{
    if (mSize.isSquare()) return it();
    int w = sqrt(area());
    return SCRect(QQSize(w), center());
}

QVariant SCRect::toVariant() const
{
    QVariant result;
    result.setValue(it());
    return result;
}

void SCRect::unite(const SCRect other)
{
    if (isNull()) return set(other);                                    /* /=======\ */
    if (other.isNull()) return set(it());                               /* /=======\ */
    QQRect qqrc;
    qqrc.setLeft(qMin(left(), other.left()));
    qqrc.setRight(qMax(right(), other.right()));
    qqrc.setTop(qMin(top(), other.top()));
    qqrc.setBottom(qMax(bottom(), other.bottom()));
    setQQRect(qqrc);
}

SCRect SCRect::madeSquare()
{
    TRACEQFI << toDebugString();
    if (isSquare()) return it();
    qreal areaF = qreal(area());
    int dim = qRound(sqrt(areaF));
    SCRect result(QQSize(dim), center());
    TRACE << result.toDebugString();
    return result;
}

QString SCRect::toDebugString() const
{
    return isNull()
            ? "{SCRect>null<}"
            : QQString("{SCRect: Size=W%7xH%8 Center=CX%5,CY%6 L%1,T%2~R%3,B%4}")
              .arg(left()).arg(top()).arg(right()).arg(bottom())
              .arg(center().x()).arg(center().y()).arg(width()).arg(height());
}

// ------------------------------------- non-member  ---------------------------------------

QDebug operator<<(QDebug dbg, const SCRect &scrc)
{
    dbg << scrc.toDebugString();
    return dbg;
}

bool operator == (const SCRect &scrc, const SCRect &other)
{
    return scrc.equals(other);
}

void swap(SCRect scrc, SCRect other)
{
    SCRect middle = scrc;
    scrc = other;
    other = middle;
}
