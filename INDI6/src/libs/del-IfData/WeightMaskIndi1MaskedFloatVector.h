#pragma once

#include "BaseIndi1MaskedFloatVector.h"


class WeightMaskIndi1MaskedFloatVector : public BaseIndi1MaskedFloatVector
{
public:
    WeightMaskIndi1MaskedFloatVector() {;}

public: // virtual
    virtual QQString doctypeExpected() const override;
    virtual QQString expectedElementTag() const override;
    virtual QQString className() const override { return "WeightMaskIndi1MaskedFloatVector"; }

public:
};

