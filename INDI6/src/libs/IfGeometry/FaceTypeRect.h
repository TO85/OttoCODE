#pragma once
#include "IfGeometry.h"

#include <QtCore/QMetaType>

#include <eirType/ObjectType.h>
#include <eirType/SCRect.h>

class IFGEOMETRY_EXPORT FaceTypeRect
{
public:
    enum Type { $null = 0, Head, Full, Tight, $size };

public:
    FaceTypeRect() = default;
    FaceTypeRect(const FaceTypeRect &other) = default;
    FaceTypeRect(const SCRect frect) { set(Full, frect); }
    FaceTypeRect(const Type ftype, const SCRect frect) { set(ftype, frect); }
    FaceTypeRect(const ObjectType otype, const SCRect frect) { set(type(otype), frect); }
    ~FaceTypeRect() = default;
    FaceTypeRect &operator=(const FaceTypeRect &other) = default;

    Type type() const { return mType; }
    QQString typeName() const { return typeName(type()); }
    SCRect rect() const { return mRect; }
    FaceTypeRect it() const { return *this; }
    FaceTypeRect &it() { return *this; }

    bool isNull() const { return $null == type() || rect().isNull(); }
    bool notNull() const { return ! isNull(); }
    bool is(const ObjectType fotype) { return type() == type(fotype); }
    Rational expectedEyeWidth() const { return Rational(rect().width(), 5); }

    void set(const Type ftype, const SCRect frect);
    void clear() { mType = Type::$null, mRect.nullify(); }

    QString toString() const;

public: // static
    static QQString typeName(const Type ftype);
    static Type type(const ObjectType otype);

private:
    Type mType=$null;
    SCRect mRect;
};

Q_DECLARE_METATYPE(FaceTypeRect);

extern IFGEOMETRY_EXPORT QDebug operator << (QDebug dbg, const FaceTypeRect fr);
