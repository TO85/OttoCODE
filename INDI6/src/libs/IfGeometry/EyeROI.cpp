#include "EyeROI.h"

#include <eirType/ObjectType.h>
#include <eirXfr/Debug.h>

SCRectF EyeROI::smLeyeRectF(QQSizeF(0.5, 0.5), QQPointF(-0.25, -0.125));
SCRectF EyeROI::smReyeRectF(QQSizeF(0.5, 0.5), QQPointF(+0.25, -0.125));

ObjectType EyeROI::classify(const DetectRect &eyeDR, const QQPoint offset) const
{
    EXPECTEQ(ObjectType::EyeEither, eyeDR.type().value());
    ObjectType result = ObjectType::$null;
    SCRect eyeRect = eyeDR.rect();
    QQPoint eyeCenterPt = eyeRect.center() + offset;
    TRACEQFI << eyeDR << offset << eyeCenterPt;
    bool leftContains = left().contains(eyeCenterPt);
    bool rightContains = right().contains(eyeCenterPt);
    TRACE << left() << "contains" << eyeCenterPt << leftContains;
    TRACE << right() << "contains" << eyeCenterPt << rightContains;

    if (leftContains && rightContains)
        result = byDistance(eyeCenterPt);
    else if (leftContains /* && ! rightContains */ )
        result = ObjectType::EyeLeft;
    else if (rightContains /* && ! leftContains */ )
        result = ObjectType::EyeRight;
    else /* ! leftContains && ! rightContains */
        result = ObjectType::EyeNeither;

    TRACEQFI << eyeDR << offset << toDebugString() << eyeCenterPt
             << leftContains << rightContains << result;
    return result;
}

EyeLine EyeROI::parseEyeLine(const DetectRectList &aEyeDetectList)
{
    TRACEQFI << aEyeDetectList; // << toDebugString();
    EyeLine result;

    QQPoint::List ignoredList;
    for (DetectRect eyeDR : aEyeDetectList)
    {
        const ObjectType eyeOType = eyeDR.type();
        QQPoint eyeCenter = eyeDR.rect().center();
        TRACE << eyeOType << eyeCenter;
        AEXPECT(eyeOType.isEye());
        if (false)
        {
            ;
        }
        else if (ObjectType::EyeLeft == eyeOType)
        {
            if (result.isLeftNull())
            {
                result.setLeft(eyeCenter);
            }
        }
        else if (ObjectType::EyeRight == eyeOType)
        {
            if (result.isRightNull())
            {
                result.setRight(eyeCenter);
            }
        }
        else if (ObjectType::EyeNeither == eyeOType)
        {
            ignoredList.append(eyeCenter);
        }
        else
        {
            WARN << "Unhandled Eye Type" << eyeOType;
        }
        if ( ! result.isEitherNull())
            break;
    }
    // WANTDO (something with ignoredList);
    if (result.isEitherNull()) result.nullify();
    DUMPVAL(result);
    return result;
}

void EyeROI::set(const SCRect &frect)
{
    mFaceRect = frect;
    SCRect leye  = smLeyeRectF.toRect(frect);
    SCRect reye  = smReyeRectF.toRect(frect);
    set(leye, reye);
}

QVariant EyeROI::toVariant() const
{
    QVariant result;
    result.setValue(it());
    return result;
}

QString EyeROI::toDebugString() const
{
    return QString("{EyeROI> Left=%1 Right=%2 Distance=%3 <EyeROI}")
            .arg(left(), right()).arg(distance());
}


/* ------------------------ private ---------------------- */

ObjectType EyeROI::byDistance(const QQPoint pt) const
{
    ObjectType result = ObjectType::$null;
    qreal lDistance = left().center().distanceF(pt);
    qreal rDistance = right().center().distanceF(pt);
    qreal dDistance = lDistance - rDistance;
    if (dDistance < (qreal(distance()) / 5.0))
        result = ObjectType::EyeNeither;
    else if (lDistance < rDistance)
        result = ObjectType::EyeLeft;
    else /* rDistance < lDistance */
        result = ObjectType::EyeRight;
    TRACEQFI << pt << toDebugString() << result.name() << lDistance << rDistance << dDistance;
    return result;
}


/* ----------------------------------- non-member  --------------------------------------- */

QDebug operator << (QDebug dbg,  const EyeROI &roi)
{
    dbg << roi.toDebugString(); return dbg;
}
