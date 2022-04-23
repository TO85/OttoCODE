#pragma once

#include <QSize>

#include "Rational.h"

template <typename T> class SizeT
{
public:
    SizeT() : mWidth(0), mHeight(0) {;}
    SizeT(const T tWidth, const T tHeight) : mWidth(tWidth), mHeight(tHeight) {;}
    SizeT<T> & operator = (const QSize qsize) { mWidth = qsize.width(), mHeight = qsize.height(); }

public:
    T width() const { return mWidth; }
    T height() const { return mHeight; }
    T area() const { return width() * height(); }
    SizeT<T> scaled(const Rational scale) const { return SizeT<T>(mWidth * scale, mHeight * scale); }
    QSize toQSize() const { return QSize(width(), height()); }
    operator QSize() const { return toQSize(); }

private:
    SizeT<T> it() const { return *this; }

private:
    T mWidth;
    T mHeight;
};

typedef SizeT<int> Size;
typedef SizeT<float> FloatSize;
typedef SizeT<Rational> RationalSize;

