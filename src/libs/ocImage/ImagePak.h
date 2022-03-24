#pragma once
#include "ocImage.h"

#include <VariablePak>

#include <QImage>
class QPixmap;

#include <QQFileInfo>

#include "Image.h"
#include "FloatImage.h"
#include "FloatImagePlane.h"

class OCIMAGE_EXPORT ImagePak : public VariablePak
{
public:
    ImagePak() {;}

public:
    QQFileInfo fileInfo() const;
    QByteArray imageBytes() const;
    bool contains(const Image::Type ix) const;
    bool notContains(const Image::Type ix) const { return ! contains(ix); }
    QPixmap pixmap(const Image::Type ix) const;
    QImage qimage(const Image::Type ix) const;
    FloatImage floatImage(const Image::Type ix);
    FloatImagePlane floatImagePlane(const Image::Type ix);
    void set(const QQFileInfo &fi);
    void set(const QByteArray &imageBytes);
    void set(const Image::Type ix, const QImage &qi);
    void set(const Image::Type ix, const FloatImage &fi);
    void set(const Image::Type ix, const FloatImagePlane &fip);
    void load(const QQFileInfo &fi);
    void load(const QByteArray &imageData);
    void load(const QImage &qi);
    void load(const FloatImage &flim);
    void load(const FloatImagePlane &flane);
    void load();

public: // static
    static QImage::Format colorQFormat();
    static QImage::Format floatQFormat();
    static QImage::Format greyQFormat();

protected:
    bool generate(const Image::Type ix);
    bool generateQImage(const Image::Type ix);
    bool generateFloatImage(const Image::Type ix);
    bool generateFloatPlane(const Image::Type ix);
    bool readImageFile();
    bool loadOriginalImage();
};


