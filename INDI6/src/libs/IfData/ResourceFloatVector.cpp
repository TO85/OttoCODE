#include "ResourceFloatVector.h"

#include <eirType/Success.h>

ResourceFloatVector::ResourceFloatVector(const ResourceType aType,
                                         const QQDomElement &aDE,
                                         const int index)
    : AbstractResource(aType, aDE)
    , cmIndex(index)
    , mFloats(pixelCount())
{
    AbstractResource::set(aDE);
    setFloats(aDE);
}

bool ResourceFloatVector::isValid() const
{
    if (isNull()) return false;
    return true;
}

bool ResourceFloatVector::parse()
{
    TRACEFN;
    MUSTDO(it); //     MUSTDO(it);
    MUSTRTN(false);
}

QQStringList ResourceFloatVector::toInfoStrings(const int level) const
{
    QQStringList result = AbstractResource::toInfoStrings(level);
    result << QQString("Size: %1").formatMessage(cmIndex);
    MUSTDO(more); // MUSTDO(more);
    return result;

}

void ResourceFloatVector::setFloats(const QQDomElement &aDE)
{
    switch (type())
    {
    case ResourceType::BaseData:        Q_FALLTHROUGH();
    case ResourceType::InputMask:       Q_FALLTHROUGH();
    case ResourceType::OutputMask:      ERROR << "Not [Un]Signed";  break;

    case ResourceType::MeanFace:        Q_FALLTHROUGH();
    case ResourceType::WeightMask:      mSignedFloats.set(false);   break;

    case ResourceType::LayerSet0:       mSignedFloats.set(true);    break;
    }
    MUSTDO(parseFloatVector); MUSTUSE(aDE); // MUSTDO
}

bool ResourceFloatVector::isNull() const
{
    if (AbstractResource::isNull()) return true;
    if (floats().isEmpty()) return true;
    if (mSignedFloats.isNull()) return true;
    return false;
}
