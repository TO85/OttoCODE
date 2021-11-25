#include "MultiNameList.h"

#include <eirXfr/Debug.h>

MultiNameList::MultiNameList(const QList<MultiName> aNames)
{
    for ( MultiName mn : aNames )
        append(mn);
}

QQStringList MultiNameList::toStringList() const
{
    QQStringList result;
    for ( MultiName mn : it() )
        result << mn.toString();
    return result;
}

QStringList MultiNameList::toQStringList() const
{
    QStringList result;
    for ( MultiName mn : it() )
        result << mn.toString();
    return result;
}

QString MultiNameList::toQString(const QString &sep)
{
    return toQStringList().join(sep);
}
