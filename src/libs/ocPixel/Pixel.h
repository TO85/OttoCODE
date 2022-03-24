#pragma once
#include "ocPixel.h"

#include <QObject>

#include <KeySeg>
#include <ObjectHelper>


class OCPIXEL_EXPORT Pixel : public QObject
{
    Q_GADGET
public:
    enum Mask
    {
        $nullMask = 0,
        RgbMaskRed          = 0x0000FF00,
        RgbMaskGreen        = 0x00FF0000,
        RgbMaskBlue         = 0xFF000000,
        RgbMaskOpacity      = 0x000000FF,

    };
    Q_ENUM(Mask);
    KeySeg componentKey(const Mask value) const { return enumName(value); }
    Mask componentValue(const KeySeg & key) const { return enumValue<Mask>(key.toQString().toLocal8Bit().data()); }
    typedef QList<Mask> ComponentList;

public:
    explicit Pixel(QObject *parent = nullptr);

signals:

};

