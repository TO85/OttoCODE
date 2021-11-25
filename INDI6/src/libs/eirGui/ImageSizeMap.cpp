#include "ImageSizeMap.h"

#include <eirXfr/Debug.h>

QQSize::List ImageSizeMap::sizeList() const
{
    QQSize::List result;
    for (QSize sz : mSizeImageMap.keys())
        result << QQSize(sz);
    return result;
}

QQImage ImageSizeMap::baseImage() const
{
    TRACEQFI << mBaseSize << contains(mBaseSize);
    return contains(mBaseSize) ? mSizeImageMap.value(mBaseSize) : QQImage();
}

bool ImageSizeMap::setBase(const QQImage &aImage)
{
    TRACEQFI << aImage << contains(aImage.size());
    if (mSizeImageMap.contains(aImage.size())) return false;
    mBaseSize = aImage.size();
    EXPECT(append(aImage));
    EXPECT(mSizeImageMap.contains(aImage.size()));
    return mSizeImageMap.contains(aImage.size());
}

bool ImageSizeMap::append(const QQImage &aImage)
{
    TRACEQFI << aImage;
    if (mSizeImageMap.contains(aImage.size())) return false;
    mSizeImageMap.insert(aImage.size(), aImage);
    return mSizeImageMap.contains(aImage.size());
}

QQImage ImageSizeMap::image(const QQSize aSize)
{
    TRACEQFI << aSize << contains(aSize) << mSizeImageMap.keys();
    if (notContains(aSize)) append(baseImage().resized(aSize));
    return contains(aSize) ? mSizeImageMap.value(aSize) : QQImage();
}

QQImage ImageSizeMap::image(const int scale)
{
    TRACEQFI << scale << mBaseSize * scale << contains(mBaseSize * scale);
    return image(mBaseSize * scale);
}

QQStringList ImageSizeMap::toDebugStrings() const
{
    QQStringList result;
    result << QString("BaseSize=" + mBaseSize.toDebugString());
    for (QQSize sz : mSizeImageMap.keys())
        result << QQString("%1 = %2").arg(sz.toDebugString(),
                                          mSizeImageMap.value(sz).toDebugString());
    return result;
}
