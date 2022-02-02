#include "KeyItem.h"

#include "Sortable.h"

KeyItem::KeyItem() {;}
KeyItem::KeyItem(const QString &qs) : mString(qs) {;}

bool KeyItem::startsWith(const KeyItem &stub) const
{
    return mString.startsWith(stub.toQString());
}

bool KeyItem::less(const KeyItem &other) const
{
    return Sortable(toQString()) < Sortable(other.toQString());
}

QString KeyItem::toQString() const
{
    return mString;
}

void KeyItem::clear()
{
    mString.clear();
}

bool operator < (const KeyItem lhs, const KeyItem rhs)
{
    return lhs.less(rhs);
}
