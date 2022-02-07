#pragma once
#include "ocBase.h"

#include <QString>

class OCBASE_EXPORT KeySeg
{
public:
    KeySeg();
    KeySeg(const QString & qs);

public:
    bool startsWith(const KeySeg & stub) const;
    bool less(const KeySeg & other) const;
    QString toQString() const;
    bool operator < (const KeySeg & other) const { return less(other); }
    operator QString () const { return toQString(); }

public:
    void clear();

private:
    KeySeg it() const { return *this; }
    KeySeg & it() { return *this; }

private:
    QString mString;
};

extern OCBASE_EXPORT bool operator < (const KeySeg & lhs, const KeySeg & rhs);

