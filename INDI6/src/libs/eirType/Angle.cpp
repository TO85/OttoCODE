#include "Angle.h"

#include <cmath>

#include <eirXfr/Debug.h>

const qreal Angle::scmHalfCircleRadians = 3.14159265358979323846;
const qreal Angle::scmQuarterCircleRadians = scmHalfCircleRadians / 2.0;
const qreal Angle::scmEighthCircleRadians = scmHalfCircleRadians / 4.0;
const qreal Angle::scmFullCircleRadians = scmHalfCircleRadians * 2.0;


qreal Angle::screenArcTangentRadians() const
{
    qreal result = atan2(denominatorF(), numeratorF()) - scmQuarterCircleRadians;
    TRACEQFI << toString() << result;
    return result;
}

/* ---------------------- private ------------------------- */


/* ---------------------- static ------------------------- */

qreal Angle::degreesFromRadiansF(const qreal aRadians)
{
    return 360.0 * aRadians / halfCircle().toReal();
}
