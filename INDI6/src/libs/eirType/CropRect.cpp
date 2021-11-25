#include "CropRect.h"

#include <eirXfr/Debug.h>

CropRect::CropRect(const QRect inrc, const unsigned clip)
{
    QRect rc;
    unsigned clipMask = powerOfTwo(clip) - 1;
    QSize sz(inrc.width() & clipMask, inrc.height() & clipMask);
    QPoint ofpt(inrc.left() + ((inrc.width() - sz.width()) / 2),
                inrc.right() + ((inrc.height() - sz.height()) / 2));
    rc = QRect(ofpt, sz);
    TRACEQFI << inrc << clip << "-->" << rc;
}
