#pragma once
/*! \file ResourceBaseData.h */
#include "IfData.h"

#include <QtCore/QBitArray>
#include <QtGui/QBitmap>
#include <QtGui/QImage>
#include <QtGui/QPixmap>

#include <eirType/BooleanString.h>
#include <eirType/QQLine.h>
#include <eirType/QQSize.h>
#include <IfGeometry/EyeLine.h>

#include "AbstractResource.h"

class IFDATA_EXPORT ResourceBitMask : public AbstractResource
{
public:
    ResourceBitMask() {;}
    ResourceBitMask(const ResourceType aType, const QQDomElement &aDE);

public: // getters
    QBitArray bits() const { return mBits; }

private: // processors

public: // debug
    QQStringList toDebugStrings() const;

private:
    QQSize mSize;
    EyeLine mEyeLine;
    BooleanString mBooleanString;
    QQBitArray mBits;

    // AbstractResource interface
public:
    bool isNull() const override final;
    virtual bool isValid() const override final;
    virtual bool parse() override final;
    virtual QQStringList toInfoStrings(const int level) const override final;

    // Getter/[Re]Setter interface
public:
    const QQSize &size() const;
    void setSize(const QQSize &newSize);
    void resetSize();
    const EyeLine &eyeLine() const;
    void setEyeLine(const EyeLine &newEyeLine);
    void resetEyeLine();
    const BooleanString &booleanString() const;
    void resetBooleanString();
    void resetBits();
};

extern IFDATA_EXPORT QDebug operator << (QDebug dbg, const ResourceBitMask rbm);
