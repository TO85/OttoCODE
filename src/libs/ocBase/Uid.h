/*! @file Uid.h Declare Uid class based upon QUuid
 *  @ingroup ocBase
 *  @sa QtCore/QUuid
 */
#pragma once

#include <QtCore/QUuid>

#include <QtCore/QMetaType>
#include <QtCore/QRandomGenerator>

#include "TypeDefs.h"

class Uid
{
public:
    typedef DWORD Seed;
    typedef NIBBLE Version;
    typedef TRIBIT Variant;
    typedef OWORD Value;

public:
    Uid(const bool create);
    Uid() = default;
    Uid(const Uid &other) = default;
    Uid &operator = (const Uid &other) = default;
    ~Uid() = default;

public:
    Value set(const bool create);

public:
    QString toString() const;
    QString tail() const;

protected:
    Value setValue();

public: // debug
    QString trace() const { return tail(); }

private:
    QUuid mUuid;
    union
    {
        OWORD       oword = 0;
        QWORD       qword[2];
        DWORD       dword[4];
        WORD        word[8];
        BYTE        byte[16];
    } mValues;
    QRandomGenerator mGenerator;
};

Q_DECLARE_METATYPE(Uid);

#if 0
Uid(const QByteArray &other);
Uid(const QString &fromString);
Uid(const Variant variant, const QByteArray name);
Uid(const Variant variant, const QString name);
Uid(const Uid base, const QByteArray name);
Uid(const Uid base, const QString name);

Value set(const QByteArray &other);
Value set(const QString &fromString);
Value set(const Variant variant, const QByteArray name);
Value set(const Variant variant, const QString name);
Value set(const Uid base, const QByteArray name);
Value set(const Uid base, const QString name);

public:
Version version() const;
Variant variant() const;
Version version(const Version ver);
Variant variant(const Variant ver);
QByteArray toHex() const;
OWORD randomize();
void reseed(const Seed seed);

private:
static OWORD random();


#endif

