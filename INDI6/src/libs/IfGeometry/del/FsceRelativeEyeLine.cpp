#include "FsceRelativeEyeLine.h"


FsceRelativeEyeLine::FsceRelativeEyeLine(const EyeLine el, const SCRect relface)
    : QQLineF(relface.relativePoint(el.left()), relface.relativePoint(el.right()))
    , mRelativeFace(relface)
{
    if (p1().x() > p2().x()) swap();
}
