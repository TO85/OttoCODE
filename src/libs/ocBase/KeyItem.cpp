#include "KeyItem.h"

KeyItem::KeyItem() {;}
KeyItem::KeyItem(const QString &qs) : mString(qs) {;}

QString KeyItem::toQString() const
{
    return mString;
}
