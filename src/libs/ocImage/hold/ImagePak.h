#pragma once
#include "ocImage.h"

#include <VariablePak>

#include <QImage>
class QPixmap;

#include <QQFileInfo>
#include <Size>
#include <Rational>

#include "FloatQImage.h"
#include "FloatImagePlane.h"
#include "Image.h"
#include "ImagePak.h"
class ImagePixmap;

class OCIMAGE_EXPORT ImagePak : public VariablePak
{
public:
    enum PixmapMode
    {
        $nullMode       = 0,
        Natural,
        UnsignedGreyScale,
        SignedGreyScale,
        UnsignedColorScale,
        SignedColorScale,
        UnsignedIntensity,
        SignedIntensity,
        $sizeMode
    };

    struct PixmapSpec
    {
        Image::Type     IType   = Image::$nullType;
        PixmapMode      Mode    = $nullMode;
        QColor          Color   = QColor();
        Rational        Scale   = Rational(1,1);
    };

public:
    ImagePak();
    ImagePak(const int variantReserve);
    ImagePak(const QQFileInfo &fileInfo);

public:
    QQFileInfo fileInfo() const;
    QByteArray imageBytes() const;
    bool contains(const Image::Type ix) const;
    bool notContains(const Image::Type ix) const { return ! contains(ix); }
    Size size() const;
    QImage original() const;

public:
    void set(const QQFileInfo &fi);
    void set(const QByteArray &imageBytes);
    void set(const QImage &originalImage);
    void set(const Image::Type ix, const QImage &qi);
    void set(const Image::Type ix, const FloatQImage &fi);
    void set(const Image::Type ix, const FloatImagePlane &fip);
    ImagePixmap & pixmap(const Image::Type ix);
    ImagePixmap & pixmap(const PixmapSpec args);
    QImage colorQImage(const Image::Type ix);
    QImage floatQImage(const Image::Type ix);
    FloatImagePlane floatImagePlane(const Image::Type ix);
    QImage getImage(const Image::Type ix) const;
    FloatQImage getFloat(const Image::Type ix) const;
    FloatImagePlane getPlane(const Image::Type ix) const;

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


