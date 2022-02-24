#pragma once

#include <QSharedDataPointer>

class VideoFileFormatData;

class VideoFileFormat
{
public:
    VideoFileFormat();
    VideoFileFormat(const VideoFileFormat &);
    VideoFileFormat &operator=(const VideoFileFormat &);
    ~VideoFileFormat();

private:
    QSharedDataPointer<VideoFileFormatData> data;
};

