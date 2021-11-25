#pragma once
#include "IfData.h"

#include "BaseIndi1MaskedFloatVector.h"

class MeanFaceIndi1MaskedFloatVector : public BaseIndi1MaskedFloatVector
{
public:
    MeanFaceIndi1MaskedFloatVector() {;}

public:
//    virtual void load(const QDomElement &de);

public: // virtual
    virtual QQString doctypeExpected() const override;
    virtual QQString expectedElementTag() const override;
    virtual QQString className() const override { return "MeanFaceIndi1MaskedFloatVector"; }

private: // static
    static const QQString scmElementTag;
};



