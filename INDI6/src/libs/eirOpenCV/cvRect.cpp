#include "cvRect.h"

#include <QtDebug>

#include <eirXfr/Debug.h>

QString cvRect::toString() const
{
    return QString("cv::Rect sz=%1Wx%2H tl=%3L,%4T c=%5X,%6Y").arg(size().width).arg(size().height)
            .arg(topLeft().x()).arg(topLeft().y()).arg(center().x()).arg(center().y());
}

// ------------------------------------- non-member  ---------------------------------------

QDebug operator<<(QDebug dbg, const cvRect &cvrc)
{
    dbg << cvrc.toString();
    return dbg;
}

//extern EIROPENCV_EXPORT QDebug operator<<(QDebug dbg, const cvRect &cvrc);
