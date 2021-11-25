#pragma once
#include "IfData.h"

#include <QObject>

#include "ResourceData.h"
class DomFileManager;


class IFDATA_EXPORT ResourceManager : public QObject
{
    Q_OBJECT
public:
    explicit ResourceManager(QObject *parent = nullptr);

public:
    const DomStatus &status() const { return mStatus; }
    DomFileManager *fileManager() const { return mpFileManager; }
    ResourceData data() const { return mData; }

public:
    DomStatus loadResourses();

public slots:
    void configure(const QVariantMap &aConfig=QVariantMap()) {NEEDUSE(aConfig);NEEDDO(slot);}
    void initialize();

signals:

private:
    DomStatus &status() /*non-const*/ { return mStatus; }
    DomFileManager *fileManager() /*non-const*/ { return mpFileManager; }
    ResourceData &data() /*non-const*/ { return mData; }

private slots: // sub-functions
    void initializeBaseDir();
    void initializeFileSet();

private: // parsers
    DomStatus parseMainData(const QQDomElement &aMainDataDE);
    DomStatus parseInputBitMask(const QQDomElement &aMaskDE);


private:
    DomFileManager *mpFileManager=nullptr;
    DomStatus mStatus;
    ResourceData mData;

public: // static
    static QQString doctypeExpected() { return scmDocType; }
    static QQString dataTagExpected() { return scmDataTag; }
    static QQString inputBitMaskTag() { return scmInputBitMaskTag; }
    static QQString outputBitMaskTag() { return scmOutputBitMaskTag; }
    static QQString meanFaceTag() { return scmMeanFaceTag; }
    static QQString weightMaskTag() { return scmWeightMaskTag; }
    static QQString faceLayersTag() { return scmFaceLayersTag; }

private: // static
    static const QQString scmDocType;
    static const QQString scmDataTag;
    static const QQString scmInputBitMaskTag;
    static const QQString scmOutputBitMaskTag;
    static const QQString scmMeanFaceTag;
    static const QQString scmWeightMaskTag;
    static const QQString scmFaceLayersTag;
};

Q_GLOBAL_STATIC(ResourceManager, RMGR);
