#include "ocImage.h"

#include<QImageReader>
#include<QString>

ocImage::ocImage()
{
}

QString ocImage::supportedImageFormats()
{
    return QImageReader::supportedImageFormats().join(' ');
}
