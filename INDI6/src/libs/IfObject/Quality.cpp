#include "Quality.h"

#include <eirType/QQPoint.h>
#include <eirXfr/Debug.h>
#include <IfGeometry/EyeLine.h>

#include "ObjectResults.h"

void Quality::setDistance(const qreal aDistance)
{
    mDistance = aDistance;
    mQuality = qualityForDistance(mDistance);
}

void Quality::setQuality(const unsigned aQuality)
{
    mQuality = aQuality;
    mDistance = distanceForQuality(mQuality);
}

unsigned Quality::qualityForDistance(const qreal distance)
{
    unsigned Q = 0;
    if (distance < 0.0)             Q = 1;
    else if (distance <= 1.0)       Q = 500 + 500 * (1.0 - distance);
    else if (distance <= 2.5)       Q = 100 + 250 * (2.5 - distance);
    else if (distance <= 5.0)       Q =   3 +  97 * (5.0 - distance);
    else                            Q = 2;
    TRACEQFI << distance << Q;
    return qBound(1U, Q, 999U);
}

qreal Quality::distanceForQuality(const unsigned aMille)
{
    WANTDO(it); WANTUSE(aMille); WANTRTN(0.0);
}

