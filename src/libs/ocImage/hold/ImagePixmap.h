#pragma once

#include <QPixmap>

#include "Image.h"
#include "ImagePak.h"

class ImagePixmap : public QPixmap
{
public:

public:
    ImagePixmap();
    ImagePixmap(const Image::Type itype);
    ImagePixmap(const ImagePak::PixmapSpec spec);
    ImagePixmap(const QImage qimage, const ImagePak::PixmapSpec spec);
    ImagePixmap(const FloatQImage fqimage, const ImagePak::PixmapSpec spec);
    ImagePixmap(const FloatImagePlane fplane, const ImagePak::PixmapSpec spec);

public:

public:
    void set(const Image::Type itype);
    void set(const ImagePak::PixmapSpec spec);
    void set(const QImage qimage, const ImagePak::PixmapSpec spec);
    void set(const FloatQImage fqimage, const ImagePak::PixmapSpec spec);
    void set(const FloatImagePlane fplane, const ImagePak::PixmapSpec spec);

private:
    ImagePak::PixmapSpec mSpec;
};

