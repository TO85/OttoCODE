#include "QQStringList.h"


QQStringList::QQStringList(const int size, const QQString &fill)
    : List<QQString>(size, fill) {;}

QQStringList::QQStringList(const QList<QString> other)
{
    for (QString qs : other) append(qs);
}
