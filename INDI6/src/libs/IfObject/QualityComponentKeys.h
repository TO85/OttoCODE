#pragma once
#include "IfObject.h"

#include <eirType/Enumeration.h>

#define QUALITYCOMPONENTKEY_ENUM(NV) \
    NV($null, = 0)  \
    NV($begFrontal, = 10)  \
    NV(FrontalScore,)   \
    NV(FrontalAreaFraction,)   \
    NV(FrontalWidthRatio,)   \
    NV($endFrontal,) \
    NV($begEye, = 20) \
    NV(EyeScore,)   \
    NV(ExpectedEyeLine,)   \
    NV(EyeROI,)   \
    NV(LeftEyeROI,)   \
    NV(RightEyeROI,)   \
    NV(EyeLineRatio,)   \
    NV(EyeFaceRatio,)   \
    NV($endEye,) \
    NV($max,)

class IFOBJECT_EXPORT QualityComponentKeys : public Enumeration
{
    DECLARE_ENUMERATION(QualityComponentKeys, QUALITYCOMPONENTKEY_ENUM)
public:
};

