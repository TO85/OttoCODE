#pragma once
#include "eirData.h"

#include <eirType/MultiName.h>
#include <eirType/QQMetaType.h>
#include <eirType/QQVariant.h>

class EIRDATA_EXPORT DomVariantElement : public QDomElement
{
public:
    enum Encoding { $null = 0, String, Text, Data, Data64, Hex, $end };

public:
    DomVariantElement() = default;
    DomVariantElement(const QQVariant::KeyValue &keyValue) { set(keyValue); }
    DomVariantElement(const DomVariantElement &other) = default;
    ~DomVariantElement() = default;
    DomVariantElement &operator = (const DomVariantElement &other) = default;

    DomVariantElement it() const { return *this; }
    DomVariantElement &it() { return *this; }

    void set(const QQVariant::KeyValue &keyValue);

public:
    const static QString VariantElementTag;
    const static QString KeyTag;
    const static QString MetaTypeTag;
    const static QString MetaTypeNameTag;
    const static QString EncodingTag;

private:
    QDomElement toElement();

private:
    QQMetaType mMetaType;
    Encoding mEncoding=$null;
    QQVariant::Key mKey;
    QQVariant mVariant;
};


Q_DECLARE_METATYPE(DomVariantElement);

