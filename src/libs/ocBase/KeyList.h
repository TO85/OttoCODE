#pragma once
#include "ocBase.h"

#include <QList>
#include "Key.h"

class OCBASE_EXPORT KeyList : public QList<Key>
{
public:
    KeyList();
    KeyList(QList<Key> other) : QList<Key>(other) {;}
};

