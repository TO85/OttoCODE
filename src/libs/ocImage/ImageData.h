#pragma once

#include <QSharedDataPointer>
class ImageDataData;

#include <Ident>

class ImageData
{
public:
    ImageData();
    ImageData(const ImageData &);
    ImageData &operator=(const ImageData &);
    ~ImageData();

public:
    Ident ident() const;

private:
    Ident mIdent;
    QSharedDataPointer<ImageDataData> data;
};

