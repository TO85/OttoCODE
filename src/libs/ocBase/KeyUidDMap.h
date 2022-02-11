#pragma once

#include <DualMap>

#include "Key.h"
#include "Uid.h"

class KeyUidDMap
{
public:
    KeyUidDMap() {;}
    KeyUidDMap(const Key & key) { insert(key); }

public:
    Uid uid(const Key & key) const;
    Key key(const Uid uid) const;
    static Uid::Flag uidType();

public:
    Uid insert(const Key & key);
    Uid insert(const Key & key, const Uid uid);

private:
    DualMap<Uid, Key> mUidKeyDMap;
    static Uid::Flag smUidType;
};

