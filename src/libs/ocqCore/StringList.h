#pragma once

#include <List>
#include "QQString.h"

class StringList : public List<String>
{
public:
    StringList();
    StringList(const QList<QString> other);
    StringList(const int size, const String &fill=String());
};

