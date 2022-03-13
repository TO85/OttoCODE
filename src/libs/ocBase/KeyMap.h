#pragma once
#include "ocBase.h"

#include "Key.h"

template <typename T> class OCBASE_EXPORT KeyMap
{
public:
    KeyMap() {;}

public:
    bool isEmpty() const { return mKeyTMap.isEmpty(); }
    bool notEmpty() const { return ! isEmpty(); }
    bool contains(const Key &key) const { return mKeyTMap.contains(key); }
    bool notContains(const Key &key) const { return ! contains(key); }
    const T value(const Key &key) const { return mKeyTMap.value(key); }
    const QList<Key> keys() const { return mKeyTMap.keys(); }

public:
    void clear() { mKeyTMap.clear(); }
    void insert(const Key &key, const T &t) { mKeyTMap.insert(key, t); }

private:
    QMap<Key, T> mKeyTMap;
};
