#include "Resource1Loader.h"

Resource1Loader::Resource1Loader(QObject *parent)
    : QObject(parent)
{
    setObjectName("Resource1Loader");
    TRACEQFI << QOBJNAME(parent) << QOBJNAME(this);
}

DomStatus Resource1Loader::initialize(const QQDir &aBaseDir, const QQString &aMainFileName)
{
    TRACEQFI << aBaseDir.path() << aMainFileName;
    MUSTRTN(DomStatus());
}

DomStatus Resource1Loader::load(const int maxLayers)
{
    TRACEQFI << maxLayers;
    MUSTRTN(DomStatus());
}
