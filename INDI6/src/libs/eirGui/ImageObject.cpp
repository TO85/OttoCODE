#include "ImageObject.h"

#include <eirXfr/Debug.h>

ImageObject::ImageObject(QObject *parent)
    : QObject(parent)
{
    setObjectName("ImageObject:nullImage");
    TRACEQFI << QOBJNAME(this) << QOBJNAME(parent);
}

ImageObject::ImageObject(const QQImage aImage, QObject *parent)
    : QObject(parent)
    , QQImage(aImage)
{
    setObjectName("ImageObject:"+name());
    TRACEQFI << aImage << QOBJNAME(this) << QOBJNAME(parent);
}
