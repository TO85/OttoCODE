#pragma once

#include <QSharedDataPointer>
class ImageFileFormatData;

#include <KeySeg>

class ImageFileFormat
{
public:
    ImageFileFormat();
    ImageFileFormat(const ImageFileFormat &);
    ImageFileFormat &operator=(const ImageFileFormat &);
    ~ImageFileFormat();

public:
    KeySeg key() const;

private:
    QSharedDataPointer<ImageFileFormatData> data;
};

