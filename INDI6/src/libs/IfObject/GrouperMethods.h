#pragma once
#include "IfObject.h"

#include <eirType/Enumeration.h>
#define GROUPMETHOD_ENUM(NV) \
    NV($null, = 0)  \
    NV($beginCombine, = 10) \
    NV(NoCombine, ) \
    NV(CombineContains, ) \
    NV(CombineOverlap, ) \
    NV($endCombine, ) \
    NV($beginGroup, = 20) \
    NV(NoGroup, ) \
    NV(GroupUnion,)   \
    NV(GroupAverage,)   \
    NV($endGroup, ) \
    NV($max, )   \

class IFOBJECT_EXPORT GrouperMethods : public Enumeration
{
    DECLARE_ENUMERATION(GrouperMethods, GROUPMETHOD_ENUM)
public:
    bool isCombine() const;
    bool isGroup() const;
};

