#pragma once
#include "IfData.h"

#include <eirGui/QQImage.h>
#include <eirType/QQBitArray.h>
#include <eirType/QQSize.h>
#include <IfGeometry/EyeLine.h>

class IFDATA_EXPORT BaseIndi1BitMask
{
public:
    BaseIndi1BitMask() {;}

public:
    QQBitArray bits() const { return mBits; }
    QQSize size() const { return mSize; }
    bool isNull() const;

public:
    QQImage maskNormalImage(const QQImage &aImage, const QColor maskColor=Qt::gray) const;

public: // virtual
    virtual DomStatus load(const QQDomElement &de);
    void clear();

private:
    QQImage maskContinous32bit(const QQImage &aImage, const QColor maskColor=Qt::gray) const;
    QQImage maskContinous8bit(const QQImage &aImage, const QColor maskColor=Qt::gray) const;
    QQImage maskByRow32bit(const QQImage &aImage, const QColor maskColor=Qt::gray) const;
    QQImage maskByRow8bit(const QQImage &aImage, const QColor maskColor=Qt::gray) const;

public: // virtual
    virtual QQString expectedBitMaskTag() const = 0; // pure
    QQString doctypeExpected() const;
    virtual QQString className() const = 0; // pure

private:
    QQBitArray mBits;
    int mActivePixels=0;
    QQSize mSize;
    EyeLine mEyeLine;

private: // static
    static const QQString scmElementTag;
};



