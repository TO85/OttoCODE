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
    RectT(const QRect other) { mSize = other.size(), mCenter = other.center(); }
    RectT(const SizeT<T> size, const PointT<T> center) { mSize = size, mCenter = center; }
    RectT<T> operator = (const RectT<T> & other) { mSize = other.mSize, mCenter = other.mCenter; return it(); }
    RectT<T> operator = (const QRect & qrect) { mSize = qrect.size(), mCenter = qrect.center(); return it(); }

public:
    SizeT<T> size() const { return mSize; }
    QPoint center() const { return mCenter; }
    QPoint topLeft() const { return QPoint(mCenter.x() - (mSize.width()  / 2),
                                           mCenter.y() - (mSize.height() / 2)); }
    T top() const { return topLeft().y(); }
    T left() const  { return topLeft().x(); }
    T width() const { return size().width(); }
    T height() const { return size().height(); }
    QRect toQRect() const { return QRect(left(), top(), width(), height()); }
    operator QRect() const { return toQRect(); }
    RectT<T> scaled(const Rational scale) const { return RectT<T>(mSize.scaled(scale), mCenter); }

public:
    QSize size(const QSize sz) { return mSize = sz; }
    QSize size(const QSize sz, const Rational scale) { return mSize = sz * scale; }
    QPoint center(const QPoint pt) { return mCenter = pt; }

private:
    RectT<T> it() const { return *this; }

private:
    SizeT<T> mSize;
    PointT<T> mCenter;
};

typedef RectT<int> Rect;
typedef RectT<float> FloatRect;
typedef RectT<Rational> RationalRect;
