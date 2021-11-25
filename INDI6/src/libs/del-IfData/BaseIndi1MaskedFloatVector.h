#pragma once
#include "IfData.h"

#include <eirType/QQString.h>

class VectorLayerData;
class Indi1ResourceManager;

class BaseIndi1MaskedFloatVector
{
public:
    typedef QVector<BaseIndi1MaskedFloatVector> Vector;

public:
    BaseIndi1MaskedFloatVector() {;}

public:

public:
    void clear();
    int id() const { return mId; }
    FloatVector data() const { return mData; }

public: // virtual
    virtual DomStatus load(const QQDomElement &de);
    virtual QQString doctypeExpected() const;
    virtual QQString className() const = 0; // pure
    virtual QQString expectedElementTag() const = 0; // pure

protected:
    DomStatus parseFloatVector(const QQDomElement &de);

public: // debug & virtual
    virtual QStringList toDebugStrings() const;
    virtual void dump() const;

private:
    int mId=-1;
    int mCount=-1;
    FloatPixel mMinData=qQNaN();
    FloatPixel mMaxData=qQNaN();
    FloatVector mData;

private: // static
    static const QQString scmElementTag;
};


