#pragma once
#include "IfData.h"

#include "BaseIndi1MaskedFloatVector.h"
class FaceLayersIndi1MaskedFloatVectorSet;

class IFDATA_EXPORT LayerIndi1MaskedFloatVector : public BaseIndi1MaskedFloatVector
{
public:
    LayerIndi1MaskedFloatVector() {;}

public:


private:

public: // virtual
    virtual QQString className() const override { return "LayerIndi1MaskedFloatVector"; }
    virtual QQString doctypeExpected() const override;
    virtual QQString expectedElementTag() const override;

private:

};

