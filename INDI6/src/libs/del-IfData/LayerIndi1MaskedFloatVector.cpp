#include "LayerIndi1MaskedFloatVector.h"

#include "ResourceManager.h"

// virtual
QQString LayerIndi1MaskedFloatVector::doctypeExpected() const
{
    return ResourceManager::doctypeExpected();
}

QQString LayerIndi1MaskedFloatVector::expectedElementTag() const
{
    return ResourceManager::faceLayersTag();
}
