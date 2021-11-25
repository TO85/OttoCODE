#pragma once
/* @file: ResoourceAttributes.h */
#include "IfData.h"

#include <QtCore/QMetaType>

#include <eirType/BasicName.h>
#include <eirType/QQLine.h>
#include <eirType/QQSize.h>
#include <eirType/QQStringList.h>
#include <eirXml/ElementAttributeMap.h>
class QQDomElement;

#include "ResourceType.h"

class ResourceAttributes
{
public:
    ResourceAttributes(const QQDomElement &aDE);
    explicit ResourceAttributes() = default;
    ResourceAttributes(const ResourceAttributes &other) = default;
    ~ResourceAttributes() = default;
    ResourceAttributes &operator = (const ResourceAttributes &other) = default;

public: // processors
    void parse(const QQDomElement &aDE);
    void parse(const QDomNamedNodeMap &aNodeMap);
    void clear();

public: // getters
    const ResourceType &type() const { return mType; }
    const ElementAttributeMap &map() const { return mAttributeMap; }
    const QQDomElement &element() const { return mElement; }
    const QQString &elementTag() const { return mElementTag; }

public:
    QQStringList toInfoStrings() const;

private: // [re]setters
    void resetElement() {  mElement.clear(); }
    void resetAttributeMap() { mAttributeMap.clear(); }

private:
    ResourceType mType=ResourceType::$null;
    ElementAttributeMap mAttributeMap;
    QQDomElement mElement;
    QQString mElementTag;
};

Q_DECLARE_METATYPE(ResourceAttributes);
