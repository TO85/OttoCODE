#pragma once
#include "eirData.h"

#include <eirType/Milliseconds.h>
#include <eirType/MultiName.h>
#include <eirType/QQVariant.h>

#include "BaseVolatileSettings.h"

class EIRDATA_EXPORT SettingsSnapshot
{
public: // types
    typedef Milliseconds Id;
    typedef MultiName Key;
    typedef QList<Key> KeyList;
    typedef QQVariant Value;
    typedef QPair<Key, Value> Pair;
    typedef QList<Pair> PairList;
    typedef QMap<Key, Value> Map;

public: // ctors
    explicit SettingsSnapshot() = default;
    SettingsSnapshot(const SettingsSnapshot &other) = default;
    ~SettingsSnapshot() = default;
    SettingsSnapshot &operator = (const SettingsSnapshot &other) = default;

public: // access
    bool contains(const Key &aKey);
    Value value(const Key &aKey, const Value defValue) const;
    Value &at(const Key &aKey); // NOT const
    void set(const Key &aKey, const Value &aValue);
    void remove(const Key &aKey);
    KeyList keys(const Key &aGroupKey=Key()) const;
    KeyList allKeys() const;
    PairList list(const Key &aGroupKey=Key()) const;
    PairList allList() const;


public: // Commands
    void append(const Key &aKey, const Value &aValue);
    void append(const Pair aPair);
    void append(const Map &aMap, const Key &aGroupKey=Key());
    Id apply(const SettingsSnapshot &other);

private:
    BaseVolatileSettings *mpSettings;
    Id mId;
};

Q_DECLARE_METATYPE(SettingsSnapshot);
