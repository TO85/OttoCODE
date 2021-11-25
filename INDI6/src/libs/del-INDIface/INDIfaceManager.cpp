#include "INDIfaceManager.h"

#include <eirGui/QQColor.h>
#include <eirType/QQBitArray.h>
#include <eirXfr/Debug.h>
#include <eirXml/DomFile.h>
#include <eirXml/QQDomDocument.h>
#include <eirXml/QQDomElement.h>

#include "../version.h"


INDIfaceManager::INDIfaceManager(QObject *parent)
    : QObject(parent)
    , mVersionInfo(VER_STRING, VER_MAJOR, VER_MINOR, VER_MICRO, VER_MINI)
{
    setObjectName("INDIfaceManager");
    TRACEQFI << QOBJNAME(parent) << QOBJNAME(this);
    EMIT(constructed());
}

DomStatus INDIfaceManager::initialize(const QQDir &aBaseDir, const QQString &aMainFileName)
{
    DomStatus tStatus;
    QQFileInfo tResFileInfo(aBaseDir, aMainFileName);
    mResourseFileInfo = tResFileInfo;
    tStatus.expect("Resource File Exists(%1)", mResourseFileInfo.exists(), QtInfoMsg, QtCriticalMsg);
    tStatus.expect("Resource File Readable(%1)", mResourseFileInfo.isReadable(), QtInfoMsg, QtCriticalMsg);
    tStatus.dump();
    status().append(tStatus);
    return tStatus;
}

bool INDIfaceManager::loadResources(const QQDir &aBaseDir, const int aMaxLayers)
{
    TRACEQFI << aBaseDir << aMaxLayers;
    Success success;
    mpResourceManager = new ResourceManager(this);
    // TODO: AEXPECTQOP(ResourceManager, mpResourceManager);
    AEXPECTPTR(mpResourceManager);
    resource()->setBaseDir(aBaseDir);
    resource()->setMaxLoadLayers(aMaxLayers);
    mResourseFileInfo = resource()->baseFileInfo();
    EMIT(loadingResoources(mResourseFileInfo));
    success.expect(resource()->process());
    success.expect(resource()->isLoadValid());
    EMIT(resourcesLoaded(success));
    return success;
}
/*
DomStatus INDIfaceManager::loadResources(const int aMaxLayers)
{
    TRACEQFI << QOBJNAME(this);
    DomStatus tStatus;
    mMaxLayers = aMaxLayers;
    tStatus.dump();
    status().append(tStatus);
    return tStatus;
}
*/
/* ----------------------- private ----------------------- */

