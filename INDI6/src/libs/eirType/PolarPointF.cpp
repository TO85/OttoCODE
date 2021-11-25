#include "PolarPointF.h"

#include <cmath>

#include <eirXfr/Debug.h>

QQPointF PolarPointF::toPointF() const
{
    return QQPointF(radius() * sin(angle().screenArcTangentRadians()),
                    radius() * cos(angle().screenArcTangentRadians()));
}

void PolarPointF::set(const QQPointF aCartesianPointF)
{
    mRadius = aCartesianPointF.distance();
    mAngle.set(aCartesianPointF.y(), aCartesianPointF.x());
}
