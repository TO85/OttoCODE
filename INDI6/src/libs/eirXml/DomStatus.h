#pragma once
#include "eirXml.h"

#include <eirType/QQFileInfo.h>
#include <eirType/QQByteArray.h>
#include <eirType/QQtMsgType.h>
#include <eirType/QQString.h>
#include <eirType/QQStringList.h>

class EIRXML_EXPORT DomStatus
{
public:
    class EIRXML_EXPORT Item
    {
    public:
        typedef QList<Item> List;

    public:
        explicit Item() = default;
        Item(const QQtMsgType aQMT) : mQMT(aQMT) {;}
        Item(const QQtMsgType aQMT, const QQString aMessage) : mQMT(aQMT), mMessage(aMessage) {;}
        Item(const Item &other) = default;
        ~Item() = default;
        Item &operator = (const Item &other) = default;

    public: // access
        QQtMsgType type() const { return mQMT; }
        QQString message() const { return mMessage; }
        bool isNull() const { return mQMT.isNull() && mMessage.isEmpty(); }
        bool notNull() const { return ! isNull(); }
        QQString toString() const;

    public: // setters
        Item setType(const QQtMsgType aQMT) { mQMT = aQMT; return it(); }
        Item setMessage(const QQtMsgType aQMT, const QQString aMessage) { mQMT = aQMT, mMessage = aMessage; return it(); }
        Item setTypeFormat(const QQtMsgType qQMT, const QQString aFormat, const QVariant v1,
                 const QVariant v2=QVariant(), const QVariant v3=QVariant(), const QVariant v4=QVariant());
        Item setTypeFormat(const QQtMsgType qQMT, const QQString aFormat, const QVariantList qvl);
        Item setMessage(const QQString aMessage) { mMessage = aMessage; return it(); }
        Item setFormat(const QQString aFormat, const QVariant v1, const QVariant v2=QVariant(), const QVariant v3=QVariant(), const QVariant v4=QVariant());
        Item setFormat(const QQString aFormat, const QVariantList qvl);

    private:
        Item &it() { return *this;}
        Item it() const { return *this;}

    private:
        QQtMsgType mQMT;
        QQString mMessage;
        QQString mFormat;
        QVariantList mVariants;
    };

public:
    explicit DomStatus() = default;
    DomStatus(const DomStatus::Item firstItem) { append(firstItem); }
    DomStatus(const QQtMsgType aType) { append(Item(aType)); }
    DomStatus(const DomStatus &other) = default;
    ~DomStatus() = default;
    DomStatus &operator = (const DomStatus &other) = default;

public:
    bool isEmpty() const { return mItemList.isEmpty(); }
    bool notEmpty() const { return ! isEmpty(); }
    QQtMsgType type() const { return mMaxMsgType; }
    bool notError() const { return type().notError() && notEmpty(); }
    bool isError() const { return ! notError(); }
    int itemCount() const { return mItemList.count(); }
    Item::List list() const { return mItemList; }
    QQStringList itemStrings() const;
    QQFileInfo fileInfo() const { return mFileInfo; }
    QQByteArray bytes() const { return mBytes; }
    operator bool () const { return notError(); }

public:
    void clear();
    Item expect(const QQString aMessage, const bool test, const QtMsgType trueType, const QtMsgType falseType);
    Item setDocument(QQDomDocument * pDoc, const QQString &description, const QQByteArray &aBytes);
    Item info(const QQString aMessage) { return item(QtInfoMsg, aMessage); }
    Item info(const QQString aFormat, const QVariant v1, const QVariant v2=QVariant(), const QVariant v3=QVariant(), const QVariant v4=QVariant());
    Item info(const QQString aFormat, const QVariantList qvl) { return item(QtInfoMsg, aFormat, qvl); }
    Item trace(const QQString aMessage) { return item(QtDebugMsg, aMessage); }
    Item trace(const QQString aFormat, const QVariant v1, const QVariant v2=QVariant(), const QVariant v3=QVariant(), const QVariant v4=QVariant());
    Item trace(const QQString aFormat, const QVariantList qvl) { return item(QtDebugMsg, aFormat, qvl); }
    Item warn(const QQString aMessage) { return item(QtWarningMsg, aMessage); }
    Item warn(const QQString aFormat, const QVariant v1, const QVariant v2=QVariant(), const QVariant v3=QVariant(), const QVariant v4=QVariant());
    Item warn(const QQString aFormat, const QVariantList qvl) { return item(QtWarningMsg, aFormat, qvl); }
    Item error(const QQString aMessage) { return item(QtCriticalMsg, aMessage); }
    Item error(const QQString aFormat, const QVariant v1, const QVariant v2=QVariant(), const QVariant v3=QVariant(), const QVariant v4=QVariant());
    Item error(const QQString aFormat, const QVariantList qvl) { return item(QtCriticalMsg, aFormat, qvl); }
    Item fatal(const QQString aMessage) { return item(QtFatalMsg, aMessage); }
    Item fatal(const QQString aFormat, const QVariant v1, const QVariant v2=QVariant(), const QVariant v3=QVariant(), const QVariant v4=QVariant());
    Item fatal(const QQString aFormat, const QVariantList qvl) { return item(QtFatalMsg, aFormat, qvl); }
    QQtMsgType append(const Item &aItem);
    QQtMsgType append(const DomStatus &more);
    void set(const QByteArray &aBytes) { mBytes = aBytes; }
    void set(const QQFileInfo &aFileInfo) { mFileInfo = aFileInfo; }
    void set(const QByteArray &aBytes, const QQFileInfo &aFileInfo) { mFileInfo = aFileInfo, mBytes = aBytes; }

public: // debug
    QQStringList toDebugStrings() const;
    void dump() const { for (auto s : toDebugStrings()) DUMP << s; }

private:
    Item item(const QQtMsgType aQMT, const QQString aMessage);
    Item item(const QQtMsgType aQMT, const QQString aFormat, const QVariant v1, const QVariant v2=QVariant(), const QVariant v3=QVariant(), const QVariant v4=QVariant());
    Item item(const QQtMsgType aQMT, const QQString aFormat, const QVariantList qvl);
    DomStatus it() const { return *this; }
    DomStatus &it() { return *this; }

private:
    QQtMsgType mMaxMsgType;
    Item::List mItemList;
    QQFileInfo mFileInfo;
    QQByteArray mBytes;

};

Q_DECLARE_METATYPE(DomStatus);
Q_DECLARE_METATYPE(DomStatus::Item);

extern EIRXML_EXPORT QDebug operator << (QDebug dbg, const DomStatus::Item &dsi);
extern EIRXML_EXPORT QDebug operator << (QDebug dbg, const DomStatus &ds);

