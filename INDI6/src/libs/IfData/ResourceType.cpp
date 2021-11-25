#include "ResourceType.h"

#include <eirType/QQString.h>

DEFINE_ENUMERATION(ResourceType, ENUMCLASS_ENUM);

QQString ResourceType::toInfoString() const
{
    return QQString("%1 (%2)").formatMessage(name(), value());
}

QQString ResourceType::toDebugString() const
{
    return QQString("{ResourceType:>%2=[%1]<}").formatMessage(name(), value());
}

QDebug operator << (QDebug dbg, const ResourceType rtype)
{
    dbg << rtype.toDebugString();
    return dbg;
}


