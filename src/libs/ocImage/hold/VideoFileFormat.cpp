#include "VideoFileFormat.h"

class VideoFileFormatData : public QSharedData
{
public:

};

VideoFileFormat::VideoFileFormat() : data(new VideoFileFormatData)
{

}

VideoFileFormat::VideoFileFormat(const VideoFileFormat &rhs)
    : data{rhs.data}
{

}

VideoFileFormat &VideoFileFormat::operator=(const VideoFileFormat &rhs)
{
    if (this != &rhs)
        data.operator=(rhs.data);
    return *this;
}

VideoFileFormat::~VideoFileFormat()
{

}
