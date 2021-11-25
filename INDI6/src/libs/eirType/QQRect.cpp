#include "QQRect.h"

#include <eirXfr/Debug.h>

QQString QQRect::toDebugString() const
{
    return QQString("{QQRect: L%1,T%2~R%3,B%4 @CX%5,CY%6 W%7xH%8}")
            .arg(left()).arg(top()).arg(right()).arg(bottom())
            .arg(center().x()).arg(center().y()).arg(width()).arg(height());
}

/* ------------------------- non-member ------------------------ */

QDebug operator << (QDebug dbg, const QQRect qqrc)
{
    dbg << qqrc.toDebugString(); return dbg;
}

