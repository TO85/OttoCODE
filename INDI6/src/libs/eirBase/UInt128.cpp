// file: {EIRC2 repo}./src/libs/eirType/UInt128.cpp
#include "UInt128.h"

//#include <XFR>

UInt128::UInt128() : mUpperLowerPair(0,0)
{
//    XENTER();
}

UInt128::UInt128(const quint64 upper, const quint64 lower)
{
//    XENTER();
//    XARG1(upper);
//    XARG2(lower);
    set(upper, lower);
}

UInt128::UInt128(const QUuid quuid)
{
    bool ok;
    QByteArray qbaRaw128 = quuid.toByteArray(QUuid::Id128);
    quint64 u64upper = qbaRaw128.left(128).toULongLong(&ok, 16);
    quint64 u64lower = qbaRaw128.mid(128).toULongLong(&ok, 16);
    set(u64upper, u64lower);
}

UInt128 UInt128::set(const quint64 upper, const quint64 lower)
{
    mUpperLowerPair = Pair128(upper, lower);
    return *this;
}

QString UInt128::toHex(bool with0x) const
{
    QString hex = with0x ? "0x" : "";
    hex += QString::number(mUpperLowerPair.first, 16);
    hex += QString::number(mUpperLowerPair.second, 16);
    return hex;
}

quint64 UInt128::upper() const
{
    return mUpperLowerPair.first;
}

quint64 UInt128::lower() const
{
    return mUpperLowerPair.second;
}

bool UInt128::operator ==(const UInt128 &other)
{
    return upper() == other.upper() && lower() == other.lower();
}

bool UInt128::operator <(const UInt128 &other)
{
    return (upper() == other.upper())
            ? lower() <  other.lower()
            : upper() <  other.upper();
}
