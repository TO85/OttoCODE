#pragma once
#include "ocColor.h"

#include <QObject>

#include <QColor>
#include <QList>

#include <ObjectHelper>
#include <QQString>

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
        Cyan ,
        Magenta,
        Yellow,
        Hue,
        Saturation,
        Cr,
        Cb,

        $maxComponent
    };
    Q_ENUM(Component);
    KeySeg componentKey(const Component value) const { return enumName(value); }
    Component componentValue(const KeySeg & key) const { return enumValue<Component>(key.toQString().toLocal8Bit().data()); }
    typedef QList<Component> ComponentList;

    enum Compound
    {
        $nullCompound  = 0,
        RGB,
        CMYK,
        HSL,
        YCC,
        ORGB,
        OHSL,
        OYCC,
        NCS,
        $maxCompound
    };
    Q_ENUM(Compound);
    KeySeg compoundKey(const Compound value) const { return enumName(value); }
    Compound compoundValue(const KeySeg & key) const { return enumValue<Compound>(key.toQString().toLocal8Bit().data()); }
    typedef QList<Compound> CompoundList;

    enum Model
    {
        $nullModel      = 0,
        Rgb             = QColor::Rgb,
        Hsv             = QColor::Hsv,
        Cmyk            = QColor::Cmyk,
        Hsl             = QColor::Hsl,
        ExtendedRgb     = QColor::ExtendedRgb,
        $userModel      = ExtendedRgb + 1,
        YCrCb           = $userModel + 1,
        YUV             = $userModel + 2,
        Natural         = $userModel + 3,
        $maxModel       = Natural + 1,

    };
    Q_ENUM(Model);
    KeySeg modelKey(const Model value) const { return enumName(value); }
    Model modelName(const KeySeg & key) const { return enumValue<Model>(key.toQString().toLocal8Bit().data()); }

public:
    explicit Color(QObject *parent = nullptr) : QObject(parent) {;}
    Color(const QColor &aColor, QObject *parent = nullptr);

public:
    Model model() const { return mModel; }
    QColor qColor() const { return mQColor; }
    int componentCount() const { return mColorRationalList.count(); }
    int isEmpty() const { return mColorRationalList.isEmpty(); }
    bool isValidIndex(const int ix) const;
    ColorFloatType componentF(const int ix) const;
    ColorRationalType componentR(const int ix) const;
    ColorUShortIntType componentUS(const int ix) const;
    ColorSShortIntType componentSS(const int ix) const;
    ColorULongIntType componentUL(const int ix) const;
    ColorSLongIntType componentSL(const int ix) const;
    ColorRationalType operator () (const int ix) const { return componentR(ix); }

public:
    Model & model() { return mModel; }
    ColorRationalType & component(const int ix);
    ColorRationalType & operator [] (const int ix) { return component(ix); }
    void set() {Q_ASSERT(!"TODO");}
    void set(const QColor &qcolor) {Q_ASSERT(!"TODO");}

public slots:


public: // static
    static ColorFloatType floatInvalid() { return qQNaN(); }
    static ColorRationalType rationalInvalid() { return qQNaN(); }
    static ColorUShortIntType uShortInvalid() { return UCHAR_MAX; }
    static ColorSShortIntType sShortInvalid() { return SCHAR_MAX; };
    static ColorULongIntType uLongInvalid() { return USHRT_MAX; }
    static ColorSLongIntType sLongInvalid() { return SHRT_MAX; }


signals:

private:

public: // debug
    QQString toDebugSString() const;


private:
    Model mModel;
    QColor mQColor;
    ColorRationalList mColorRationalList;

};

