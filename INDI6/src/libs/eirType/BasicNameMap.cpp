#include "BasicNameMap.h"

#include <eirXfr/Debug.h>

bool BasicNameMap::contains(const BasicName &aName) const
{
    return mMap.contains(aName.sortable());
}

QQStringList BasicNameMap::nameValueStrings() const
{
    QQStringList result;
    for ( BasicName name : mMap.keys() )
        result << QQString("%1=<%2>").formatMessage(name(),
                mMap.value(name.sortable()).second.toString());
    return result;
}

QQVariant BasicNameMap::value(const BasicName &aName) const
{
    return mMap.contains(aName.sortable()) ? mMap.value(aName.sortable()).second : QQVariant();
}

QQVariant BasicNameMap::value(const BasicName &aName, const QQVariant &defaultVari) const
{
    return mMap.contains(aName.sortable()) ? mMap.value(aName.sortable()).second : defaultVari;
}

void BasicNameMap::set(const BasicName &aName, const QQVariant &aVari)
{
    mMap.insert(aName.sortable(), NameVari(aName, aVari));
}

void BasicNameMap::insert(const BasicName &aName, const QQVariant &aVari)
{
    // TODO(template<KEY>); // insert() included for QMap compatibility
    set(aName, aVari);
}

void BasicNameMap::set(const NameVari &aPair)
{
    mMap.insert(aPair.first.sortable(), aPair);
}
