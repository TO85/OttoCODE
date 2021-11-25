#pragma once
#include "eirXml.h"

#include <eirType/MultiName.h>
#include <eirType/QQByteArray.h>
#include <eirType/QQFileInfo.h>
#include <eirType/QQVector.h>
#include <eirType/Success.h>
#include <eirXml/DomStatus.h>
#include <eirXml/QQDomDocument.h>
#include <eirXml/QQDomElement.h>

class EIRXML_EXPORT DomFile : public QObject
{
    Q_OBJECT
public:
    typedef QQVector<DomFile *> Vector;

public:
    explicit DomFile(QObject *parent = nullptr);
    DomFile(const MultiName &aKey, QObject *parent = nullptr);
    DomFile(const QQFileInfo &aFileInfo, QObject *parent = nullptr);
    void setKey(const MultiName &aKey) { mKey = aKey; }
    void setFileInfo(const QQFileInfo &aFileInfo) { mKey = aFileInfo.baseName(), mFileInfo = aFileInfo; }

public: // getters
    MultiName key() const { return mKey; }
    DomStatus status() const { return mStatus; }
    QQFileInfo fileInfo() const { return mFileInfo; }
    QQByteArray bytes() const { return mBytes; }
    QQDomDocument document() const { return mDocument; }
    QQDomElement rootElement() const { return mDocument.documentElement(); }
    int childElementCount() const { return mChildElementList.count(); }
    QQDomElement childElement(const int ix);
    QQStringList childElementNames() const { return mChildElementNameList; }

public: // setters
    void setBytes(const QQByteArray &aBytes) { mBytes = aBytes; }
    void setDocument(const QQDomDocument &aDoc) { mDocument = aDoc; }


public: // commands
    void clear();
    DomStatus loadDocument(const QQFileInfo &aFileInfo);
    virtual DomStatus loadDocument();
    virtual int loadChildElements();

signals:

public:
    QQString toDebugString() const;
    QQStringList toInfoStrings(const int level) const;
    QQStringList toDebugStrings() const;
    void dump() const { for ( auto s : toDebugStrings() ) DUMP << s; }

private:
    MultiName mKey;
    DomStatus mStatus;
    QQFileInfo mFileInfo;
    QQByteArray mBytes;
    QQDomDocument mDocument;
    QQStringList mChildElementNameList;
    QQDomElement::List mChildElementList;
};

extern EIRXML_EXPORT QDebug operator << (QDebug dbg, const DomFile &df);

