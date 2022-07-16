#include "ColorFloatQImage.h"

ColorFloatQImage::ColorFloatQImage(const QImage other)
{
    set(other);
}

QImage ColorFloatQImage::set(const QImage other)
{
    QImage result(other);
    result.convertTo(QImage::Format_RGBA32FPx4_Premultiplied);
    return result;
}

