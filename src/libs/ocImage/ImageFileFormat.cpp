#include "ImageFileFormat.h"

class ImageFileFormatData : public QSharedData
{
public:
    KeySeg dmKey;


};

ImageFileFormat::ImageFileFormat() : data(new ImageFileFormatData)
{

}

ImageFileFormat::ImageFileFormat(const ImageFileFormat &rhs)
    : data{rhs.data}
{

}

ImageFileFormat &ImageFileFormat::operator=(const ImageFileFormat &rhs)
{
    if (this != &rhs)
        data.operator=(rhs.data);
    return *this;
}

ImageFileFormat::~ImageFileFormat()
{

}

KeySeg ImageFileFormat::key() const
{
    Q_ASSERT(data);
    return data->dmKey;
}
