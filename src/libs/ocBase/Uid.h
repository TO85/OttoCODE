/*! @file Uid.h Declare Uid class based upon QUuid
 *  @ingroup ocBase
 *  @sa QtCore/QUuid
 */
#pragma once
#include "ocBase.h"

#include <QtCore/QUuid>
#include <QtCore/QString>
#include <QtCore/QRandomGenerator>

#include "TypeDefs.h"

class OCBASE_EXPORT Uid
{
public:
    typedef DWORD Seed;
    typedef QWORD Id;
    typedef NIBBLE Version;
    typedef TRIBIT Variant;
    typedef QWORD Half;
    typedef OWORD Whole;
    typedef WORD Type;
    typedef QWORD Value;

public:
    Uid();
    Uid(const bool create);
    Uid(const Type type, const Value value);

public:
    bool isNull() const;
    bool notNull() const { return  ! isNull(); }
    bool isValid() const;
    bool notValid() const { return  ! isValid(); }
    Whole whole() const;
    Half upper() const;
    Half lower() const;
    QUuid toUuid() const;
    Id id() const;
    Type type() const;
    Value value() const;
    QString toHex() const;
    QString toString() const;
    QString tail() const;
    bool equal(const Uid &other) const;
    bool less(const Uid &other) const;
    bool operator == (const Uid &other) const { return equal(other); }
    bool operator <  (const Uid &other) const { return less(other); }

public:
    Whole set(const bool create);
    Whole variant(const Variant aVariant);
    Whole set(const Half upper, const Half lower);
    Whole set(const Type type, const Value value=0);
    Whole create(const Type type, const Value value=0);
    Whole id(const Id aId);

public: // static
    static void randomize(const Seed seed=0);
    static Uid createVersion4(const Type type=$nullType, const Value value=0);

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
            DWORD       dword0; // Value
            union
            {
                DWORD       flags;
                DWORD       version : 4,
                            typeHi  : 4,
                            valid   : 1,
                            variant : 3,
                            typeLo  : 4;
            };
            QWORD       qword8; // Id
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
        UidVarOttoCODE      = 0b0000000010100000,
        UidVariantMicrosoft = 0b0000000011000000,
        UidVarReserved7     = 0b0000000011100000,
        UidVariantMask      = 0b0000000011100000,
        UidValid            = 0b0000000000010000,
        UidNibble7Mask      = 0b0000000000001111,
        UidTypeMask         = UidNibble5Mask | UidNibble7Mask
    };
    enum QVariant
    {
        VariantApollo       = 0,
        VariantReserved1    = 1,
        VariantReserved2    = 2,
        VariantReserved3    = 3,
        VariantDCE          = 4,
        VariantOttoCODE     = 5,
        VariantReserved6    = 6,
        VariantReserved7    = 7
    };

    enum Types
    {
        $nullType           = 0b0000000000000000,
        $type00min          = 0b0000000000000001,
        $type00max          = 0b0111111111111111,
        $type01min          = 0b1000000000000001,
        $type01max          = 0b1011111111111111,
        $type02min          = 0b1100000000000001,
        $type02max          = 0b1101111111111111,
        $type03min          = 0b1110000000000001,
        LogType             = 0b1110000000000010,
        LogItemType         = 0b1110000000000011,
        LogChannelType      = 0b1110000000000100,
        $LogMaxType         = 0b1110000000011111,
        $type03max          = 0b1110111111111111,
        $type04min          = 0b1111000000000001,
        $type04max          = 0b1111011111111111,
        $type05min          = 0b1111100000000001,
        $type05max          = 0b1111101111111111,
        $type06min          = 0b1111110000000001,
        $type06max          = 0b1111110111111111,
        $type07min          = 0b1111111000000001,
        $type07max          = 0b1111111011111111,
        $type08min          = 0b1111111100000001,
        $type08max          = 0b1111111101111111,
        $type09min          = 0b1111111110000001,
        $type09max          = 0b1111111110111111,
        $type10min          = 0b1111111111000001,
        $type10max          = 0b1101111111011111,
        $type11min          = 0b1111111111100001,
        $type11max          = 0b1110111111101111,
        $type12min          = 0b1111111111110001,
        $type12max          = 0b1111011111110111,
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

