#pragma once

#include "BaseIndi1BitMask.h"

class InputIndi1BitMask : public BaseIndi1BitMask
{
public:
    InputIndi1BitMask() {;}

public: // virtual
    virtual QQString doctypeExpected() const;
    virtual QQString expectedBitMaskTag() const override;
    virtual QQString className() const override { return "InputIndi1BitMask"; }

};

