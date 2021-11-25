#include "FaceGeometry.h"

#include <eirType/eirType.h>
#include <eirXfr/Debug.h>

#include "FaceTypeRect.h"

QQPointF FaceGeometry::smLipCenterPt(0.0, +0.5); // Note: top down coordoinate system
QQPointF FaceGeometry::smChinCenterPt(0.0, +1.0);
QQPointF FaceGeometry::smLowerFacePt(0.0, +1.5);
QQPointF FaceGeometry::smNeckPt(0.0, +2.0);

FaceTypeRect FaceGeometry::ftRect(const ObjectType fotype)
{
    TRACEQFI << fotype;
    AEXPECT(fotype.isFaceFrontal());

    if (mFTRect.is(fotype))
        return mFTRect;

    switch (fotype.value())
    {
    case ObjectType::FaceFrontalHead:
        return FaceTypeRect(FaceTypeRect::Head, head());

    case ObjectType::FaceFrontalTight:
        return FaceTypeRect(FaceTypeRect::Tight, tightFace());

    default:
        WARN << "Unhandled FrontalFace ObjectType:" << fotype;
        /* Q_FALLTHROUGH */
    case ObjectType::FaceFrontalFull:
        return FaceTypeRect(FaceTypeRect::Full, fullFace());
    }
}

Rational FaceGeometry::expectedEyeWidth() const
{
    Rational eew(fullFace().width(), 5);
    TRACEQFI << fullFace() << eew;
    return eew;
}

void FaceGeometry::set(const EyeLine eline)
{
    TRACEQFI << eline;
    mEyeLine = eline;
    mEyeDistance = mEyeLine.length();
    mHalfEye = mEyeDistance / 2;
    mEyeCenter = mEyeLine.center();
    mFaceCenter = mEyeCenter + QQPoint(0, + mHalfEye);
    TRACE << "mEyeLine" << mEyeLine << "mEyeDistance" << mEyeDistance << "mHalfEye" << mHalfEye
          << "mEyeCenter" << mEyeCenter << "mFaceCenter" << mFaceCenter;
}

void FaceGeometry::set(const FaceTypeRect &ftrect)
{
    TRACEQFI << ftrect;
    EXPECTNOT(ftrect.isNull());
    mFTRect = ftrect;
    switch (ftrect.type())
    {
    case FaceTypeRect::Head:        setHeadRect(ftrect.rect());          break;
    case FaceTypeRect::Tight:       setTightFace(ftrect.rect());         break;
    default:                        WARN << "Invalid FaceRect::Type";
                                    Q_FALLTHROUGH();
    case FaceTypeRect::Full:        setFullFace(ftrect.rect());          break;
    }
}

void FaceGeometry::setTightFace(const SCRect tface)
{
    EXPECTNOT(tface.isNull());
    const unsigned eyeDistance = tface.width() / 2;
    const QQPoint eyeCenter = tface.center();
    const EyeLine eline(eyeCenter, eyeDistance);
    mFTRect = FaceTypeRect(FaceTypeRect::Tight, tface);
    TRACEQFI << tface << eyeDistance << eyeCenter << eline;
    set(eline);
}

void FaceGeometry::setFullFace(const SCRect fface)
{
    EXPECTNOT(fface.isNull());
    const unsigned eyeDistance = fface.width() / 3;
    const QQPoint eyeCenter = fface.center() - QQPoint(0, eyeDistance / 2);
    const EyeLine eline(eyeCenter, eyeDistance);
    mFTRect = FaceTypeRect(FaceTypeRect::Full, fface);
    TRACEQFI << fface << eyeDistance << eyeCenter << eline;
    set(eline);
}

void FaceGeometry::setHeadRect(const SCRect hrect)
{
    EXPECTNOT(hrect.isNull());
    const int eyeDistance = hrect.width() / 3;
    const QQPoint eyeCenter = hrect.center() + QQPoint(0, - eyeDistance / 2);
    const EyeLine eline(eyeCenter, eyeDistance);
    mFTRect = FaceTypeRect(FaceTypeRect::Head, hrect);
    TRACEQFI << hrect << eyeDistance << eyeCenter << eline;
    set(eline);
}

QStringList FaceGeometry::toDumpStrings() const
{
    return QStringList()
            << QString("%1=%2,%3~%4,%5").arg("eyeLine()").arg(eyeLine().leftPoint().x()).arg(eyeLine().leftPoint().y())
                                                         .arg(eyeLine().rightPoint().x()).arg(eyeLine().rightPoint().y())
            << QString("%1=%2").arg("eyeDistance()").arg(eyeDistance())
            << QString("%1=%2").arg("halfEye()").arg(halfEye())
            << QString("%1=%2,%3").arg("eyeCenter()").arg(eyeCenter().x()).arg(eyeCenter().y())
            << QString("%1=%2,%3").arg("faceCenter()").arg(faceCenter().x()).arg(faceCenter().y())
            << QString("%1=%2,%3").arg("lipCenter()").arg(lipCenter().x()).arg(lipCenter().y())
            << QString("%1=%2,%3").arg("chinCenter()").arg(chinCenter().x()).arg(chinCenter().y())
            << QString("%1=%2,%3").arg("lowerFace()").arg(lowerFace().x()).arg(lowerFace().y())
            << QString("%1=%2,%3").arg("neckPoint()").arg(neckPoint().x()).arg(neckPoint().y())
            << QString("%1=%2").arg("eyeBox()", eyeBox())
            << QString("%1=%2").arg("noseBox()", noseBox())
            << QString("%1=%2").arg("faceBox()", faceBox())
            << QString("%1=%2").arg("tightFace()", tightFace())
            << QString("%1=%2").arg("fullFace()", fullFace())
            << QString("%1=%2").arg("head()", head())
            << QString("%1=%2").arg("FaceTypeRect", mFTRect.toString());
            ;
}

// ------------------------------------- static  ---------------------------------------

EyeLine FaceGeometry::expectedEyeLine(const FaceTypeRect ftrect, const bool adjusted)
{
    TRACEQFI << ftrect;
    EXPECTNOT(ftrect.isNull());
    FaceGeometry fg(ftrect);
    EyeLine result = fg.eyeLine();
    if (adjusted) result.translate(ftrect.rect().topLeft().negated());
    TRACE << result << fg.toDumpStrings();
    return result;
}

/* ----------------------------------- non-member  --------------------------------------- */

QDebug operator << (QDebug dbg,  const FaceGeometry &fgeom)
{
    foreach (QString s, fgeom.toDumpStrings()) dbg << s; return dbg;
}

