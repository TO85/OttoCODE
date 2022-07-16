#include "ImageInfo.h"

class ImageInfoData : public QSharedData
{
public:

};

ImageInfo::ImageInfo() : data(new ImageInfoData)
{

}

ImageInfo::ImageInfo(const ImageInfo &rhs)
    : data{rhs.data}
{

}

ImageInfo &ImageInfo::operator=(const ImageInfo &rhs)
{
    if (this != &rhs)
        data.operator=(rhs.data);
    return *this;
}

ImageInfo::~ImageInfo()
{

}
