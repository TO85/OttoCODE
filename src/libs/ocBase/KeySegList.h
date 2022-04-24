#pragma once
#include "ocBase.h"

#include <QStringList>

#include <QList>
#include "KeySeg.h"

class OCBASE_EXPORT KeySegList : public QList<KeySeg>
{
public:
    KeySegList() {;}
    KeySegList(const QStringList &qsl);
};

