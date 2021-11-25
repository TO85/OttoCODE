#include "ImageFactory.h"

#include <eirXfr/Debug.h>

ImageFactory::ImageFactory(QObject *parent)
    : QObject(parent)
{
    setObjectName("ImageFactory");
    TRACEQFI << QOBJNAME(parent) << QOBJNAME(this);
}

ImageFactory::ImageFactory(const ResourceValues aValues, QObject *parent)
    : QObject(parent)
    , mValues(aValues)
{
    setObjectName("ImageFactory");
    TRACEQFI << QOBJNAME(parent) << QOBJNAME(this) << mValues.info();
}

void ImageFactory::set(const ResourceValues &aValues)
{
    TRACEQFI << aValues.info();
    mValues = aValues;
}
