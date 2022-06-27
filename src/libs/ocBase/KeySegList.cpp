#include "KeySegList.h"

KeySegList::KeySegList(const QList<KeySeg> &other)
{
    it() = other;
}

KeySegList::KeySegList(const QStringList &qsl)
{
    for (QString key : qsl)
        append(KeySeg(key));
}
