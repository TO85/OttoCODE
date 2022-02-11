#pragma once

#include <QList>
#include "String.h"

class StringList : public QList<String>
{
public:
    StringList() {;}
    StringList(const QList<QString> other);
    StringList(const int size, const String &fill=String());
};

