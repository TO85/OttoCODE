/*! \file: AbstractResource.h */
#pragma once
#include "IfData.h"

#include <QtCore/QMetaType>

#include <eirType/QQLine.h>
#include <eirType/QQSize.h>
#include <eirType/QQVariant.h>

#include "ResourceAttributes.h"

class IFDATA_EXPORT AbstractResource
{
public:
    AbstractResource();
    AbstractResource(const ResourceType &aType);
    AbstractResource(const ResourceType &aType, const QQDomElement &aDE);

public:
    const ResourceType &type() const { return mType; }
    QQDomElement element() const { return mElement; }
    QQString text() const { return element().text(); }
    bool isEmpty() const { return element().text().isEmpty(); }
    bool notEmpty() const { return ! isEmpty(); }
    bool contains(const BasicName &aKey) const;
    QQString attribute(const BasicName &aKey) const;
    QQVariant attribute(const BasicName &aKey, const QQVariant::Type &variType) const;
    int attributeInt(const BasicName &aKey) const;
    int pixelCount() const;
    QQSize normalSize() const;
    QQLine normalEyeLine() const;

protected:
    virtual void set(const QQDomElement &aDE);
    virtual bool isNull() const;
    virtual bool notValud() const { return ! isValid(); }
    virtual bool isValid() const = 0;
    virtual bool parse() = 0;
    virtual QQStringList toInfoStrings(const int level=1) const;

public: // debug
    QQStringList toDebugStrings() const;

protected:
    ResourceType mType=ResourceType::$null;
    ResourceAttributes mAttributes;
    QQDomElement mElement;
};



