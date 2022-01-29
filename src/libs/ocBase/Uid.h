/*! @file Uid.h Declare Uid class based upon QUuid
 *  @ingroup ocBase
 *  @sa QtCore/QUuid
 */
#pragma once

#include <QtCore/QUuid>
#include <QtCore/QRandomGenerator>

#include "AsciiString.h"
#include "TypeDefs.h"

class Uid
{
public:
    typedef DWORD Seed;
    typedef NIBBLE Version;
    typedef TRIBIT Variant;
    typedef QWORD Half;
    typedef OWORD Value;


public:
    Uid();
    Uid(const bool create);

public:
    Value value() const;
    QUuid toUuid() const;
    AsciiString toHex() const;
    QString toString() const;
    QString tail() const;

public:
    Value set(const bool create);
    Value set(const Half upper, const Half lower);

public: // static
    static void randomize(const Seed seed=0);
    static Uid createVersion4(const DWORD type=$nullType, const QWORD seq=0);

protected:
    const Uid it() const { return *this; }
    Uid &it() { return *this; }

public: // debug
    QString trace() const { return tail(); }

private:
    union
    {
        OWORD       oword = 0;
        QWORD       qword[2];
        DWORD       dword[4];
        WORD        word[8];
        BYTE        byte[16];
        struct
        {
            DWORD       dword0;
            union
            {
                DWORD       flags;
                DWORD       version : 4,
                            typeHi  : 4,
                            bit63   : 1,
                            variant : 3,
                            typeLo  : 4;
            };
            QWORD       qword8;
        };
    } mValues;
    static QRandomGenerator mGenerator;

public:
    enum Flag
    {
        UidVersion1         = 0b0001000000000000,
        UidVersion2         = 0b0010000000000000,
        UidVersion3         = 0b0011000000000000,
        UidVersion4         = 0b0100000000000000,
        UidVersion5         = 0b0101000000000000,
        UidVerReserved6     = 0b0110000000000000,
        UidVerReserved7     = 0b0111000000000000,
        UidVersionMask      = 0b1111000000000000,
        UidNibble5Mask      = 0b0000111100000000,
        UidVariantApollo    = 0b0000000000000000,
        uidVarReserved1     = 0b0000000000100000,
        uidVarReserved2     = 0b0000000001000000,
        uidVarReserved3     = 0b0000000001100000,
        UidVariantDCE       = 0b0000000010000000,
        UidVarReserved5     = 0b0000000010100000,
        UidVariantMicrosoft = 0b0000000011000000,
        UidVarReserved7     = 0b0000000011100000,
        UidVariantMask      = 0b0000000011100000,
        UidNibble6Bit3      = 0b0000000000010000,
        UidNibble7Mask      = 0b0000000000001111,
        UidTypeMask         = UidNibble5Mask | UidNibble7Mask
    };
    enum Type
    {
        $nullType           = 0b0000000000000000,
        ReservedType01      = 0b0000000000000001,
        ReservedType02      = 0b0000000000000010,
        ReservedType03      = 0b0000000000000011,
        ReservedType04      = 0b0000000000000100,
        ReservedType05      = 0b0000000000000101,
        ReservedType06      = 0b0000000000000110,
        ReservedType07      = 0b0000000000000111,
        ReservedType08      = 0b0000000000001000,
        ReservedType09      = 0b0000000000001001,
        ReservedType0A      = 0b0000000000001010,
        ReservedType0B      = 0b0000000000001011,
        ReservedType0C      = 0b0000000000001100,
        ReservedType0D      = 0b0000000000001101,
        ReservedType0E      = 0b0000000000001110,
        ReservedType0F      = 0b0000000000001111,
        ReservedType10      = 0b0000000100000000,
        ReservedType20      = 0b0000001000000000,
        ReservedType30      = 0b0000001100000000,
        ReservedType40      = 0b0000010000000000,
        ReservedType50      = 0b0000010100000000,
        ReservedType60      = 0b0000011000000000,
        ReservedType70      = 0b0000011100000000,
        ReservedType80      = 0b0000100000000000,
        ReservedType90      = 0b0000100100000000,
        ReservedTypeA0      = 0b0000101000000000,
        ReservedTypeB0      = 0b0000101100000000,
        ReservedTypeC0      = 0b0000110000000000,
        ReservedTypeD0      = 0b0000110100000000,
        ReservedTypeE0      = 0b0000111000000000,
        ReservedTypeF0      = 0b0000111100000000,
    };

};


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

