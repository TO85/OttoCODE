#include "ObjectRegion.h"

#include <QtCore/QString>

#include <eirXfr/Debug.h>

ObjectRegion::ObjectRegion(const MultiName &name, const SCRect rect)
    : cmRegionName(name)
    , cmRegionRect(rect)
{
    TRACEQFI << cmRegionName() << cmRegionRect;
}

ObjectRegion::ObjectRegion(const SCRect rect)
    : cmRegionName(QString("X%1Y%2W%3").arg(rect.center().x()).arg(rect.center().y()).arg(rect.width()))
    , cmRegionRect(rect)
{
    TRACEQFI << cmRegionName() << cmRegionRect;
}
