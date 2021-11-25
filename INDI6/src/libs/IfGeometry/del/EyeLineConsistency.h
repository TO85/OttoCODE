#pragma once
#include "IfGeometry.h"

#include <eirType/Rational.h>

#include "FsceRelativeEyeLine.h"


class EyeLineConsistency
{
public:
    EyeLineConsistency() {;}
    EyeLineConsistency(const FsceRelativeEyeLine elf);
    Rational slope() const { return mSlope; }
    qreal eyeWidthFactor() const;
    qreal eyeSlopeFactor() const;
    qreal weighted(const qreal widthWeight=1.0, const qreal slopeWeight=1.0) const;
    unsigned consistency(const qreal widthWeight=1.0, const qreal slopeWeight=1.0) const;

private:
    FsceRelativeEyeLine mLineFace;
    qreal mDistance = qQNaN();
    Rational mSlope = qQNaN();
    qreal mDistanceFactor = qQNaN();
    qreal mSlopeFactor = qQNaN();
};

