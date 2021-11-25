#include "DomStatus.h"

#include <eirXfr/Debug.h>
#include <eirType/QQVariant.h>
#include <eirXml/QQDomDocument.h>

QQStringList DomStatus::itemStrings() const
{
    QQStringList result;
    result << type().toDebugString();
    result << QQString::number(itemCount()) + " Item" + ((1 == itemCount()) ? "" : "s");
    for (Item item : mItemList)
        result << item.toString();
    if (fileInfo().notNull())
        result << "FINFO: " + fileInfo().dir().absolutePath() + " / " + fileInfo().filePath();
    if (bytes().notEmpty())
        result << "BYTES: " + bytes().toString();
    return result;
}

void DomStatus::clear()
{
    mMaxMsgType.clear(), mItemList.clear(), mBytes.clear(), mFileInfo = QQFileInfo();
}

DomStatus::Item DomStatus::expect(const QQString aMessage, const bool test, const QtMsgType trueType, const QtMsgType falseType)
{
    DomStatus::Item item(test ? trueType : falseType);
    item.setFormat(aMessage, test);
    append(item);
    return item;
}

DomStatus::Item DomStatus::setDocument(QQDomDocument *pDoc, const QQString &description, const QQByteArray &aBytes)
{
    DomStatus::Item item;
    int line, column;
    QQString errorString;

    bool ok = pDoc->setContent(aBytes, &errorString, &line, &column);
    QVariantList qvl = QVariantList() << description << aBytes << line << column << errorString;
    if (ok)
        item.setTypeFormat(QtInfoMsg, "DomDocument %1 loaded, doctype=%2", description, pDoc->doctypeName());
    else
        item.setTypeFormat(QtCriticalMsg, "Error loading %1 from %2 at %3,%4: %5", qvl);
    return item;
}

DomStatus::Item DomStatus::info(const QQString aFormat, const QVariant v1, const QVariant v2, const QVariant v3, const QVariant v4)
{
    QVariantList qvl = QVariantList() << QVariant(QtInfoMsg) << v1 << v2 << v3 << v4;
    return info(aFormat, qvl);;
}

DomStatus::Item DomStatus::trace(const QQString aFormat, const QVariant v1, const QVariant v2, const QVariant v3, const QVariant v4)
{
    QVariantList qvl = QVariantList() << QVariant(QtDebugMsg) << v1 << v2 << v3 << v4;
    return trace(aFormat, qvl);;
}

DomStatus::Item DomStatus::warn(const QQString aFormat, const QVariant v1, const QVariant v2, const QVariant v3, const QVariant v4)
{
    QVariantList qvl = QVariantList() << QVariant(QtWarningMsg) << v1 << v2 << v3 << v4;
    return warn(aFormat, qvl);;
}

DomStatus::Item DomStatus::error(const QQString aFormat, const QVariant v1, const QVariant v2, const QVariant v3, const QVariant v4)
{
    QVariantList qvl = QVariantList() << QVariant(QtCriticalMsg) << v1 << v2 << v3 << v4;
    return error(aFormat, qvl);;
}

DomStatus::Item DomStatus::fatal(const QQString aFormat, const QVariant v1, const QVariant v2, const QVariant v3, const QVariant v4)
{
    QVariantList qvl = QVariantList() << QVariant(QtFatalMsg) << v1 << v2 << v3 << v4;
    return fatal(aFormat, qvl);;
}

QQtMsgType DomStatus::append(const DomStatus::Item &aItem)
{
//    TRACEQFI << aItem << aItem.type() << mMaxMsgType << mItemList.count();
    mItemList.append(aItem);
    if (aItem.type() > mMaxMsgType)
    {
        mMaxMsgType = aItem.type();
        DUMPVAL(mMaxMsgType);
    }
    return mMaxMsgType;
}

QQtMsgType DomStatus::append(const DomStatus &more)
{
//    TRACEQFI << more;
    for (Item item : more.list())
        append(item);
    return mMaxMsgType;
}

QQStringList DomStatus::toDebugStrings() const
{
    QQStringList result;
    if (isEmpty())
    {
        result << QQString("{DomStatus: >empty<}");
    }
    else
    {
        result << QQString("{DomStatus:> Max=%1 nItems=%2")
                  .arg(mMaxMsgType.name()).arg(mItemList.count());
        result << itemStrings();
        result << mFileInfo.toDebugStrings();
        result << mBytes.toDebugString();
        result << "<DomStatus}";
    }
    return result;
}

DomStatus::Item DomStatus::item(const QQtMsgType aQMT, const QQString aMessage)
{
    DomStatus::Item item(aQMT);
    item.setMessage(aMessage);
    append(item);
    return item;
}

DomStatus::Item DomStatus::item(const QQtMsgType aQMT, const QQString aFormat, const QVariant v1, const QVariant v2, const QVariant v3, const QVariant v4)
{
    QVariantList qvl = QVariantList() << QVariant(aQMT.value()) << v1 << v2 << v3 << v4;
    return item(aQMT, aFormat, qvl);
}

DomStatus::Item DomStatus::item(const QQtMsgType aQMT, const QQString aFormat, QVariantList qvl)
{
    DomStatus::Item item(aQMT);
    item.setFormat(aFormat, qvl);
    append(item);
    return item;
}

/* ===================== Item sub-class ======================== */

QQString DomStatus::Item::toString() const
{
    return QQString::formatMessage4Var("%1>%2<", type().name(), mMessage);
}

DomStatus::Item DomStatus::Item::setTypeFormat(QQtMsgType aQMT, const QQString aFormat,
        const QVariant v1, const QVariant v2, const QVariant v3, const QVariant v4)
{
    QVariantList qvl = QVariantList() << QVariant(aQMT.value()) << v1 << v2 << v3 << v4;
    return setTypeFormat(aQMT, aFormat, qvl);
}

DomStatus::Item DomStatus::Item::setTypeFormat(const QQtMsgType aQMT, const QQString aFormat, QVariantList qvl)
{
    TRACEQFI << aQMT << aFormat << qvl;
    DomStatus::Item result;
    result.setType(aQMT);
    qvl.prepend(QVariant(aQMT.value()));
    mFormat = aFormat;
    mMessage.formatMessage(aFormat, qvl);
    if (aQMT() == QtCriticalMsg) ERROR << mMessage;
//    if (aQMT() == QtFatalMsg) ASSERT(mMessage);
    return result;
}

DomStatus::Item DomStatus::Item::setFormat(const QQString aFormat, const QVariant v1, const QVariant v2, const QVariant v3, const QVariant v4)
{
    QVariantList qvl = QVariantList() << QVariant() << v1 << v2 << v3 << v4;
    return setFormat(aFormat, qvl);
}

DomStatus::Item DomStatus::Item::setFormat(const QQString aFormat, const QVariantList qvl)
{
    mFormat = aFormat, mVariants = qvl;
    mMessage = mFormat.formatMessage(qvl);
    return it();
}

/* ------------------------- non-members ------------------------ */

extern EIRXML_EXPORT QDebug operator << (QDebug dbg, const DomStatus::Item &dsi)
{
    dbg << dsi.toString(); return dbg;
}

QDebug operator << (QDebug dbg, const DomStatus &ds)
{
    for (QQString s : ds.toDebugStrings())
        dbg << s << Qt::endl;
    return dbg;
}
