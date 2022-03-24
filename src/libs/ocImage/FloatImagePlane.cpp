#include "FloatImagePlane.h"

#include <QImage>

FloatImagePlane::FloatImagePlane(const QImage &qimage, const Pixel::Mask mask)
    : Matrix2D<ImageFloatType>(qimage.size())
{
    set(qimage, mask);
}

void FloatImagePlane::set(const QImage &qimage, const Pixel::Mask mask)
{
    QImage tImage = qimage.convertedTo(QImage::Format_RGBA32FPx4_Premultiplied);
    Q_UNUSED(tImage); Q_UNUSED(mask); Q_ASSERT(false); // MUSTDO it
}

