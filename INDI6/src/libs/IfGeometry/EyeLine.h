#pragma once
#include "IfGeometry.h"

#include <eirType/QQLine.h>

#include <QtCore/QList>

#include <eirType/QQPoint.h>
#include <eirType/QQSize.h>

#include "EyeLineF.h"

class IFGEOMETRY_EXPORT EyeLine : public QQLine
{
public:
    typedef QList<EyeLine> List;

public:
    EyeLine(const QQPoint offset) : mOffset(offset) {;}
    EyeLine(const QQLine other, const QQPoint offset=QQPoint()) : QQLine(other), mOffset(offset) {;}
    EyeLine(const QQPoint leye, const QQPoint reye, const QQPoint offset=QQPoint())
        : QQLine(leye, reye), mOffset(offset) {;}
    EyeLine(const QQPoint center, const int distance, const QQPoint offset=QQPoint());
    EyeLine(const EyeLineF elf, const QQSize size, const QQPoint offset=QQPoint());
    EyeLine() = default;
    EyeLine(const EyeLine &other) = default;
    ~EyeLine() = default;
    EyeLine &operator = (const EyeLine &other) = default;

public: // getters
    QQPoint leftPoint() const { return p1();}
    QQPoint rightPoint() const { return p2();}
    QQPoint offset() const { return mOffset; }

public: // status
    int top() const { return qMin(leftPoint().y(), rightPoint().y()); }
    int left() const { return leftPoint().x(); }
    int right() const { return rightPoint().x(); }
    int distance() const { return length(); }
    qreal distanceF() const { return qreal(length()); }
    bool isLeftNull() const { return leftPoint().isNull(); }
    bool isRightNull() const { return rightPoint().isNull(); }
    Rational expectedEyeWidth() const { return Rational(distance(), 3); }
    QQLine offsetLine() const { return it() + offset(); }
    QQLine lineToLeft(const QQPoint aPoint)  const { return QQLine(aPoint, leftPoint());  }
    QQLine lineToRight(const QQPoint aPoint) const { return QQLine(aPoint, rightPoint()); }

    void set(const EyeLine other) { setLeft(other.leftPoint()), setRight(other.rightPoint()); }
    void set(const QQPoint offset) { mOffset = offset; }
    void setLeft (const QQPoint leyept) { QQLine::setP1(leyept); }
    void setRight(const QQPoint reyept) { QQLine::setP2(reyept); }

    QQString toDebugString() const;

private:
    EyeLine it() const { return *this; }
    EyeLine &it() { return *this; }

private:
    QQPoint mOffset;
};

