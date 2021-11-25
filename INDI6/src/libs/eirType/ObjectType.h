#pragma once
#include "eirType.h"

#include <QtCore/QList>
#include <QtCore/QMetaType>
#include <QtCore/QString>


class EIRTYPE_EXPORT ObjectType
{
public:
    enum Value
    {
        $null = 0,
        $beginFace = 10,
        $beginFaceFrontal = 20,
        FaceFrontalHead,
        FaceFrontalFull,
        FaceFrontalTight,
        $endFaceFrontal,
        $beginFaceProfile = 30,
        FaceProfileLeft,
        FaceProfileRight,
        FaceProfileEither,
        $endFaceProfile,
        $endFace,
        $beginFacialFeature = 100,
        $beginEye = 110,
        EyeLeft,
        EyeRight,
        EyeNeither,
        EyeEither,
        EyeBoth,
        $endEye = 119,
        Nose = 121,
        Mouth = 131,
        $endFacialFeature,
        $beginBody = 200,
        BodyFull,
        BodyUpper,
        BodyLower,
        $endBody = 299,
        $beginOther = 900,
        LicensePlate = 911,
        VehicleGeneral,
        CatFace = 951,
        $invalid = 990,
        $nothandled,
        $maximum
    };
    typedef QList<ObjectType> List;

public:
    ObjectType() = default;
    ObjectType(const Value aValue) : mValue(aValue) {;}
    ObjectType(const ObjectType &other) = default;
    ~ObjectType() = default;
    ObjectType &operator = (const ObjectType &other) = default;

    enum Value value() const { return mValue; }

    QString name() const { return name(mValue); }
    bool isNull() const { return $null == value(); }
    bool isValid() const { return isValid(mValue); }
    bool notValid() const { return ! isValid(); }
    bool equal(const ObjectType &other) const { return value() == other.value(); }
    bool lessthan (const ObjectType &other) const { return value() < other.value(); }
    bool operator == (const ObjectType &other) const { return equal(other); }
    bool operator < (const ObjectType &other) const { return lessthan(other); }

    bool isFaceFrontal() const;
    bool isEye() const;
    QChar eyeChar() const;

    QString toDebugString() const;

public: // static
    static bool isValid(const int iInt);
    static bool notValid(const int iValue) { return ! isValid(iValue); }
    static Value value(const QString &aName);
    static QString name(const int aInt);
    static QString name(const enum Value aEnum);

private:
    enum Value mValue=$null;
};

Q_DECLARE_METATYPE(ObjectType);

extern EIRTYPE_EXPORT bool operator == (const ObjectType &lhs, const ObjectType &rhs);
extern EIRTYPE_EXPORT QDebug operator << (QDebug dbg, const ObjectType &ot);

