#include "ElementAttributeMap.h"

#include <eirXfr/Debug.h>

#include "QQDomNode.h"

const DomStatus &ElementAttributeMap::status() const
{
    return mStatus;
}

QQString ElementAttributeMap::value(const BasicName &aName, const QQString &defaultValue) const
{
    QQString result = mNameValueMap.value(aName, defaultValue);
    TRACEQFI << aName() << defaultValue << result;
    return result;
}

QQString ElementAttributeMap::tryExists(DomStatus *pStatus, const BasicName &aName,
                                         const QQString &defaultValue) const
{
    QQString result;
    if (contains(aName))
    {
        result = value(aName);
        pStatus->info("%1={%2}", aName(), result);
    }
    else if (defaultValue.notEmpty())
    {
        result = defaultValue;
        pStatus->warn("%1=Default: {%2}", aName(), result);
    }
    else
    {
        pStatus->error("%1 attribute not found; no default", aName());
    }
    return result;
}

QQStringList ElementAttributeMap::toInfoStrings() const
{
    QQStringList result;
    for (BasicName tKey : mNameValueMap.keys())
        result << QQString("%1 = {%2}").formatMessage(tKey(), mNameValueMap.value(tKey));
    return result;
}

DomStatus ElementAttributeMap::set()
{
    DomStatus result;
    clear();
    result.expect("Element notNull(%1)", mElement.notNull(), QtInfoMsg, QtCriticalMsg);
    if (mNodeMap.isEmpty())
        mNodeMap = mElement.attributes();
    const int nNodes = mNodeMap.length();
    for (int ix = 0; ix < nNodes; ++ix)
    {
        const QQDomNode tNode = mNodeMap.item(ix);
        WEXPECTEQ(QDomNode::AttributeNode, tNode.nodeType());
        const BasicName tName(tNode.nodeName());
        const QQString tValue(tNode.nodeValue());
        if (mNameValueMap.contains(tName))
        {
            const QQString oldValue = mNameValueMap.value(tName);
            WARN << "Duplicate Name:" << tName << oldValue;
            result.warn("Duplicate Name: %1={%2}", tName(), oldValue);
        }
        mNameValueMap.insert(tName, tValue);
        result.info("Added: %1={%2}", tName(), tNode.nodeValue());
    }
    mStatus = result;
    return result;
}

/* ----------------------- debug -------------------------- */

QStringList ElementAttributeMap::toDebugStrings() const
{
    QStringList result;
    result << "{ElementAttributeMap:>";
    result << toInfoStrings();
    result << "<ElementAttributeMap}";
    return result;
}

/* ----------------------- non-member -------------------------- */

QDebug operator << (QDebug dbg, const ElementAttributeMap &eam)
{
    for (QString s : eam.toDebugStrings())
        dbg << s << Qt::endl;
    return dbg;
}
