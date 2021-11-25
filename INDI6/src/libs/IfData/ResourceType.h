#pragma once

class QQString;

#include <eirType/Enumeration.h>


#define RESOURCETYPE_ENUM(NV) \
    NV($null, = 0)  \
    NV(BaseData, ) \
    NV(InputMask, ) \
    NV(OutputMask, ) \
    NV(WeightMask, ) \
    NV(MeanFace, ) \
    NV(LayerSet0, ) \
    NV($size,)   \

class EIRTYPE_EXPORT ResourceType : public Enumeration
{
    DECLARE_ENUMERATION(ResourceType, RESOURCETYPE_ENUM)
public:
    bool isTypeNull() const { return $null == value(); }
    QQString toInfoString() const;
    QQString toDebugString() const;
};

extern EIRTYPE_EXPORT QDebug operator << (QDebug dbg, const ResourceType rtype);










