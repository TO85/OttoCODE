#include "DetectRectMap.h"

#include <eirXfr/Debug.h>

DetectRectList DetectRectMap::list(const bool reversed) const
{
    DetectRectList result = values();
    if (reversed) result.reverse();
    return result;
}

DetectRect DetectRectMap::united() const
{
    DetectRect result(first());
    result.setScore(0);
    for (DetectRect dr : values())
    {
        result.unite(dr);
        result.score() += dr.score();
    }
    return result;

}

QRectVector DetectRectMap::toQRectVector() const
{
    QRectVector result;
    for (DetectRect dr : list())
        result << dr.rect().toQRect();
    return result;
}

void DetectRectMap::append(const DetectRectList &aDRectList)
{
    for (DetectRect dr : aDRectList) append(dr);
}

QQStringList DetectRectMap::toDebugStrings() const
{
    QQStringList result = QQStringList()
            << QQString("{DetectRectMap:>maxScore=%1, %2 items:")
               .arg(maxScore()).arg(list().size());
    for (DetectRect dr : list(true)) result << dr.toDebugString();
    result << "<DetectRectMap}";
    return result;
}
