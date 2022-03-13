#pragma once
#include "ocColor.h"

#include <QObject>

#include <ObjectHelper>

class OCCOLOR_EXPORT Color : public QObject
{
    Q_GADGET
public:
    enum Component
    {
        $nullComponent  = 0,
        Grey,
        Alpha,
        Opacity,
        Tranparency,
        Red,
        Green,
        Blue,
        Hue,
        Saturation,
        Cr,
        Cb,

        $maxComponent
    };
    Q_ENUM(Component);
    KeySeg componentKey(const Component value) const { return enumName(value); }
    Component componentValue(const KeySeg & key) const { return enumValue<Component>(key.toQString().toLocal8Bit().data()); }

public:
    explicit Color(QObject *parent = nullptr) { Q_UNUSED(parent); }

signals:

};

