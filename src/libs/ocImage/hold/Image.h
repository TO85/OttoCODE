#pragma once
#include "ocImage.h"

#include <QObject>

#include <QList>
#include <QMetaType>

#include <KeySeg>
#include <ObjectHelper>

class OCIMAGE_EXPORT Image : public QObject
{
    Q_GADGET
public:
    enum Type
    {
        $nullType               = 0,
        PrimaryImage,

        $begQImages             = 10,
        OriginalQImage,         // User-supplied
        ColorQImage,            // Format_ARGB32_Premultiplied
        FloatColorQImage,       // Format_RGBA32FPx4_Premultiplied
        GreyQImage,             // Format_Grayscale8 (no Alpha)
        $endQImages,

        $begFloatImages         =20,
        FloatCmykImage,         // Cyan+Magenta+Yellow+Grey
        FloatHslImage,          // Opacity+Hue+Saturation+Grey (as Lightness)
        FloatYccImage,          // Opacity+Grey (as Y)+Cr+Cb
        FloatNaturalImage,      // Opacity+Grey (as Black~White)+Red+Green+Blue+Yellow
            // Natural Color System, see: https://en.wikipedia.org/wiki/Natural_Color_System
        $endFloatImages,

        $begFloatPlanes         =30,
        FloatGrayPlane,         // Color::Component::Grey
        FloatAlphaPlane,        // Color::Component::Alpha
        FloatOpacityPlane,      // Color::Component::Opacity
        FloatTranparencyPlane,  // Color::Component::Tranparency
        FloatRedPlane,          // Color::Component::Green
        FloatGrnPlane,          // Color::Component::Green
        FloatBluPlane,          // Color::Component::Blue
        FloatCynPlane,          // Color::Component::Cyan
        FloatMagPlane,          // Color::Component::Magenta
        FloatYelPlane,          // Color::Component::Yellow
        FloatBlkPlane,          // Color::Component::BlackMono
        FloatHuePlane,          // Color::Component::Hue
        FloatSatPlane,          // Color::Component::Saturation
        FloatCrPlane,           // Color::Component::Cr
        FloatCbPlane,           // Color::Component::Cb
        $endFloatPlanes,

        $maxType
    };
    Q_ENUM(Type);
    KeySeg tyoeKey(const Type value) const { return enumName(value); }
    Type typeValue(const KeySeg & key) const { return enumValue<Type>(key.toQString().toLocal8Bit().data()); }
    typedef QList<Type> TypeList;

public:
    explicit Image(QObject *parent = nullptr);

public: // const
    bool isQImageType() const { return isQImageType(mType); }
    bool isFloatImageType() const { return isFloatQImageType(mType); }
    bool isFloatPlaneType() const { return isFloatPlaneType(mType); }

public: // static
    static bool isQImageType(const Type itype);
    static bool isFloatQImageType(const Type itype);
    static bool isFloatPlaneType(const Type itype);

private:
    Type mType = $nullType;

};

