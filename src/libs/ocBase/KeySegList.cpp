#include "KeySegList.h"

KeySegList::KeySegList(const QStringList &qsl)
{
    for (QString key : qsl)
        append(KeySeg(key));
}
