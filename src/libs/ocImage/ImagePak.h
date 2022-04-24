#pragma once
#include "ocImage.h"

#include <VariablePak>

#include <QImage>
class QPixmap;

#include <QQFileInfo>
#include <QQSize>
#include <Rational>

#include "Image.h"
#include "FloatQImage.h"
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
    QQSize size() const;
    QPixmap pixmap(const Image::Type ix, const Rational scale=1);
    QImage original() const;
    QImage colorQImage(const Image::Type ix);
    QImage floatQImage(const Image::Type ix);
    FloatImagePlane floatImagePlane(const Image::Type ix);
    QImage getImage(const Image::Type ix) const;
    FloatQImage getFloat(const Image::Type ix) const;
    FloatImagePlane getPlane(const Image::Type ix) const;
    void set(const QQFileInfo &fi);
    void set(const QByteArray &imageBytes);
    void set(const QImage &originalImage);
    void set(const Image::Type ix, const QImage &qi);
    void set(const Image::Type ix, const FloatQImage &fi);
    void set(const Image::Type ix, const FloatImagePlane &fip);

public: // static
    static QImage::Format colorQFormat();
    static QImage::Format floatQFormat();
    static QImage::Format greyQFormat();

protected:
    void generate(const Image::Type ix);
    void generateQImage(const Image::Type ix);
    void generateQFloatImage(const Image::Type ix);
    void generateFloatPlane(const Image::Type ix);
    void generateOriginal();
    void generateColorQI();
};


