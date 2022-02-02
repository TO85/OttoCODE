#pragma once
#include "ocBase.h"

#include <QList>
#include "KeyItem.h"

class OCBASE_EXPORT KeyItemList : public QList<KeyItem>
{
public:
    KeyItemList();
};

