#pragma once
#include "ocColor_global.h"

#include <QList>

#include <Rational>

typedef float ColorFloatType;
typedef Rational ColorRationalType;
typedef quint8 ColorUShortIntType;
typedef quint8 ColorSShortIntType;
typedef qint16 ColorULongIntType;
typedef qint16 ColorSLongIntType;
typedef QList<ColorFloatType> ColorFloatList;
typedef QList<ColorRationalType> ColorRationalList;
typedef QList<ColorUShortIntType> ColorUShortIntList;
typedef QList<ColorSShortIntType> ColorSShortIntList;
typedef QList<ColorULongIntType> ColorULongIntList;
typedef QList<ColorSLongIntType> ColorSLongIntList;

class OCCOLOR_EXPORT ocColor
{
public:
    ocColor();
};
