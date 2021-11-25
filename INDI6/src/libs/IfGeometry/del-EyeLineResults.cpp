#include "del-EyeLineResults.h"

#include <eirXfr/Debug.h>


void EyeLineResults::append(const SCRectList detectedEyes)
{
    TRACEQFI << detectedEyes;

    MUSTDO(it);
}

void EyeLineResults::append(const EyeLine eline)
{
    TRACEQFI << eline;
    mItemList << Item(eline, faceRect());;
}

void EyeLineResults::append(const EyeLine::List elines)
{
    foreach (EyeLine eline, elines) append(eline);
}

/* ------------------------------ Item sub-class ---------------------------------- */


void EyeLineResults::Item::set(const EyeLine eline, const SCRect frect)
{
    TRACEQFI << eline << frect;
    mEyeLine = eline, mFaceRect = frect;
    mRelativeEyeLine = mFaceRect.relative(mEyeLine);
}

void EyeLineResults::Item::set(const SCRect leye, const SCRect reye, const SCRect frect)
{
    mLeftEyeRect = leye, mRightEyeRect = reye;
    set(EyeLine(leye.center(), reye.center()), frect);
}
