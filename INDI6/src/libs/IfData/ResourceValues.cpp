#include "ResourceValues.h"

#include <eirXfr/Debug.h>

ResourceValues::ResourceValues()
{
    TRACEFN;
}

QQStringList ResourceValues::info() const
{
    QQStringList result;
    MUSTDO(it); // MUSTDO(it)
    return result;
}

void ResourceValues::setResourceBaseData(const ResourceBaseData &aBaseData)
{
    //mResourceBaseData = aBaseData; // TODO Why Not?
    mResourceBaseData.setName(aBaseData.name());
    mResourceBaseData.setDescription(aBaseData.description());
    mResourceBaseData.setNormalSize(aBaseData.normalSize());
    mResourceBaseData.setNormalEyeLine(aBaseData.normalEyeLine());
}

void ResourceValues::setResourceBitMask(const ResourceType aType, const ResourceBitMask &aBitMask)
{
    switch (aType)
    {
    case ResourceType::InputMask:   mInputBitMask = aBitMask;   break;
    case ResourceType::OutputMask:  mOutputBitMask = aBitMask;  break;
    default:    ERROR << "Unexpected Resource Type:" << aType;  break;
    }
}
