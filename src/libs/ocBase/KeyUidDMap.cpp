#include "KeyUidDMap.h"


Uid KeyUidDMap::insert(const Key &key)
{
    Uid uid(true);
    return insert(key, uid);
}

Uid KeyUidDMap::insert(const Key &key, const Uid uid)
{
    Uid result(uid);
    mUidKeyDMap.remove(uid, mUidKeyDMap.at(uid));
    mUidKeyDMap.insert(result, key);
    return result;
}
