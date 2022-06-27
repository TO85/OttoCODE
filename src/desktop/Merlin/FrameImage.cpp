#include "FrameImage.h"

#include <QPixmap>

FrameImage::FrameImage()
{

}

FrameImage::FrameImage(const QImage &qi)
    : mColorImage(qi.convertToFormat(colorImageFormat()))
{

}

QImage FrameImage::colorImage() const
{
    return mColorImage;
}

QImage FrameImage::greyImage() const
{
    if (mGreyImage.isNull())
        mGreyImage = mColorImage.convertToFormat(greyImageFormat());
    return mGreyImage;
}

QPixmap FrameImage::plane(const ColorPlane cp) const
{
    if (mPlanePixmapMap.contains(cp))
        return mPlanePixmapMap.value(cp);
    else
        return generate(cp);
}

QPixmap FrameImage::generate(const ColorPlane cp) const
{

}
