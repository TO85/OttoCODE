#pragma once

#include <DualMap>

#include "Key.h"
#include "Uid.h"

class KeyUidDMap : public DualMap<Uid, Key>
{
public:
    KeyUidDMap() {;}
};

