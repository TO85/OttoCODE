#include "QQByteArrayList.h"

#include <eirXfr/Debug.h>


void QQByteArrayList::set(const QList<QByteArray> &other)
{
    for (QByteArray qba : other) append(QQByteArray(qba));
}
