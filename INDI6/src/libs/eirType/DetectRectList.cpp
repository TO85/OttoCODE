#include "DetectRectList.h"

#include <eirXfr/Debug.h>



SCRectList DetectRectList::rectList() const
{
    SCRectList result;
    for (auto dr : it()) result << dr.rect();
    return result;
}

QVector<QRect> DetectRectList::toQRectVector()
{
    QVector<QRect> result;
    for (DetectRect dr : it()) result << dr.rect().toQRect();
    return result;
}
