#include "FaceTypeRect.h"

#include <eirXfr/Debug.h>

void FaceTypeRect::set(const FaceTypeRect::Type ftype, const SCRect frect)
{
    TRACEQFI << ftype << frect;
    mType = ftype, mRect = frect;
}

QString FaceTypeRect::toString() const
{
    return QString("FaceRect: Type=%1 Rect=%2").arg(typeName(), rect().toDebugString());
}

// ------------------------------------- static  ---------------------------------------

QQString FaceTypeRect::typeName(const Type ftype)
{
    switch (ftype)
    {
    case Type::Full:        return "Full";
    case Type::Tight:       return "Tight";
    case Type::Head:        return "Head";
    case Type::$null:       return "{null}";
    case Type::$size:       return "{size}";
    }
    return "{error}";
}

FaceTypeRect::Type FaceTypeRect::type(const ObjectType otype)
{
    switch (otype.value())
    {
    case ObjectType::FaceFrontalHead:                   return Type::Head;
    case ObjectType::FaceFrontalFull:                   return Type::Full;
    case ObjectType::FaceFrontalTight:                  return Type::Tight;
    default: WARNQFI << "Invalid" << otype.name();      return Type::$null;
    }
}

// ------------------------------------- non-member  ---------------------------------------

QDebug operator << (QDebug dbg,  const FaceTypeRect fr)
{
    dbg << fr.toString(); return dbg;
}

