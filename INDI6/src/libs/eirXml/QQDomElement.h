#pragma once
#include "eirXml.h"

#include <eirType/QQStringList.h>

class EIRXML_EXPORT QQDomElement : public QDomElement
{
public:
    typedef QList<QQDomElement> List;

public:
    explicit QQDomElement() = default;
    QQDomElement(const QDomElement &other) : QDomElement(other) {;}
    QQDomElement(const QQDomElement &other) = default;
    ~QQDomElement() = default;
    QQDomElement &operator = (const QQDomElement &other) = default;

public:
    bool notNull() const { return ! isNull(); }
    QQString tagName() const { return QDomElement::tagName(); }
    int attributeCount() const { return attributes().count(); }
    int childNodeCount() const { return childNodes().count(); }
    QQStringList attributeNameValueList() const;
    QQStringList childElementNameList() const;
    QQStringList toInfoStrings(const int level=2) const;
    QQDomElement childElement(const QQString &elementTag) const;

public:
    QQStringList toDebugStrings(const bool nest=false) const;
    void dump(const bool nest=false) const;

private:
    QQStringList toDebugStrings(const int nestLevel, const bool nest) const;
};

Q_DECLARE_METATYPE(QQDomElement);

extern EIRXML_EXPORT QDebug operator << (QDebug dbg, const QQDomElement &de);

