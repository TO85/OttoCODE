// file: {EIRC2 repo}./src/libs/eirBase/UInt128.h
#pragma once
#include "eirBase.h"

#include <QByteArray>
#include <QList>
#include <QPair>
#include <QString>
#include <QUuid>

class EIRBASE_EXPORT UInt128
{
public:
    typedef QPair<quint64, quint64> Pair128;

public:
    UInt128(void);
    UInt128(const Pair128 upperLowerPair);
    UInt128(const quint64 upper, const quint64 lower);
    UInt128(const QByteArray & byteArray);
    UInt128(const quint8 bytes[8]);
    UInt128(const QUuid quuid);
    UInt128 set(const Pair128 upperLowerPair);
    UInt128 set(const quint64 upper, const quint64 lower);
    UInt128 set(const QByteArray & byteArray);
    UInt128 set(const quint8 bytes[8]);
    UInt128 set(const QUuid quid);
    UInt128 toU128(void) const;
    QString toHex(bool with0x=true) const;
    QByteArray toByteArray(void)  const;
    bool isNull(void) const;
    void nullify(void);
    quint64 upper() const;
    quint64 lower() const;
    bool operator == (const UInt128 & other);
    bool operator <  (const UInt128 & other);

private:
    union
    {
        Pair128 mUpperLowerPair;
        quint8 mBytes[8];
    };
};
