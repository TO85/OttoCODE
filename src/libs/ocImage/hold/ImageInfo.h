#pragma once

#include <QSharedDataPointer>

class ImageInfoData;

class ImageInfo
{
public:
    ImageInfo();
    ImageInfo(const ImageInfo &);
    ImageInfo &operator=(const ImageInfo &);
    ~ImageInfo();

private:
    QSharedDataPointer<ImageInfoData> data;
};

