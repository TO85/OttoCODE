#include "ResourceAttributes.h"

#include <eirXfr/Debug.h>

ResourceAttributes::ResourceAttributes(const QQDomElement &aDE)
{
    TRACEQFI << aDE;
    parse(aDE);
}

void ResourceAttributes::parse(const QQDomElement &aDE)
{
    TRACEQFI << aDE;
    mElement = aDE;
    mElementTag = mElement.tagName();
    QDomNamedNodeMap tAttributeNodes = mElement.attributes();
    parse(tAttributeNodes);
}

void ResourceAttributes::parse(const QDomNamedNodeMap &aNodeMap)
{
    TRACEQFI << aNodeMap.length();
    mAttributeMap.set(aNodeMap);
}

void ResourceAttributes::clear()
{
    mType.set(ResourceType::$null);
    resetElement();
    resetAttributeMap();
    mElementTag.clear();
}

QQStringList ResourceAttributes::toInfoStrings() const
{
    QQStringList results;
    results << QQString("Type: %1").formatMessage(type().toInfoString());
    results << QQString("Tag:  %1").formatMessage(elementTag());
    results << map().toInfoStrings();
    results << element().toInfoStrings();
    return results;
}
