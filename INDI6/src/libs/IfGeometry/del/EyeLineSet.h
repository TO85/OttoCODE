#pragma once
#include "IfGeometry.h"

#include <QMultiMap>

#include <eirType/QQPoint.cpp>
#include <eirType/SCRect.h>
#include <eirType/SCRectList.h>

#include "EyeLine.h"

class IFGEOMETRY_EXPORT EyeLineSet
{
public:
    typedef QMultiMap<qreal, EyeLine> ConsistencyMap;

public:
    EyeLineSet() {;}
    EyeLineSet(const SCRectList eyeList, const SCRect faceRect) { set(eyeList, faceRect); }
    void set(const SCRectList eyeList, const SCRect faceRect);
    ConsistencyMap consitencyMap(const qreal distanceWeight=1.0,
                                            const qreal slopeWeight=1.0) const;

private:
    EyeLine::List mLineList;
    SCRect mRelativeFace;
};

