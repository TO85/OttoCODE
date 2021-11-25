#include "EyeLineSet.h"

#include <QList>
#include <QMultiMap>
#include <QPoint>

#include <eirType/QQPoint.h>
#include <eirXfr/Debug.h>

#include "EyeLineConsistency.h"
#include "FsceRelativeEyeLine.h"

void EyeLineSet::set(const SCRectList eyeList, const SCRect faceRect)
{
    TRACEQFI << eyeList << faceRect;
    mRelativeFace = faceRect;

    QMultiMap<int, QQPoint> leftEyePointMap;
    foreach (SCRect eyerc, eyeList)
    {
        QQPoint ec = eyerc.center();
        leftEyePointMap.insert(ec.x(), ec);
    }
    TRACE << leftEyePointMap;

    QList<QQPoint> eyeCenterListByLeft = leftEyePointMap.values();
    mLineList.clear();
    while ( ! eyeCenterListByLeft.isEmpty())
    {
        QQPoint leftPoint = eyeCenterListByLeft.takeFirst();
        foreach (QQPoint rightPoint, eyeCenterListByLeft)
            mLineList.append(EyeLine(leftPoint, rightPoint));
    }
    TRACE << mLineList;
}

EyeLineSet::ConsistencyMap EyeLineSet::consitencyMap(const qreal distanceWeight,
                                                    const qreal slopeWeight) const
{
    TRACEQFI << distanceWeight << slopeWeight << mLineList;
    ConsistencyMap consistencyEyeLineMMap;
    foreach (EyeLine el, mLineList)
    {
        FsceRelativeEyeLine elf(el, mRelativeFace);
        EyeLineConsistency elc(elf);
        qreal ec = elc.consistency(distanceWeight, slopeWeight);
        consistencyEyeLineMMap.insert(ec, el);
    }
    TRACE << consistencyEyeLineMMap;
    return consistencyEyeLineMMap;
}



