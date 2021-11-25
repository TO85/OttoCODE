#include "InputIndi1BitMask.h"

#include "ResourceManager.h"

// virtual
QQString InputIndi1BitMask::doctypeExpected() const
{
    return ResourceManager::doctypeExpected();
}

// virtual
QQString InputIndi1BitMask::expectedBitMaskTag() const
{
    return ResourceManager::inputBitMaskTag();
}
