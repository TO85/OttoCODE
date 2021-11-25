#include "QQDomDocument.h"

#include <eirXfr/Debug.h>

#include "QQDomElement.h"

QQDomElement QQDomDocument::rootElement() const
{
    return documentElement();
}

DomStatus QQDomDocument::set()
{
    DomStatus::Item statusItem;
    if (mBytes.isEmpty())
        statusItem.setMessage(QtCriticalMsg, "Byte Array is Empty");
    else
        statusItem.setMessage(QtInfoMsg, "Byte Array contains "+QQString::number(mBytes.size())+" bytes");
    TRACEQFI << statusItem.toString();
    mStatus.append(statusItem);
    return mStatus;
}

/* ------------------------- debug --------------------------*/

QQStringList QQDomDocument::toDebugStrings() const
{
    QQStringList result;
    result << "{QQDomDocument: " + doctypeName();
    QQDomElement rootDE = documentElement();
    result << rootDE.toDebugStrings();
    result << "<QQDomDocument}";
    return result;
}

/* ------------------------- non-member --------------------------*/

QDebug operator << (QDebug dbg, const QQDomDocument &doc)
{
    for (auto s : doc.toDebugStrings())
        dbg << s << Qt::endl;
    return dbg;
}
