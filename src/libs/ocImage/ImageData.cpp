#include "ImageData.h"

class ImageDataData : public QSharedData
{
public:

};

ImageData::ImageData() : data(new ImageDataData)
{

}

ImageData::ImageData(const ImageData &rhs)
    : data{rhs.data}
{

}

ImageData &ImageData::operator=(const ImageData &rhs)
{
    if (this != &rhs)
        data.operator=(rhs.data);
    return *this;
}

ImageData::~ImageData()
{

}

Ident ImageData::ident() const
{
    return mIdent;
}
