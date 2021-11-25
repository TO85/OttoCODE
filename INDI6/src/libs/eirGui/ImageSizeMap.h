#pragma once
#include "eirGui.h"

#include <eirType/QQSize.h>
#include <eirType/QQString.h>
#include <eirType/QQStringList.h>

#include "QQImage.h"

class EIRGUI_EXPORT ImageSizeMap
{
public:
    ImageSizeMap() = default;
    ImageSizeMap(const QQImage &baseImage) { setBase(baseImage); }
    ImageSizeMap(const ImageSizeMap &other) = default;
    ~ImageSizeMap() = default;
    ImageSizeMap &operator = (const ImageSizeMap &other) = default;

    bool contains(const QQSize aSize) const { return mSizeImageMap.contains(aSize); }
    bool notContains(const QQSize aSize) const { return ! contains(aSize); }
    QQSize::List sizeList() const;
    bool isBase(const QQSize aSize) const { return aSize == mBaseSize; }
    QQSize baseSize() const { return mBaseSize; }
    QQImage baseImage() const;

    void clear() { mBaseSize.invalidate(), mSizeImageMap.clear(); }
    bool setBase(const QQImage &aImage);
    bool append(const QQImage &aImage);
    QQImage image(const int scale);
    QQImage image(const QQSize aSize);

    QQStringList toDebugStrings() const;

private:
    QQSize mBaseSize;
    QMap<QSize, QQImage> mSizeImageMap;
};

Q_DECLARE_METATYPE(ImageSizeMap);

