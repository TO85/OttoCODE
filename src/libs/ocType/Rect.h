#pragma once
#include "ocType.h"

#include <QPoint>
#include <QRect>
#include <QSize>

#include "Point.h"
#include "Size.h"

template <typename T> class RectT
{
public:
    RectT() {;}
    RectT(const QRect other);
    RectT(const QSize size, const PointT<T> center);

public:
    QSize size() const { return mSize; }
    QPoint center() const { return mCenter; }
    T top() const { }
    T left() const;
    QPoint topLeft() const;
    QRect toQRect() const;

public:
    QSize size(const QSize sz) { return mSize = sz; }
    QSize size(const QSize sz, const Rational scale) { return mSize = sz * scale; }
    QPoint center(const QPoint pt) { return mCenter = pt; }

private:
    QSize mSize;
    PointT<T> mCenter;
};

typedef RectT<int> Rect;
typedef RectT<float> FloatRect;
typedef RectT<Rational> RationalRect;
