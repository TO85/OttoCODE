#pragma once

#include <QLine>
#include <QLineF>

#include "Point.h"
#include "Size.h"

template <typename T> class LineT
{
public:
    LineT(const QRect other);
    LineT(const PointT<T> p1, const PointT<T> p2);

public:
    T p1() const { return mP1; }
    T p2() const { return mP2; }
    T top() const { return qMin(p1().y(), p2().y()); }
    T bottom() const { return qMax(p1().y(), p2().y()); }
    T left() const { return qMin(p1().x(), p2().x()); }
    T right() const { return qMax(p1().x(), p2().x()); }
    T width() const { return qAbs(right() - left()); }
    T height() const { return qAbs(bottom() - top()); }
    SizeT<T> size() const { return SizeT<T>(width(), height()); }
    PointT<T> topLeft() const { return PointT<T>(left(), top()); }
    PointT<T> bottomRight() const { return PointT<T>(right(), bottom()); }
    PointT<T> center() const { return PointT<T>((left() + right() / 2), (top() + bottom()) / 2); }
    QLine toQLine() const { return QLine(p1(), p2()); }
    QLineF toQLineF() const { return QLineF(p1(), p2()); }

public:

private:
    PointT<T> mP1, mP2;
};

typedef LineT<int> Line;
typedef LineT<float> FloatLine;
typedef LineT<Rational> RationalLine;
