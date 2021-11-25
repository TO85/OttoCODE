#include "DomVariantElement.h"

#include <eirXfr/Debug.h>

const QString DomVariantElement::VariantElementTag = QString("VariantElement");
const QString DomVariantElement::KeyTag = QString("Key");
const QString DomVariantElement::EncodingTag = QString("Encoding");
const QString DomVariantElement::MetaTypeTag = QString("Type");
const QString DomVariantElement::MetaTypeNameTag = QString("TypeName");

void DomVariantElement::set(const QQVariant::KeyValue &keyValue)
{
    QQVariant vari = keyValue.second;
    mKey = keyValue.first;
    mMetaType.set(vari.type());
}

QDomElement DomVariantElement::toElement()
{
    TRACEFN;
    QDomElement result;
    result.setTagName(VariantElementTag);
    result.setAttribute(KeyTag, mKey());
    result.setAttribute(MetaTypeTag, mVariant.type());
    result.setAttribute(MetaTypeNameTag, mVariant.typeName());
    result.setAttribute(EncodingTag, int(mEncoding));
    MUSTDO(encoding);
    return result;
}
