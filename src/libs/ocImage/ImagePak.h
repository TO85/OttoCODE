#pragma once
#include "ocImage.h"

#include <VariablePak>

#include <QFileInfo>
#include <QImage>
#include <QMetaType>

#include "FloatImage.h"
#include "FloatImagePlane.h"

class OCIMAGE_EXPORT ImagePak : public VariablePak
{
public:
    enum Index
    {
        $nullIndex   = 0,
        OriginalQImage,         // User-specified
        ColorQImage,            // Format_ARGB32_Premultiplied
        FloatQImage,            // Format_RGBA32FPx4_Premultiplied
        GreyQImage,             // Format_Grayscale8 (no Alpha)
        FloatORgbImage,
        FloatOCmykImage,
        FloatOHslImage,
        FLoatOYccImage,
        FloatOpacityPlane,
        FloatRedPlane,
        FloatGrnPlane,
        FloatBluPlane,
        FloatCynPlane,
        FloatMagPlane,
        FloatYelPlane,
        FloatBlkPlane,
        FloatHuePlane,
        FloatSatPlane,
        FloatCrPlane,
        FloatCbPlane,

        $maxIndex
    };

public:
    QFileInfo fileInfo() const;
    bool contains(const Index ix) const;
    QImage qimage(const Index ix);
    FloatImage floatImage(const Index ix);
    FloatImagePlane floatImagePlane(const Index ix);
    void set(const QFileInfo &fi);
    void set(const Index ix, const QImage &qi);
    void set(const Index ix, const FloatImage &fi);
    void set(const Index ix, const FloatImagePlane &fip);
    void load();
    void load(const QFileInfo &fi);
    void load(const QByteArray &imageData);
    void load(const QImage &qi);
    void load(const FloatImage &fi);
    void load(const FloatImagePlane &fip);

public:
    ImagePak() = default;
    ~ImagePak() = default;
    ImagePak(const ImagePak &other) = default;
    ImagePak &operator=(const ImagePak & rhs) = default;
};

Q_DECLARE_METATYPE(ImagePak);

