#include "KeySeg.h"

#include "Sortable.h"

KeySeg::KeySeg() {;}
KeySeg::KeySeg(const QString &qs) : mString(qs) {;}

bool KeySeg::startsWith(const KeySeg &stub) const
{
    return mString.startsWith(stub.toQString());
}

bool KeySeg::less(const KeySeg &other) const
{
    return Sortable(toQString()) < Sortable(other.toQString());
}

QString KeySeg::toQString() const
{
    return mString;
}

void KeySeg::clear()
{
    mString.clear();
}

bool operator < (const KeySeg & lhs, const KeySeg & rhs)
{
    return lhs.less(rhs);
}
