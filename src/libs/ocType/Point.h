#pragma once
#include "ocType.h"

#include <QPoint>
#include <QPointF>

#include "Rational.h"

template <typename T> class PointT
{
public:
    PointT() : mX(0), mY(0) {;}
    PointT(const T tX, const T tY) : mX(tX), mY(tY) {;}
    PointT(const QPoint qpoint) : mX(qpoint.x()), mY(qpoint.y()) {;}

public:
    T x() const { return mX; }
    T y() const { return mY; }
    QPoint toQPoint() const { return QPoint(mX, mY); }
    QPointF toQPointF() const { return QPointF(mX, mY); }

private:
    T mX;
    T mY;
};

typedef PointT<int> Point;
typedef PointT<float> FloatPoint;
typedef PointT<Rational> RationalPoint;
