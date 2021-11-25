#pragma once
/*! \file ResourceFloatVector.h */
#include "IfData.h"

#include "AbstractResource.h"
class ResourceBitMask;

class ResourceFloatVector : public AbstractResource
{
public:
    typedef qreal Float;
    typedef QQVector<Float> FloatVector;

public:
    ResourceFloatVector(const ResourceType aType, const QQDomElement &aDE, const int index=0);

public: // accessors
    FloatVector floats() const { return mFloats; }


private: // processors
    void setFloats(const QQDomElement &aDE);

private:
    const int cmIndex;
    Boolean mSignedFloats;
    FloatVector mFloats;

    // AbstractResource interface
public:
    virtual bool isNull() const override final;
    virtual bool isValid() const override final;
    virtual bool parse() override final;
    virtual QQStringList toInfoStrings(const int level) const override final;
};

