#include "cvCascade.h"

#include <QtDebug>

#include <eirType/DetectRect.h>
#include <eirType/DetectRectMap.h>
#include <eirType/ObjectType.h>
#include <eirType/SCRect.h>
#include <eirType/Success.h>
#include <eirXfr/Debug.h>

#include "cvQRect.h"
#include "cvQSize.h"
#include "cvRect.h"

bool cvCascade::initialize()
{
    TRACEQFI << type();
    EXPECT(type().isEye() || type().isFaceFrontal());
    if ( ! (type().isEye() ||  type().isFaceFrontal())) return false;
    unload();
    WEXPECT(mCascadeFileInfo.isNull());
    EXPECTNOT(isLoaded());
    return true;
}

bool cvCascade::loadXml(const QQFileInfo &xmlfi)
{
    TRACEQFI << xmlfi << type();
    EXPECT(type().isEye() || type().isFaceFrontal());
    EXPECT(xmlfi.notNull());
    bool result = false;
    if (xmlfi.notNull())
    {
        const cvString cvXmlFileName(mCascadeFileInfo.absoluteFilePath());
        result = loadXml(cvXmlFileName);
    }
    return result;
}

bool cvCascade::loadXml(const cvString &cvXmlFileName)
{
    TRACEQFI << cvXmlFileName << cvXmlFileName.size() << type();
    EXPECT(type().isEye() || type().isFaceFrontal());
    EXPECTNOT(cvXmlFileName.isEmpty());
    unload();
    mException.clear();
    if (cvXmlFileName.isEmpty()) return false;                          /* /====\ */
    try
    {
        mCascade.load(cvXmlFileName);
    }
    catch(const cv::Exception &cve)
    {
        cvException cvx(cve);
        mException = cvx;
        for (QString s : cvx.toDebugStrings()) ERROR << s;
    }
    if (isLoaded())
    {
        mCascadeFileInfo = QQFileInfo(cvXmlFileName);
        mCascadeName = mCascadeFileInfo.baseName();
        mCoreSize = cvQSize(mCascade.getOriginalWindowSize());
        TRACE << isLoaded() << mCascadeFileInfo << mCascadeName << mCoreSize;
        return true;
    }
    else
    {
        ERROR << "mCascade.load(cvXmlFileName) FAILED: " << cvXmlFileName;
        return false;
    }
}

void cvCascade::unload()
{
    TRACEQFI << mCascadeFileInfo << type();
//    mCascade.load(cvString());
  //  WEXPECT(notLoaded());
    mCascadeFileInfo.nullify();
    mCascadeName.clear();
    mCoreSize.empty();
    WEXPECT(mCascadeFileInfo.isNull());
}

void cvCascade::clear()
{
    TRACEQFI << cmType.name();
    mGreyInputMat.clear();
    mGreyInputImage = QImage();
    mIntStdVector.clear();
    mCvRectStdVector.clear();
    mScoredResults.clear();
}


bool cvCascade::notLoaded() const
{
    TRACEQFI << mCascade.empty();
    return mCascade.empty();
}

bool cvCascade::isLoaded() const
{
    TRACEQFI << mCascade.empty() << ! notLoaded();
    return ! notLoaded();
}

QStringList cvCascade::statusStrings() const
{
    QStringList qsl;
    if (mCascadeFileInfo.isNull())
    {
        qsl << QString("...%1 Classifier not specified").arg(typeName());
    }
    else if (notLoaded())
    {
        qsl << QString("...%1 Classifier not loaded").arg(typeName());
        qsl << "   From " + mCascadeFileInfo.absoluteFilePath();
    }
    else // (is Loaded)
    {
        qsl << QString("%1%2 %3 Classifier %4x%5 %6")
               .arg(/*%1*/isLoaded() ? "---" : "***",
                    /*%2*/mCascadeName,
                    /*%3*/cmType.name())
               .arg(/*%4*/mCoreSize.width())
               .arg(/*%5*/mCoreSize.height())
               .arg(/*%6*/isLoaded() ? "loaded" : "FAILED!");
        qsl << QString("   From %1").arg(mCascadeFileInfo.absoluteFilePath());
    }
    TRACEQFI << qsl;
    return qsl;
}

int cvCascade::findScoredRects(const cvMat &inputMat, const SCRect &detectRect, const Parameters &parms)
{
    TRACEQFI << inputMat << parms;
    mGreyInputMat = inputMat;
    AEXPECTNOT(mGreyInputMat.isNull());

    std::vector<int> intvect;
    std::vector<cv::Rect> rectvect;
    mCascade.detectMultiScale(mGreyInputMat(), rectvect, intvect, parms.factor(),
                              parms.neighbors(), parms.flags(),
                              parms.minSize(), parms.maxSize());

    DetectRectMap results = parseResults(detectRect, rectvect, intvect);
    DUMPVAL(results);
    mCvRectStdVector = rectvect;
    mIntStdVector = intvect;
    mScoredResults = results;
    return results.count();
}

int cvCascade::findRects(const cvMat &inputMat, const Parameters &parms)
{
    TRACEQFI << inputMat << parms;
    EXPECT(type().isEye() || type().isFaceFrontal());
    mGreyInputMat = inputMat;
    AEXPECTNOT(mGreyInputMat.isNull());

    std::vector<cv::Rect> rectvect;
    mCascade.detectMultiScale(mGreyInputMat(), rectvect, parms.factor(),
                              parms.neighbors(), parms.flags(),
                              parms.minSize(), parms.maxSize());

    DetectRectMap results = parseResults(SCRect(mGreyInputMat.size()), rectvect);
    DUMPVAL(results);
    mCvRectStdVector = rectvect;
    mScoredResults = results;
    return results.count();
}

DetectRectMap cvCascade::parseResults(const SCRect detectRect, std::vector<cv::Rect> rectVector, std::vector<int> intVector)
{
    TRACEQFI << detectRect << rectVector << intVector;
    EXPECT(type().isEye() || type().isFaceFrontal());
    DetectRectMap result;
    size_t nResults = rectVector.size();
    const bool intEmpty = 0 == intVector.size();
    int maxScore = -1;
    if ( ! intEmpty)
    {
        EXPECTEQ(nResults, intVector.size());
        nResults = qMin(nResults, intVector.size());
    }

    for (unsigned ix = 0; ix < nResults; ++ix)
    {
        const cv::Rect ocvrc = rectVector[ix];
        const cvRect cvrc(ocvrc);
        const QQRect qqrc = cvrc.toRect();
        const QQPoint tl = qqrc.topLeft() + detectRect.topLeft();
        const SCRect scrc(tl, qqrc.size());
        const int score = intEmpty ? -1 : intVector[ix];
        result << DetectRect(type(), scrc, score);
        if (score > maxScore) maxScore = score;
    }
    result.setMaxScore(maxScore);
    DUMPVAL(result.toDebugStrings())
    return result;
}

/* --------------------------- static --------------------------- */

QString cvCascade::Parameters::toDebugString(const cvCascade::Parameters &parms)
{
    return QString("factor=%1, neighbors=%2, flags=%3, %4x%5~%6x%7")
            .arg(parms.factor()).arg(parms.neighbors()).arg(parms.flags())
            .arg(parms.minSize().width).arg(parms.minSize().height)
            .arg(parms.maxSize().width).arg(parms.maxSize().height);
}

/* --------------------------- non-member --------------------------- */

QDebug operator<<(QDebug dbg, const cvCascade::Parameters &parms)
{
    dbg << parms.toDebugString(); return dbg;
}
