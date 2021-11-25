#include "MeanFaceIndi1MaskedFloatVector.h"

#include "ResourceManager.h"

QQString MeanFaceIndi1MaskedFloatVector::doctypeExpected() const
{
    return ResourceManager::doctypeExpected();
}

QQString MeanFaceIndi1MaskedFloatVector::expectedElementTag() const
{
    return ResourceManager::meanFaceTag();
}
