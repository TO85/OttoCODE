#include "FaceLayersIndi1MaskedFloatVectorSet.h"


void FaceLayersIndi1MaskedFloatVectorSet::set(const LayerIndi1MaskedFloatVector &aLayer)
{
    const int tId = aLayer.id();
    AEXPECT(isValidIndex(tId));
    if (isValidIndex(tId))
        mLayerVector[tId] = aLayer;
}

QQString FaceLayersIndi1MaskedFloatVectorSet::doctypeExpected() const
{
    return ResourceManager::doctypeExpected();
}
