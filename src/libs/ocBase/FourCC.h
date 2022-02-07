#pragma once
#include "ocBase.h"

#include <QMetaType>

class AsciiString;

class OCBASE_EXPORT FourCC
{
public:
    FourCC(const char * pch);
    FourCC(const AsciiString & s);
    FourCC() = default;
    ~FourCC() = default;
    FourCC(const FourCC &other) = default;
    FourCC &operator = (const FourCC &other) = default;

public:
    bool isNull() const { return 0 == mValue; }
    bool notNull() const { return ! isNull(); }
    DWORD value() const { return mValue; }
    AsciiString string() const;
    operator DWORD () const;
    operator AsciiString () const;

private:
    DWORD mValue;
};


Q_DECLARE_METATYPE(FourCC);

