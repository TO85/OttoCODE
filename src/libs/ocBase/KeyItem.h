#pragma once
#include "ocBase.h"

#include <QString>

class OCBASE_EXPORT KeyItem
{
public:
    KeyItem();
    KeyItem(const QString & qs);

public:
    bool startsWith(const KeyItem & stub) const;
    bool less(const KeyItem & other) const;
    bool operator < (const KeyItem & other) const { return less(other); }
    QString toQString() const;

public:
    void clear();

private:
    KeyItem it() const { return *this; }
    KeyItem & it() { return *this; }

private:
    QString mString;
};

extern OCBASE_EXPORT bool operator < (const KeyItem lhs, const KeyItem rhs);

