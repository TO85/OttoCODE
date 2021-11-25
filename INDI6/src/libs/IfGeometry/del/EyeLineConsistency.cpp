#include "EyeLineConsistency.h"

#include <eirXfr/Debug.h>

EyeLineConsistency::EyeLineConsistency(const FsceRelativeEyeLine elf)
    : mLineFace(elf)
    , mDistance(elf.length() * elf.faceWidth())
    , mSlope(elf.rise() * elf.faceWidth(), elf.run() * elf.faceWidth())
{
    TRACEQFI << elf;
}

qreal EyeLineConsistency::eyeWidthFactor() const
{
    if (0 == mLineFace.faceWidth()) return 2000.0;
    qreal eyeDistance = mLineFace.length();
    qreal eyeFaceFactor = eyeDistance / qreal(mLineFace.faceWidth());
    qreal halfFactor = qAbs(eyeFaceFactor - 0.5);
    qreal halfSquared = halfFactor * halfFactor;
    TRACEQFI << mLineFace << "eyeDistance" << eyeDistance << "eyeFaceFactor"
             << eyeFaceFactor << "halfFactor" << halfFactor
             << "halfSquared" << halfSquared << "quality" << quality(halfSquared);
    return halfSquared;
}

qreal EyeLineConsistency::eyeSlopeFactor() const
{
    if ( ! slope().isValid()) return 2000.0;
    qreal aslope = slope().toAbsolute();
    TRACEQFI << mLineFace << aslope << aslope * 6.0 << quality(aslope * 6.0);
    return aslope * 6.0;
}

qreal EyeLineConsistency::weighted(const qreal widthWeight, const qreal slopeWeight) const
{
    qreal ewf = eyeWidthFactor();
    qreal esf = eyeSlopeFactor();
    qreal r = (ewf * widthWeight + esf * slopeWeight) / (widthWeight + slopeWeight);
    TRACEQFI << "dist" << r << "qual" << quality(r) << ewf << esf << widthWeight << slopeWeight;
    return r;
}

unsigned EyeLineConsistency::consistency(const qreal widthWeight, const qreal slopeWeight) const
{
    return quality(weighted(widthWeight, slopeWeight));
}
