#pragma once

#include <List>
#include "QQString.h"

class QQStringList : public List<QQString>
{
public:
    QQStringList();
    QQStringList(const QList<QString> other);
    QQStringList(const int size, const QQString &fill=QQString());
};

