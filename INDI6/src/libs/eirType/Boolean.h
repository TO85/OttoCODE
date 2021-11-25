#pragma once
#include "eirType.h"

#include <QtCore/QMetaType>
#include <QtCore/QString>

class EIRTYPE_EXPORT Boolean
{
public:
    Boolean(const bool is) : mValid(true), mBool(is) {;}
    Boolean() = default;
    Boolean(const Boolean &other) = default;
    ~Boolean() = default;
    Boolean &operator = (const Boolean &other) = default;

    bool is() const { return mValid && mBool; }
    bool notIs() const { return ! is(); }
    bool isValid() const { return mValid; }
    bool isNull() const { return ! mValid && ! mBool; }
    bool isInvalid() const { return ! isValid(); }
    bool wasSet() const { return isValid(); }
    bool notSet() const { return isInvalid(); }
    bool isTrue() const { return mBool; }
    bool notTrue() const { return ! isTrue(); }
    operator bool () const { return isTrue(); }
    bool operator () () const { return is(); }
    QString toString() const;
    operator QString () const { return toString(); }

    bool set(const bool b=true) { mBool = b, mValid = true; return is(); }
    bool unset(const bool isNot=true) { mBool = ! isNot, mValid = true; return is(); }
    bool operator = (const bool b) { set(b); return is(); }
    void validate() { mValid = true; }
    void invalidate() { mValid = false, mBool = true; }

private:
    bool mValid=false;
    bool mBool=true;
};

Q_DECLARE_METATYPE(Boolean);

EIRTYPE_EXPORT QDebug operator<<(QDebug dbg, const Boolean &boolean);
