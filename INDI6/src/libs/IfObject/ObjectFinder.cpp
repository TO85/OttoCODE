#include "ObjectFinder.h"

#include <eirOpenCV/cvCascade.h>
#include <eirType/Success.h>
#include <eirXfr/Debug.h>

#include "ObjectDetector.h"

ObjectFinder::ObjectFinder(ObjectDetector *pDetector, const ObjectType otype)
    : mpDetector(pDetector)
    , cmType(otype)
    , mCascade(otype)
{
    TRACEQFI << QOBJNAME(mpDetector) << cmType;
}

bool ObjectFinder::initialize()
{
    Success success;
    success.expect(mCascade.initialize());
    TRACEQFI << QOBJNAME(detector()) << cmType << success.toString() << mCascade.statusStrings();
    return success;
}

bool ObjectFinder::load(const QFileInfo &xmlFileInfo)
{
    bool result = false;
    DUMPVAL(xmlFileInfo);
    QString tFileName = xmlFileInfo.absoluteFilePath();
    DUMPVAL(tFileName);
    EXPECTNOT(tFileName.isEmpty());
    cvString cvFileName(tFileName);
    DUMPVAL(cvFileName);
    EXPECTNOT(cvFileName.isEmpty());
    result = mCascade.loadXml(cvFileName);
    TRACEQFI << xmlFileInfo << tFileName << cvFileName << cvFileName.size() << result;
    return result;
}

DetectRectMap ObjectFinder::detect(const cvMat &cvm, const Configuration config)
{
    DetectRectMap result;
    TRACEQFI << cvm << config.map();
    cvCascadeParms parms(config.map());
    DUMPVAL(parms);
    mCascade.findScoredRects(cvm, SCRect(cvm.size()), parms);
    result = mCascade.scoredResults();
    DUMPVAL(result);
    return result;
}

DetectRectMap ObjectFinder::detect(const SCRect regionRect, const cvMat &cvm, const Configuration config)
{
    MUSTDO(IT); MUSTUSE(regionRect); MUSTUSE(cvm); MUSTUSE(config); MUSTRTN(DetectRectMap());
}
