#pragma once
#include "IfObject.h"

#include <eirType/MultiName.h>
#include <eirType/SCRect.h>

class IFOBJECT_EXPORT ObjectRegion
{
public:
    ObjectRegion() {;}
    ObjectRegion(const MultiName &name, const SCRect rect);
    ObjectRegion(const SCRect rect);
    MultiName name() const { return cmRegionName; }
    SCRect rect() const { return cmRegionRect; }

private:
    const MultiName cmRegionName;
    const SCRect cmRegionRect;
};

