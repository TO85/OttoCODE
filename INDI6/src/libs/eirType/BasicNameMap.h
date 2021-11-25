#pragma once
#include "eirType.h"

#include <QtCore/QMetaType>

#include "BasicName.h"
#include "QQVariant.h"

class EIRTYPE_EXPORT BasicNameMap
{
public:
    typedef QPair<BasicName, QQVariant> NameVari;
    typedef QList<NameVari> NameVariList;

public:
    explicit BasicNameMap() = default;
    BasicNameMap(const BasicNameMap &other) = default;
    ~BasicNameMap() = default;
    BasicNameMap &operator = (const BasicNameMap &other) = default;

public:
    bool contains(const BasicName &aName) const;
    NameVariList list() const { return mMap.values(); }
    QQStringList nameValueStrings() const;

public:
    QQVariant value(const BasicName &aName) const;
    QQVariant value(const BasicName &aName, const QQVariant &defaultVari) const;

    void clear() { mMap.clear(); }
    void set(const BasicName &aName, const QQVariant &aVari);
    void insert(const BasicName &aName, const QQVariant &aVari);
    void set(const NameVari &aPair);

private:
    QMap<BasicName::Sortable, NameVari> mMap;
};

Q_DECLARE_METATYPE(BasicNameMap);

