#pragma once
#include "IfObject.h"

#include <QObject>

#include <QtGui/QImage>

#include <eirExe/Configuration.h>
#include <eirGui/QQImage.h>
#include <eirType/SCRect.h>
#include <eirType/SCRectList.h>
#include <eirType/Success.h>
#include <IfGeometry/FaceTypeRect.h>

#include "ObjectFinder.h"
#include "ObjectGrouper.h"
#include "ObjectResults.h"

class IFOBJECT_EXPORT ObjectDetector : public QObject
{
    Q_OBJECT
public:
    ObjectDetector(const ObjectType otype, QObject *parent = nullptr);
    ~ObjectDetector();
    bool initialize();

    ObjectFinder *finder() { return &mFinder; }
    ObjectGrouper *grouper() { return &mGrouper; }
    Success isLoadValid() const;

    ObjectType type() const { return cmType; }
    EyeROI eyeROI() const { return mEyeROI; }
    QQImage inputImage() const { return mInputImage; }
    ObjectResults results() const { return mQualityResults; }
    QQImage detectImage() const { return mDetectImage; }
    cvMat detectMat() const { return mDetectMat; }
    QQImage regionDetectImage() const { return mRegionDetectImage; }
    cvMat regionDetectMat() const { return mRegionDetectMat; }
    bool isCascadeLoaded() const { return mFinder.isLoaded(); }
    QStringList cascadeStatus() const  { return mFinder.statusStrings(); }
    bool isException() const { return exception().isNull(); }
    cvException exception() const { return mException; }
    cvException &exception() { return mException; }

public:

    bool loadCascade(const QFileInfo &xmlFileInfo);
    void clear();
    bool setImage(const QQImage &aInputImage);
    bool setImageFrom(ObjectDetector *pDetector);
    void setBaseConfigKey(const Configuration::Key groupKey) { mBaseConfigKey = groupKey; }
    void setEyeROI(const SCRect &faceRect) { mEyeROI = EyeROI(faceRect); }
    void setEyeROI(const EyeROI &aROI) { mEyeROI = aROI; }
    int detect(const Configuration &lconfig);
    int detectRegion(const SCRect regionRect, const Configuration &lconfig);

public: // static
    static ObjectDetector *detector(const ObjectType otype)
    { return smTypeDetectorMap.value(otype); }
    static bool contains(const ObjectType otype) { return smTypeDetectorMap.contains(otype); }
    static ObjectType::List types() { return smTypeDetectorMap.keys(); }

signals:
    void finderInitialized(const bool suceeded);
    void grouperInitialized(const bool suceeded);

private slots:

private:
    Configuration baseConfiguration() const;
    bool setRegionImage(const SCRect regionRect);
    int detect(const QImage qim, const SCRect offsetRect, const Configuration &lconfig);
    int detect(const cvMat cvm, const SCRect offsetRect, const Configuration &lconfig);

private:
    const ObjectType cmType;
    cvException mException;
    ObjectFinder mFinder;
    ObjectGrouper mGrouper;
    Configuration::Key mBaseConfigKey="/ObjectDetector";
    QQImage mInputImage;
    QQImage mDetectImage;
    cvMat mDetectMat;
    SCRect mRegionRect;
    QQImage mRegionDetectImage;
    cvMat mRegionDetectMat;
    EyeROI mEyeROI;
    DetectRectMap mDetectedRects;
    ObjectResults mGroupedResults;
    ObjectResults mQualityResults;
    static QMap<ObjectType, ObjectDetector *> smTypeDetectorMap;
};

