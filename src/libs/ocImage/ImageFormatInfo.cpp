#include "ImageFormatInfo.h"

class ImageFormatInfoData : public QSharedData
{
public:
    KeySeg dmKey;


};

ImageFormatInfo::ImageFormatInfo() : data(new ImageFormatInfoData)
{

}

ImageFormatInfo::ImageFormatInfo(const ImageFormatInfo &rhs)
    : data{rhs.data}
{

}

ImageFormatInfo &ImageFormatInfo::operator=(const ImageFormatInfo &rhs)
{
    if (this != &rhs)
        data.operator=(rhs.data);
    return *this;
}

ImageFormatInfo::~ImageFormatInfo()
{

}

KeySeg ImageFormatInfo::key() const
{
    Q_ASSERT(data);
    return data->dmKey;
}
