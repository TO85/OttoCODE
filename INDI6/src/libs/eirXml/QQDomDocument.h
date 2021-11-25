#pragma once
#include "eirXml.h"

#include "DomStatus.h"

class EIRXML_EXPORT QQDomDocument : public QDomDocument
{
public:
    QQDomDocument() = default;
    QQDomDocument(const QDomDocument &other) : QDomDocument(other) {;}
    QQDomDocument(const QQDomDocument &other) = default;
    ~QQDomDocument() = default;
    QQDomDocument &operator = (const QQDomDocument &other) = default;

public: // accessors
    QByteArray bytes() const { return mBytes; }
    DomStatus status() const { return mStatus; }
    QQString doctypeName() const { return doctype().name(); }
    bool notNull() const { return ! isNull(); }
    QQDomElement rootElement() const;

public: // extractors
    QQStringList rootElementNameList();

public: // commands
    DomStatus set();
    DomStatus set(const QByteArray &aBytes) { mBytes = aBytes; return set();}

private:
    QQDomDocument &it() { return *this; }
    QQDomDocument it() const { return *this; }

public: // debug
    QQStringList toDebugStrings() const;

private:
    QByteArray mBytes;
    DomStatus mStatus;
};

Q_DECLARE_METATYPE(QQDomDocument);

extern EIRXML_EXPORT QDebug operator << (QDebug dbg, const QQDomDocument &doc);

