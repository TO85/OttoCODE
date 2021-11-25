#pragma once
#include "IfManager.h"

#include <eirBase/VersionInfo.h>
#include <eirGui/QQColor.h>
#include <eirGui/QQImage.h>
#include <eirType/QQFileInfo.h>
#include <eirXml/DomStatus.h>
#include <IfData/ResourceManager.h>
class QQDir;

class ResourceValues;


class IFMANAGER_EXPORT INDIfaceManager : public QObject
{
    Q_OBJECT
public:
    explicit INDIfaceManager(QObject *parent = nullptr);

public: // getters
    const VersionInfo version() { return mVersionInfo; }
    DomStatus &status() { return mStatus; }
    ResourceManager *resource() { AEXPECTPTR(mpResourceManager); return mpResourceManager; }
    ResourceManager const *resource() const { AEXPECTPTR(mpResourceManager); return mpResourceManager; }
    ResourceValues resourceValues() const { return resource()->values(); }
    QQStringList resourceInfo() const { return resourceValues().info(); }
    const QQFileInfo &resourseFileInfo() const { return mResourseFileInfo; }

public: // commands
    void clearStatus() { mStatus.clear(); }
    bool initialize(const QQDir &aBaseDir, const int aMaxLayers);
    bool loadResources();

public: // processors

public slots:
    void configure() {;}

signals:
    void constructed();
    void configured();
    void initialized(const bool &success);
    void loadingResoources(const QDir &baseDir);
    void resourcesLoaded(const bool valid);

private: // setters

private:
    //ResourceSet *mpResourceSet=nullptr;
    ResourceManager *mpResourceManager=nullptr;
    VersionInfo mVersionInfo;
    QQFileInfo mResourseFileInfo;
    int mMaxLayers;
    DomStatus mStatus;
};

Q_GLOBAL_STATIC(INDIfaceManager, IfM);

extern EIRXML_EXPORT QDebug operator << (QDebug dbg, const INDIfaceManager &mgr);
