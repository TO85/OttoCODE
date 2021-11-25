#include "ResourceImages.h"

#include <eirXfr/Debug.h>

#include "ResourceValues.h"

ResourceImages::ResourceImages(const ResourceValues &aValues)
    : cmValues(aValues)
{
    TRACEQFI << aValues.info();
}
