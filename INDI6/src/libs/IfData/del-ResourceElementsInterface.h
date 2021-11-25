#pragma once
/* @file: ResourceElementsInterface.h */
#include "IfData.h"

#include <eirType/QQVariant.h>

#include "del-ResourceName.h"

class ResourceElementsInterface
{
public:

protected:
    virtual QQVariant value(const ResourceName &aName);
    virtual void set(const ResourceName &aName, const QQVariant &aValue) = 0;
};
