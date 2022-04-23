#pragma once

#include "Boolean.h"

#include <QMetaType>

class Null : private Boolean
{
public:
    Null(const bool is) : Boolean(is) {;}

public:
    bool isNull() const;
    bool notNull() const { return ! isNull(); }
    operator bool () const { return isNull(); }
    bool operator () () const { return isNull(); }

public:
    bool set(const bool b=false) { return Boolean::set(b); }
    bool operator = (const bool b) { return set(b); }

public: // QMetaType
    Null() = default;
    Null(const Null &other) = default;
    ~Null() = default;
    Null &operator = (const Null &other) = default;
};

Q_DECLARE_METATYPE(Null);

