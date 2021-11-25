#include "del-ResourceName.h"

#include "ResourceType.h"

ResourceType ResourceName::type() const
{
    ResourceType result;
    result.set(typeName()());
    return result;
}
