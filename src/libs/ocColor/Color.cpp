#include "Color.h"


Color::Color(const QColor &aColor, QObject *parent)
    : QObject(parent)
    , mQColor(aColor)
{
    set();
}

bool Color::isValidIndex(const int ix) const
{
    return ix >= 0 && ix < componentCount();
}

ColorFloatType Color::componentF(const int ix) const
{
    return isValidIndex(ix) ? mColorRationalList[ix].toFloat() : floatInvalid();
}

ColorRationalType Color::componentR(const int ix) const
{
    return isValidIndex(ix) ? mColorRationalList[ix] : rationalInvalid();
}

ColorUShortIntType Color::componentUS(const int ix) const
{

}

ColorSShortIntType Color::componentSS(const int ix) const
{

}

ColorULongIntType Color::componentUL(const int ix) const
{

}

ColorSLongIntType Color::componentSL(const int ix) const
{

}

ColorRationalType & Color::component(const int ix)
{
    static ColorRationalType scrt = rationalInvalid();
    return isValidIndex(ix) ? mColorRationalList[ix] : scrt;
}

QQString Color::toDebugSString() const
{

}
