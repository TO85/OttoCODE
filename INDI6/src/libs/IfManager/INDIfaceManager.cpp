#include "INDIfaceManager.h"

#include <eirGui/QQColor.h>
#include <eirType/QQBitArray.h>
#include <eirXfr/Debug.h>
#include <eirXml/DomFile.h>
#include <eirXml/QQDomDocument.h>
#include <eirXml/QQDomElement.h>

#include "../version.h"

#include <IfData/ResourceManager.h>
#include <IfData/ResourceValues.h>

INDIfaceManager::INDIfaceManager(QObject *parent)
    : QObject(parent)
    , mpResourceManager(new ResourceManager(this))
    , mVersionInfo(VER_STRING, VER_MAJOR, VER_MINOR, VER_MICRO, VER_MINI)
{
    AEXPECTPTR(mpResourceManager);
    setObjectName("INDIfaceManager");
    TRACEQFI << QOBJNAME(parent) << QOBJNAME(this);
    EMIT(constructed());
}

bool INDIfaceManager::initialize(const QQDir &aBaseDir, const int aMaxLayers)
{
    TRACEQFI << aBaseDir.toDebugString() << aMaxLayers;
    DomStatus tStatus;
    // TODO: AEXPECTQOP(ResourceManager, mpResourceManager);
    resource()->setBaseDir(aBaseDir);
    resource()->setMaxLoadLayers(aMaxLayers);
    resource()->addAllFiles();
    tStatus.set(resource()->fileInfo(resource()->key(0)));
    for (int ix = 0; ix < resource()->fileCount(); ++ix)
    {
        QQFileInfo tResFileInfo = resource()->fileInfo(resource()->key(ix));
        tStatus.expect("Resource File Exists(%1): "+tResFileInfo.absoluteFilePath(),
                       tResFileInfo.exists(), QtInfoMsg, QtCriticalMsg);
        tStatus.expect("Resource File Readable(%1): "+tResFileInfo.absoluteFilePath(),
                       tResFileInfo.isReadable(), QtInfoMsg, QtCriticalMsg);
    }
    tStatus.dump();
    EXPECTNOT(tStatus.isError());
    EMIT(initialized(tStatus));
    status().append(tStatus);
    return tStatus.isError();
}

bool INDIfaceManager::loadResources()
{
    TRACEQFI << mResourseFileInfo;
    EMIT(loadingResoources(resource()->baseDir()));
    bool success = resource()->process();
    EMIT(resourcesLoaded(success));
    return success;
}

/* ----------------------- private ----------------------- */

