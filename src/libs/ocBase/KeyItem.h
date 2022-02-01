#pragma once
#include "ocBase.h"

#include <QString>

class KeyItem
{
public:
    KeyItem();
    KeyItem(const QString &qs);

public:
    QString toQString() const;

private:
    QString mString;
};

