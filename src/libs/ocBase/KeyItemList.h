#pragma once
#include "ocBase.h"

#include <QList>
#include "KeySeg.h"

class OCBASE_EXPORT KeyItemList : public QList<KeySeg>
{
public:
    KeyItemList();
};

