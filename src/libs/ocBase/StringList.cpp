#include "StringList.h"


StringList::StringList(const int size, const String &fill)
    : QList<String>(size, fill) {;}

StringList::StringList(const QList<QString> other)
{
    for (QString qs : other) append(qs);
}
