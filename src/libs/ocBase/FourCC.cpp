#include "FourCC.h"

#include "AsciiString.h"

FourCC::FourCC(const char *pch)
{
    mValue = 0;
    strncpy((char *)(&mValue), pch, sizeof(mValue));
}

FourCC::FourCC(const AsciiString &s)
{
    mValue = 0;
    QByteArray fBA(sizeof(mValue)+1, 0);
    strncpy(fBA.data(), s.data(), sizeof(mValue));
    strncpy((char *)(&mValue), fBA.data(), sizeof(mValue));
}

AsciiString FourCC::string() const
{
    QByteArray result(sizeof(mValue)+1, 0);
    strncpy(result.data(), (char *)(&mValue), result.size());
    return result;
}

FourCC::operator DWORD() const
{
    return value();
}

FourCC::operator AsciiString() const
{
    return string();
}
