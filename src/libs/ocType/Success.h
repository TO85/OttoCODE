#pragma once
#include "ocType.h"

#include "Boolean.h"

class OCTYPE_EXPORT Success
{
public:
    bool result() const { return mBoolean.isTrue() && mBoolean.isInvalid(); }
    QString toString() const { return mBoolean.toString(); }
    operator bool () const { return result(); }
    operator QString () const { return toString(); }
    bool operator () () const { return result(); }

    void expect(const bool aBool)       { if ( ! aBool) mBoolean.set(false); }
    void expectNot(const bool aBool)    { if (   aBool) mBoolean.set(false); }
    void validate()                     { mBoolean.validate(); }

private:
    Boolean mBoolean;

public: // QMetaType
    Success() = default;
    Success(const Success &other) = default;
    ~Success() = default;
    Success &operator = (const Success &other) = default;
};

