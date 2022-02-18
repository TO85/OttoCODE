#pragma once

#include <QSharedDataPointer>
class ImageFormatInfoData;

#include <KeySeg>

class ImageFormatInfo
{
public:
    ImageFormatInfo();
    ImageFormatInfo(const ImageFormatInfo &);
    ImageFormatInfo &operator=(const ImageFormatInfo &);
    ~ImageFormatInfo();

public:
    KeySeg key() const;

private:
    QSharedDataPointer<ImageFormatInfoData> data;
};

