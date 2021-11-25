#include "OutputIndi1BitMask.h"

#include "ResourceManager.h"

QQString OutputIndi1BitMask::doctypeExpected() const
{
    return ResourceManager::doctypeExpected();
}

QQString OutputIndi1BitMask::expectedBitMaskTag() const
{
    return ResourceManager::outputBitMaskTag();
}
