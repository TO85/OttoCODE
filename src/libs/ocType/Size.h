#pragma once

#include "Rational.h"

template <typename T> class SizeT
{
    SizeT() : mWidth(0), mHeight(0) {;}
    SizeT(const T tWidth, const T tHeight) : mWidth(tWidth), mHeight(tHeight) {;}
    T width() const { return mWidth; }
    T height() const { return mHeight; }
    T area() const { return width() * height(); }

private:
    T mWidth;
    T mHeight;
};

typedef SizeT<int> Size;
typedef SizeT<float> FloatSize;
typedef SizeT<Rational> RationalSize;

