#pragma once
#include "eirType.h"

#include <QtDebug>
#include <QtCore/QLine>
#include <QtCore/QMetaType>

#include <cmath>

#include "QQPoint.h"
#include "QQString.h"
#include "Slope.h"

class EIRTYPE_EXPORT QQLine
{
public:
    typedef QList<QQLine> List;

public:
    QQLine() = default;
    QQLine(const QLine other) : mPoint1(other.p1()), mPoint2(other.p2()) {;}
    QQLine(const QQPoint pt1, const QQPoint pt2) : mPoint1(pt1), mPoint2(pt2) {;}
    QQLine(const QQLine &other) = default;
    ~QQLine() = default;
    QQLine &operator = (const QQLine &other) = default;

    QQPoint p1() const { return mPoint1; }
    QQPoint p2() const { return mPoint2; }
    int dX() const { return p2().x() - p1().x(); }
    int dY() const { return p2().y() - p1().y(); }
    QQPoint dXY() const { return QQPoint(dX(), dY()); }
    bool isNull() const { return p1().isNull() && p2().isNull(); }
    bool isEitherNull() const { return p1().isNull() || p2().isNull(); }
    bool notNull() const { return ! isNull(); }
    bool isEmpty() const { return p1() == p2(); }
    QQLine it() const { return *this; }
    QQLine &it() { return *this; }
    int rise() const { return p2().y() - p1().y(); }
    int run()  const { return p2().x() - p1().x(); }
    QQPoint center() const;
    Slope slope() const { return Slope(rise(),run()); }
    bool isVertical() const { return slope().isNaN(); }
    bool isFlat() const { return slope().isFlat(); }
    bool notFlat() const { return ! isFlat(); }
    qreal lengthF(const qreal ifEmpty=qQNaN()) const;
    int length(const int ifEmpty=0) const { return isEmpty() ? ifEmpty : qRound(lengthF());}
    QLine toQLine() const { return QLine(p1(), p2()); }
    operator QLine () const { return toQLine(); }

    void setP1(const QQPoint pt1) { mPoint1 = pt1; }
    void setP2(const QQPoint pt2) { mPoint2 = pt2; }
    void set(const QQPoint pt1, const QQPoint pt2) { setP1(pt1), setP2(pt2); }
    void nullify() { set(QQPoint(), QQPoint()); }
    void translate(const QQPoint dxy) { set(p1()+dxy, p2()+dxy); }
    QQLine &operator += (const QQPoint dxy) { translate(dxy); return it(); }

    QQString toDebugString() const;

private:
    QQPoint mPoint1;
    QQPoint mPoint2;
};

Q_DECLARE_METATYPE(QQLine);

extern EIRTYPE_EXPORT QQLine operator + (const QQLine ln, const QQPoint dxy);
extern EIRTYPE_EXPORT QDebug operator << (QDebug dbg, const QQLine ln);
