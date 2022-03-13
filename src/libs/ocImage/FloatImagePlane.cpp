#include "FloatImagePlane.h"

#include <QImage>

FloatImagePlane::FloatImagePlane(const QImage &qimage, const int rgbaMask)
    : Matrix2D<ImageFloatType>(qimage.size())
{
    set(qimage, rgbaMask);
}

