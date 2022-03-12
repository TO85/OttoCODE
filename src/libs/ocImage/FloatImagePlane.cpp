#include "FloatImagePlane.h"

FloatImagePlane::FloatImagePlane(const QImage &qimage, const int rgbaMask)
    : Matrix2D<ImageFloatType>(qimage.size())
{
    set(qimage, rgbaMask);
}

