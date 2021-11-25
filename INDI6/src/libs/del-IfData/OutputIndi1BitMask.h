#pragma once

#include "BaseIndi1BitMask.h"

class OutputIndi1BitMask : public BaseIndi1BitMask
{
public:
    OutputIndi1BitMask() {;}

public: // virtual
    virtual QQString doctypeExpected() const;
    virtual QQString expectedBitMaskTag() const override;
    virtual QQString className() const override { return "OutputIndi1BitMask"; }
};

