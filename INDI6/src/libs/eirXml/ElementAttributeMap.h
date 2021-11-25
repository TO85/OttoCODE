#pragma once
#include "eirXml.h"

#include <QtDebug>
#include <eirType/BasicName.h>
#include <eirType/BasicNameMap.h>
#include <eirType/QQVariant.h>

#include "QQDomElement.h"
#include "DomStatus.h"

class EIRXML_EXPORT ElementAttributeMap
{
public:
    ElementAttributeMap(const QQDomElement &de) : mElement(de) { set(); }
    explicit ElementAttributeMap() = default;
    ElementAttributeMap(const ElementAttributeMap &other) = default;
    ~ElementAttributeMap() = default;
    ElementAttributeMap &operator = (const ElementAttributeMap &other) = default;

public: // accessors
    bool contains(const BasicName &aName) const { return mNameValueMap.contains(aName); }
    QQString value(const BasicName &aName) const { return mNameValueMap.value(aName); }
    QQString value(const BasicName &aName, const QQString &defaultValue) const;
    QQString tryExists(DomStatus * pStatus, const BasicName &aName,
                        const QQString &defaultValue=QQString()) const;
    QQStringList toInfoStrings() const;


public:
    void clear() { mNameValueMap.clear(); }
    DomStatus set();
    DomStatus set(const QDomNamedNodeMap &dnnm) { mNodeMap = dnnm; return set(); }
    DomStatus set(const QQDomElement &de) { mElement = de; return set(); }

public: // debug
    QStringList toDebugStrings() const;

    const DomStatus &status() const;

private:
    QQDomElement mElement;
    QDomNamedNodeMap mNodeMap;
    DomStatus mStatus;
    BasicName::StringMap mNameValueMap;
};

Q_DECLARE_METATYPE(ElementAttributeMap);

extern EIRXML_EXPORT QDebug operator << (QDebug dbg, const ElementAttributeMap &eam);
