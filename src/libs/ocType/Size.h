#pragma once

#include <QSize>

#include "Rational.h"

template <typename T> class SizeT
{
public:
    SizeT() { set(0, 0); }
    SizeT(const QSize sz) { (void)set(sz.width(), sz.height()); }
    SizeT(const T tWidth, const T tHeight) { (void)set(tWidth, tHeight); }
    SizeT(const SizeT baseSize, const int maxDim);
    SizeT<T> & operator = (const QSize qsize) { set(qsize.width(), qsize.height()); return it(); }

public:
    T width() const { return mWidth; }
    T height() const { return mHeight; }
    T area() const { return width() * height(); }
    SizeT<T> scaled(const Rational scale) const { return SizeT<T>(mWidth * scale, mHeight * scale); }
    QSize toQSize() const { return QSize(width(), height()); }
    operator QSize() const { return toQSize(); }

public:
    void set(const T tWidth, const T tHeight) { mWidth = tWidth, mHeight = tHeight; }
    SizeT<T> andAssign(const T tFactor) { mWidth &= tFactor - 1, mHeight &= tFactor - 1; return it(); }
    SizeT<T> operator &=(const T tFactor) { return andAssign(tFactor); }


public: // static
    static SizeT<T> sizeFor(const SizeT<T> baseSize, const int maxDim);

private:
    SizeT<T> it() const { return *this; }
    SizeT<T> & it() { return *this; }

private:
    T mWidth;
    T mHeight;
};

typedef SizeT<int> Size;
typedef SizeT<float> FloatSize;
typedef SizeT<Rational> RationalSize;

