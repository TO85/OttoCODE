#include "ObjectDetector.h"

#include <eirExe/AppSettings.h>
#include <eirOpenCV/cvMat.h>
#include <eirOpenCV/cvMatType.h>
#include <eirType/Success.h>
#include <eirXfr/Debug.h>

QMap<ObjectType, ObjectDetector *> ObjectDetector::smTypeDetectorMap;

ObjectDetector::ObjectDetector(const ObjectType otype, QObject *parent)
    : QObject(parent)
    , cmType(otype)
    , mFinder(this, type())
    , mGrouper(this, type())
{
    setObjectName("ObjectDetector:"+type().name());
    TRACEQFI << QOBJNAME(parent) << QOBJNAME(this) << type();
    if (contains(type()))
        detector(otype)->deleteLater();
    smTypeDetectorMap.insert(type(), this);
}

ObjectDetector::~ObjectDetector()
{
    TRACEQFI << QOBJNAME(this) << contains(type());
    if (contains(type()))
        detector(type())->deleteLater();
    smTypeDetectorMap.remove(type());
}

bool ObjectDetector::initialize()
{
    TRACEQFI << QOBJNAME(this);
    bool finderOK  = mFinder.initialize();
    bool grouperOK = mGrouper.initialize();
    EXPECT(finderOK);
    EXPECT(grouperOK);
    EMIT(finderInitialized(finderOK));
    EMIT(grouperInitialized(grouperOK));
    return finderOK && grouperOK;
}

Success ObjectDetector::isLoadValid() const
{
    Success success;
    success.expect(isCascadeLoaded());
    success.expect(isException());
    success.expect(cmType.isFaceFrontal() || cmType.isEye());
    success.validate();
    return success;
}

bool ObjectDetector::loadCascade(const QFileInfo &xmlFileInfo)
{
    TRACEQFI << QOBJNAME(this) << xmlFileInfo;
    exception().clear();
    bool result = mFinder.load(xmlFileInfo);
    if (finder()->cascade()->isException())
            exception() = finder()->cascade()->exception();
    return result && exception().notNull();
}

void ObjectDetector::clear()
{
    TRACEFN;
    mFinder.clear();
    mGrouper.clear();
    mInputImage.clear();
    mDetectImage.clear();
    mDetectMat.clear();
    mDetectedRects.clear();
    mGroupedResults.clear();
    mQualityResults.clear();
}

bool ObjectDetector::setImage(const QQImage &aInputImage)
{
    TRACEQFI << type() << aInputImage;
    EXPECT(type().isEye() || type().isFaceFrontal());
    clear();
    WEXPECT(mGroupedResults.isEmpty());
    WEXPECT(mQualityResults.isEmpty());
    mGroupedResults.clear();
    mQualityResults.clear();

    AEXPECTNOT(aInputImage.isNull());
    mInputImage.set(aInputImage.convertedToColor());
    AEXPECTNOT(mInputImage.isNull());
    mDetectImage.set(mInputImage.convertedToGrey());
    DUMPVAL(mDetectImage);
    AEXPECTNOT(mDetectImage.isNull());
    mDetectMat.set(mDetectImage, cvMatType::Grey8());
    DUMPVAL(mDetectMat);
    AEXPECT(mDetectMat.isValid());
    return ! mInputImage.isNull() && ! mDetectImage.isNull() && mDetectMat.isValid();
}

bool ObjectDetector::setImageFrom(ObjectDetector *pDetector)
{
    TRACEQFI << type() << QOBJNAME(pDetector);
    EXPECT(type().isEye() || type().isFaceFrontal());
    mInputImage = pDetector->inputImage();
    AEXPECTNOT(mInputImage.isNull());
    mDetectImage = pDetector->detectImage();
    AEXPECTNOT(mDetectImage.isNull());
    mDetectMat = pDetector->detectMat();
    AEXPECT(mDetectMat.isValid());
    WEXPECT(mGroupedResults.isEmpty());
    WEXPECT(mQualityResults.isEmpty());
    mGroupedResults.clear();
    mQualityResults.clear();
    return ! mInputImage.isNull() && ! mDetectImage.isNull() && mDetectMat.isValid();
}

int ObjectDetector::detect(const Configuration &config)
{
    TRACEQFI << config.map() << inputImage();
    return detect(detectMat(), SCRect(detectMat().size()), config);
}

int ObjectDetector::detectRegion(const SCRect regionRect, const Configuration &config)
{
    AEXPECTNOT(inputImage().isNull());
    mRegionDetectImage = inputImage().copy(regionRect.toQRect());
    mRegionDetectMat.set(mRegionDetectImage, cvMatType::Grey8());
    TRACEQFI << inputImage() << regionRect << config.map() << mRegionDetectImage << mRegionDetectMat;
    AEXPECTEQ(regionRect.size(), mRegionDetectImage.size());
    AEXPECTEQ(regionRect.size(), mRegionDetectMat.size());
    return detect(mRegionDetectMat, regionRect, config);
}

/* ------------------------- private ------------------------ */

Configuration ObjectDetector::baseConfiguration() const
{
    Configuration result(STG->configuration(mBaseConfigKey));
    TRACEQFI << result.map();
    return result;
}

int ObjectDetector::detect(const QImage qim, const SCRect offsetRect, const Configuration &config)
{
    cvMat inMat(qim, cvMatType::Grey8());
    TRACEQFI << qim << offsetRect << config.map() << inMat;
    return detect(inMat, offsetRect, config);
}

int ObjectDetector::detect(const cvMat cvm, const SCRect offsetRect, const Configuration &lconfig)
{
    TRACEQFI << cvm << offsetRect << lconfig.map() << type();
    EXPECT(type().isEye() || type().isFaceFrontal());
    Configuration fconfig = baseConfiguration().extract("Finder", lconfig);
    Configuration gconfig = baseConfiguration().extract("Grouper", lconfig);
    WEXPECT(mGroupedResults.isEmpty());
    WEXPECT(mQualityResults.isEmpty());
    mGroupedResults.clear();
    mQualityResults.clear();

    mDetectedRects = mFinder.detect(cvm, fconfig);
    DUMPVAL(mDetectedRects);
    TODO(gconfig);
    grouper()->setDetectedRects(mDetectedRects);

    if (mDetectedRects.notEmpty())
    {
        if (type().isEye()) grouper()->assignEyeTypes(offsetRect.topLeft());
        else grouper()->setTypedRects(grouper()->detectedRects());
        grouper()->groupResults();
        mGroupedResults = grouper()->groupedResults();
        grouper()->assignQuality();
        mQualityResults = grouper()->qualityResults();
        DUMPVAL(mQualityResults);
    }
    return mQualityResults.itemCount();
}

/* ----------------------- private static --------------------------- */



