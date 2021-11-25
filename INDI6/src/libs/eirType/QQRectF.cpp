#include "QQRectF.h"

#include <eirXfr/Debug.h>

#include "QQPoint.h"
#include "QQSize.h"

QQRect QQRectF::toRect() const
{
    return QQRect(QQPoint(qRound(left()), qRound(top())),
                  QQSize(qRound(width()), qRound(height())));
}
