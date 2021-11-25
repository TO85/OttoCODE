#pragma once
#include "INDIface.h"

#include <eirBase/VersionInfo.h>
#include <eirGui/QQColor.h>
#include <eirGui/QQImage.h>
#include <eirType/QQFileInfo.h>
#include <eirXml/DomStatus.h>
#include <IfData/ResourceManager.h>
class QQDir;


class INDIFACE_EXPORT INDIfaceManager : public QObject
{
    Q_OBJECT
public:
    explicit INDIfaceManager(QObject *parent = nullptr);

public: // getters
    const VersionInfo versionInfo() { return mVersionInfo; }
    DomStatus &status() { return mStatus; }
    const QQFileInfo &resourseFileInfo() const { return mResourseFileInfo; }
    ResourceManager *resource() { return mpResourceManager; }
    ResourceSet *dataSet() { return resource()->dataSet(); }

public slots: // commands
    void clearStatus() { mStatus.clear(); }
    DomStatus initialize(const QQDir &aBaseDir, const QQString &aMainFileName, const int aMaxLayers);
    bool loadResources();

public: // processors
#ifndef EIRC_NO_INDI1DATA
    QQImage maskNormalImage(const QQImage aNormImage,
                            const QQColor maskColor=Qt::gray,
                            const bool input=false);
#endif

public slots:
    void configure() {;}

signals:
    void constructed();
    void configured();
    void initialized();
    void loadingResoources(const QQFileInfo &baseFileInfo);
    void resourcesLoaded(const bool valid);

private: // setters

private:
    ResourceManager *mpResourceManager=nullptr;
    VersionInfo mVersionInfo;
    QQFileInfo mResourseFileInfo;
    int mMaxLayers;
    DomStatus mStatus;
};

Q_GLOBAL_STATIC(INDIfaceManager, IfM);

extern EIRXML_EXPORT QDebug operator << (QDebug dbg, const INDIfaceManager &mgr);
