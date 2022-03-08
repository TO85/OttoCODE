#pragma once
#include "ocBase.h"

#include <QList>
#include "KeySeg.h"

class OCBASE_EXPORT KeySegList : public QList<KeySeg>
{
public:
    KeySegList();
};

