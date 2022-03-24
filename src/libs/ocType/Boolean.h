#pragma once
#include "ocType.h"

#include <QtCore/QMetaType>
#include <QtCore/QString>

class OCTYPE_EXPORT Boolean
{
public:
    Boolean(const bool is) : mValid(true), mTrue(is) {;}

public:
    bool is() const { return mValid && mTrue; }
    bool notIs() const { return ! is(); }
    bool isValid() const { return mValid; }
    bool isNull() const { return ! mValid && ! mTrue; }
    bool isInvalid() const { return ! isValid(); }
    bool wasSet() const { return isValid(); }
    bool notSet() const { return isInvalid(); }
    bool isTrue() const { return mTrue; }
    bool notTrue() const { return ! isTrue(); }
    operator bool () const { return is(); }
    bool operator () () const { return is(); }
    QString toString() const;
    operator QString () const { return toString(); }

public:
    bool set(const bool b=true) { mTrue = b, mValid = true; return is(); }
    bool unset(const bool isNot=true) { mTrue = ! isNot, mValid = true; return is(); }
    bool operator = (const bool b) { return set(b); }
    void validate() { mValid = true; }
    void validate(const bool b);
    void invalidate() { mValid = false; }
    void nullify() { mValid = false, mTrue = false; }

public:
    static QString toString(const Boolean b) { return b.toString(); }

private:
    bool mValid=false;
    bool mTrue=false;

public:
    Boolean() = default;
    Boolean(const Boolean &other) = default;
    ~Boolean() = default;
    Boolean &operator = (const Boolean &other) = default;
};

Q_DECLARE_METATYPE(Boolean);

OCTYPE_EXPORT QDebug operator<<(QDebug dbg, const Boolean &boolean);
