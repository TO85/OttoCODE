#include "WeightMaskIndi1MaskedFloatVector.h"

#include "ResourceManager.h"

QQString WeightMaskIndi1MaskedFloatVector::doctypeExpected() const
{
    return ResourceManager::doctypeExpected();
}


QQString WeightMaskIndi1MaskedFloatVector::expectedElementTag() const
{
    return ResourceManager::weightMaskTag();
}
