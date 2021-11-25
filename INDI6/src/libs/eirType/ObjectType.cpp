#include "ObjectType.h"

#include <QtGlobal>

#include <eirXfr/Debug.h>

/* ------------------------- static ----------------------------- */

bool ObjectType::isValid(const int iInt)
{
    TRACEQFI << iInt << $null << $maximum;
    if (name(iInt).startsWith('$')) return false;
    if (iInt <= $null) return false;
    if (iInt >= $maximum) return false;
    return true;
}

ObjectType::Value ObjectType::value(const QString &aName)
{
    TRACEQFI << aName;
    if      (false)                             ;
    else if ("$null" == aName)                  return $null;
    else if ("$beginFace" == aName)             return $beginFace;
    else if ("$beginFaceFrontal" == aName)      return $beginFaceFrontal;
    else if ("FaceFrontalHead" == aName)        return FaceFrontalFull;
    else if ("FaceFrontalFull" == aName)        return FaceFrontalFull;
    else if ("FaceFrontalTight" == aName)       return FaceFrontalTight;
    else if ("$endFaceFrontal" == aName)        return $endFaceFrontal;
    else if ("$beginFaceProfile" == aName)      return $beginFaceProfile;
    else if ("FaceProfileLeft" == aName)        return FaceProfileLeft;
    else if ("FaceProfileRight" == aName)       return FaceProfileRight;
    else if ("FaceProfileEither" == aName)      return FaceProfileEither;
    else if ("$endFaceProfile" == aName)        return $endFaceProfile;
    else if ("$endFace" == aName)               return $endFace;
    else if ("$beginFacialFeature" == aName)    return $beginFacialFeature;
    else if ("$beginEye" == aName)              return FaceFrontalFull;
    else if ("FaceFrontalHead" == aName)        return $beginEye;
    else if ("EyeLeft" == aName)                return EyeLeft;
    else if ("EyeRight" == aName)               return EyeRight;
    else if ("EyeNeither" == aName)             return EyeNeither;
    else if ("EyeEither" == aName)              return EyeEither;
    else if ("EyeBoth" == aName)                return EyeBoth;
    else if ("$endEye" == aName)                return $endEye;
    else if ("Nose" == aName)                   return Nose;
    else if ("Mouth" == aName)                  return Mouth;
    else if ("$endFacialFeature" == aName)      return $endFacialFeature;
    else if ("$beginBody" == aName)             return $beginBody;
    else if ("BodyFull" == aName)               return BodyFull;
    else if ("BodyUpper" == aName)              return BodyUpper;
    else if ("BodyLower" == aName)              return BodyLower;
    else if ("$endBody" == aName)               return $endBody;
    else if ("$beginOther" == aName)            return $beginOther;
    else if ("LicensePlate" == aName)           return LicensePlate;
    else if ("VehicleGeneral" == aName)         return VehicleGeneral;
    else if ("CatFace" == aName)                return CatFace;
    else if ("$invalid" == aName)               return $invalid;
    else if ("$nothandled" == aName)            return $nothandled;
    else if ("$maximum" == aName)               return $maximum;
    else                                        return $nothandled;
}

QString ObjectType::name(const int aInt)
{
    switch (aInt)
    {
    case $null:                         return "null";
    case $beginFace:                    return "$beginFace";
    case $beginFaceFrontal:             return "$beginFaceFrontal";
    case FaceFrontalHead:               return "FaceFrontalHead";
    case FaceFrontalFull:               return "FaceFrontalFull";
    case FaceFrontalTight:              return "FaceFrontalTight";
    case $endFaceFrontal:               return "$endFaceFrontal";
    case $beginFaceProfile:             return "$beginFaceProfile";
    case FaceProfileLeft:               return "FaceProfileLeft";
    case FaceProfileRight:              return "FaceProfileRight";
    case FaceProfileEither:             return "FaceProfileEither";
    case $endFaceProfile:               return "$endFaceProfile";
    case $endFace:                      return "$endFace";
    case $beginFacialFeature:           return "$beginFacialFeature";
    case $beginEye:                     return "$beginEye";
    case EyeLeft:                       return "EyeLeft";
    case EyeRight:                      return "EyeRight";
    case EyeNeither:                     return "EyeNeither";
    case EyeEither:                     return "EyeEither";
    case EyeBoth:                       return "EyeBoth";
    case $endEye:                       return "$endEye";
    case Nose:                          return "Nose";
    case Mouth:                         return "Mouth";
    case $endFacialFeature:             return "$endFacialFeature";
    case $beginBody:                    return "$beginBody";
    case BodyFull:                      return "BodyFull";
    case BodyUpper:                     return "BodyUpper";
    case BodyLower:                     return "BodyLower";
    case $endBody:                      return "$endBody";
    case $beginOther:                   return "$beginOther";
    case LicensePlate:                  return "LicensePlate";
    case VehicleGeneral:                return "VehicleGeneral";
    case CatFace:                       return "CatFace";
    case $invalid:                      return "$invalid";
    case $nothandled:                   return "$nothandled";
    case $maximum:                      return "$maximum";
    default: WARN << "ObjectType not handled:" << aInt;
                                        return "$nothandled";
    }
}

QString ObjectType::name(const ObjectType::Value aEnum)
{
    return name(int(aEnum));
}

bool ObjectType::isFaceFrontal() const
{
    bool result = true;
    result &= value() > $beginFaceFrontal;
    result &= value() < $endFaceFrontal;
//    TRACEQFI << $beginFaceFrontal << value() << $endFaceFrontal << result;
    return result;
}

bool ObjectType::isEye() const
{
    bool result = true;
    result &= value() > $beginEye;
    result &= value() < $endEye;
//    TRACEQFI << $beginEye << value() << $endEye << result;
    return result;
}

QChar ObjectType::eyeChar() const
{
    QChar result('!');
    switch (value())
    {
    case($beginEye):    result = '$'  ;         break;
    case(EyeLeft):      result = 'L'  ;         break;
    case(EyeRight):     result = 'R'  ;         break;
    case(EyeNeither):   result = 'N'  ;         break;
    case(EyeEither):    result = '@'  ;         break;
    case(EyeBoth):      result = '%'  ;         break;
    case($endEye):      result = '$'  ;         break;
    default:            /* NOTHING */           break;
    }
    return result;
}

/* ------------------------ debug -------------------------- */

QString ObjectType::toDebugString() const
{
    return QString("{ObjectType: %1 (%2)}").arg(name()).arg(value());
}

/* ------------------------ non-member -------------------------- */

bool operator == (const ObjectType &lhs, const ObjectType &rhs)
{
    return lhs.value() == rhs.value();
}

QDebug operator << (QDebug dbg, const ObjectType &ot)
{
    dbg << ot.toDebugString(); return dbg;
}
