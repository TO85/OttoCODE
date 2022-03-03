#pragma once

#include <QSharedDataPointer>
class ImageFileFormatData;

#include <KeySeg>
#include <MimeType>

class ImageFileFormat
{
public:
    ImageFileFormat();
    ImageFileFormat(const ImageFileFormat &);
    ImageFileFormat &operator=(const ImageFileFormat &);
    ~ImageFileFormat();

public:
    KeySeg key() const;
    KeySeg key(const KeySeg &newKey);
    MimeType mimeType() const;
    MimeType mimeType(const MimeType &newType);

private:
    QSharedDataPointer<ImageFileFormatData> data;
};

