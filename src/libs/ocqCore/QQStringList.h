#pragma once

#include <QList>
#include "QQString.h"

class QQStringList : public QList<QQString>
{
public:
    QQStringList();
    QQStringList(const QList<QString> other);
    QQStringList(const int size, const QQString &fill=QQString());
};

