#pragma once
#include "ocBase.h"

#include <QStringList>

#include <QList>
#include "KeySeg.h"

class OCBASE_EXPORT KeySegList : public QList<KeySeg>
{
public:
    KeySegList() {;}
    KeySegList(const QList<KeySeg> &other);
    KeySegList(const QStringList &qsl);

private:
    QList<KeySeg> it() const { return *this; }
    QList<KeySeg> & it() { return *this; }
};

