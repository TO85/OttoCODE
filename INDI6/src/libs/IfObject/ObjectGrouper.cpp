#include "ObjectGrouper.h"

#include <QMultiMap>

#include <eirType/PerMille.h>
#include <eirType/SCRect.h>
#include <eirType/SCRectF.h>
#include <eirType/Success.h>
#include <eirXfr/Debug.h>
#include <IfGeometry/EyeLine.h>

#include "ObjectDetector.h"
#include "ObjectFinder.h"
#include "QualityComponentKeys.h"

ObjectGrouper::ObjectGrouper(ObjectDetector *pDetector, const ObjectType otype)
    : mpDetector(pDetector)
    , cmType(otype)
{
    TRACEFN;
    AEXPECTEQ(detector()->type().value(), type().value());
}

bool ObjectGrouper::initialize()
{
    TRACEQFI << type();
    Success faceSuccess, eyeSuccess;
    // WANTDO: Weights from Config
    {
    /* Score, AreaFraction, WidthRatio */
    mFrontalWA.clear();
    faceSuccess.expect(mFrontalWA.appendWeight(FrontalScore,        "FrontalScore",     5.0));
    faceSuccess.expect(mFrontalWA.appendWeight(FrontalAreaFactor,   "FScore",           2.0));
    faceSuccess.expect(mFrontalWA.appendWeight(FrontalWidthRatio,   "FWidthRatio",      1.0));
    faceSuccess.validate();
    AEXPECT(faceSuccess);
    }
    {
    /* Score, ExpectedEyeLine, EyeROI, LEyeROI, REyeROI, EyeLineRatio, EyeFaceRatio */
    mEyeWA.clear();
    eyeSuccess.expect(mEyeWA.appendWeight(EyeScore, "EyeScore", 10.0));
    eyeSuccess.expect(mEyeWA.appendWeight(EyeExEL,  "EyeExEL",  5.0));
    eyeSuccess.expect(mEyeWA.appendWeight(EyeROI,  "EyeROI",    2.0));
    eyeSuccess.validate();
    AEXPECT(eyeSuccess);
    }
    return faceSuccess && eyeSuccess;
}

void ObjectGrouper::assignEyeTypes(const QQPoint offset)
{
    AEXPECTEQ(detector()->type().value(), type().value());
    AEXPECT(type().isEye());

    DetectRectMap result;
    result.setMaxScore(mDetectedRects.maxScore());
    for (DetectRect eyeDR : qAsConst(mDetectedRects))
    {
        ObjectType eyeType = detector()->eyeROI().classify(eyeDR, offset);
        eyeDR.setType(eyeType);
        result.append(eyeDR);
    }
    mTypedRects = result;
    DUMPVAL(mTypedRects);
}

void ObjectGrouper::setTypedRects(const DetectRectMap aDRMap)
{
    mTypedRects = aDRMap,
            mTypedRects.setMaxScore(aDRMap.maxScore());
}

void ObjectGrouper::combineResults()
{
    TRACEQFI << type() << groupMethod().name();
    AEXPECTEQ(detector()->type().value(), type().value());
    switch (groupMethod())
    {
    case GrouperMethods::CombineContains:   combineRects();     break;
    case GrouperMethods::CombineOverlap:    combineRects();     break;
    default: ERROR << "Invalid Group Method" << groupMethod().name();    Q_FALLTHROUGH();
    case GrouperMethods::NoCombine:         noCombine();        break;
    }
}

void ObjectGrouper::groupResults()
{
    TRACEQFI << type() << groupMethod().name();
    AEXPECTEQ(detector()->type().value(), type().value());
    switch (groupMethod())
    {
    case GrouperMethods::GroupAverage:      groupByAverage();               break;
    case GrouperMethods::NoGroup:           groupNoGroup();                 break;
    default: ERROR << "Invalid Group Method" << groupMethod().name();       Q_FALLTHROUGH();
    case GrouperMethods::GroupUnion:        groupByUnion();                 break;
    }
}

void ObjectGrouper::assignQuality()
{
    TRACEQFI << type();
    EXPECT(type().isEye() || type().isFaceFrontal());
    if (type().isEye())
        assignEyeQuality(detector()->eyeROI().faceRect());
    else if (type().isFaceFrontal())
        assignFrontalQuality();
    else
        ERROR << "Unhandled ObjectType" << type();
}

GrouperMethods ObjectGrouper::combineMethod() const
{
    int value = mConfig.map().value("CombineMethod", GrouperMethods::NoCombine).toInt();
    GrouperMethods result(value);
    if ( ! result.isCombine()) result = GrouperMethods::NoCombine;
    return result;

}

GrouperMethods ObjectGrouper::groupMethod() const
{
    int value = mConfig.map().value("GroupMethod", GrouperMethods::NoGroup).toInt();
    GrouperMethods result(value);
    if ( ! result.isGroup()) result = GrouperMethods::NoGroup;
    return result;
}

/* ----------------------------- private --------------------------- */

void ObjectGrouper::combineRects()
{
    TRACEQFI << type();
    AEXPECTEQ(detector()->type().value(), type().value());
    AEXPECT(combineMethod().isCombine());
    AEXPECTNE(GrouperMethods::NoCombine, combineMethod());
    ObjectResults combinedOR(type());

    QMultiMap<signed, DetectRect> areaResultMap;
    for (DetectRect dr : mTypedRects)
        areaResultMap.insert( - dr.rect().area(), dr);
    DetectRectList detectedRectsByArea = areaResultMap.values();
    while ( ! detectedRectsByArea.isEmpty())
    {
        DetectRect thisDRect = detectedRectsByArea.takeFirst();
        ObjectResults::Item item(combinedOR.type(), thisDRect);
        DUMPVAL(item);
        QMutableListIterator<DetectRect> mi(detectedRectsByArea);
        mi.toFront();
        while(mi.hasNext())
        {
            mi.next();
            DetectRect otherDRect = mi.value();
            DUMPVAL(otherDRect);
            if (thisDRect.type().value() == otherDRect.type().value()
                    && canCombine(thisDRect.rect(), otherDRect.rect()))
            {
                item.append(otherDRect);
                mi.remove();
            }
        }
        DUMPVAL(item);
        combinedOR.append(item);
    }
    combinedOR.setMaxScore(mTypedRects.maxScore());
    DUMPVAL(combinedOR);
    mCombinedResults = combinedOR;
}

void ObjectGrouper::noCombine()
{
    TRACEQFI << type();
    AEXPECTEQ(detector()->type().value(), type().value());
    AEXPECT(combineMethod().isCombine());
    AEXPECTEQ(GrouperMethods::NoCombine, combineMethod());
    ObjectResults combinedOR(type());
    QMultiMap<signed, DetectRect> areaResultMap;
    for (DetectRect dr : mTypedRects)
        areaResultMap.insert( - dr.rect().area(), dr);
    DetectRectList detectedRectsByArea = areaResultMap.values();
    while ( ! detectedRectsByArea.isEmpty())
    {
        DetectRect thisDRect = detectedRectsByArea.takeFirst();
        ObjectResults::Item item(combinedOR.type(), thisDRect);
        item.setResultRect(item.firstIncluded());
        combinedOR.append(item);
    }
    combinedOR.setMaxScore(mTypedRects.maxScore());
    DUMPVAL(combinedOR);
    mCombinedResults = combinedOR;
}

void ObjectGrouper::groupByUnion()
{
    TRACEQFI << type();
    combineRects();
    ObjectResults combinedOR = mCombinedResults;
    ObjectResults groupedOR(type());
    AEXPECTEQ(type().value(), groupedOR.type().value());
    for (ObjectResultItem combinedORI : combinedOR.itemList())
    {
        DetectRect unifiedDR = combinedORI.unifiedDetectRect();
        ObjectResultItem groupedORI(groupedOR.type(), unifiedDR, combinedORI.includedResults());
        AEXPECTNOT(groupedORI.isIncludedEmpty());
        groupedOR.append(groupedORI);
    }
    groupedOR.setMaxScore(combinedOR.maxScore());
    DUMPVAL(groupedOR);
    AEXPECTEQ(type().value(), groupedOR.type().value());
    mGroupedResults = groupedOR;
}

void ObjectGrouper::groupByAverage()
{
    combineRects();
    mGroupedResults.setMaxScore(mCombinedResults.maxScore());
    MUSTDO(avg);
}

void ObjectGrouper::groupNoGroup()
{
    ObjectResults result(type());
    AEXPECTEQ(type().value(), result.type().value());
    DetectRectMap DRects = mTypedRects;
    for (DetectRect DRect : DRects)
    {
        ObjectResultItem ori(type(), DRect);
        ori.setResultRect(DRect);
        result.append(ori);
    }
    result.setMaxScore(DRects.maxScore());
    AEXPECTEQ(type().value(), result.type().value());
    mGroupedResults = result;
}

void ObjectGrouper::assignEyeQuality(const SCRect &frect)
{
    TRACEQFI << frect << groupedResults();
    ObjectResults groupedOR = groupedResults();
    AEXPECTEQ(type().value(), groupedResults().type().value());
    AEXPECT(groupedOR.type().isEye());
    const FaceGeometry fgeom(frect);
    const int maxScore = groupedOR.maxScore();

    QMultiMap<qreal, ObjectResultItem> sortedDistanceItemsMap;
    for (ObjectResultItem groupedORI : qAsConst(groupedOR).itemList(true))
    {
        qreal distance = eyeResultDistance(groupedORI, maxScore, frect);
        groupedORI.setQualityDistance(distance);
        sortedDistanceItemsMap.insert(groupedORI.distance(), groupedORI);
    }

    ObjectResults qualityOR(type());
    int rank = 0;
    foreach (ObjectResultItem sortedORI, sortedDistanceItemsMap.values())
    {
        sortedORI.setRank(++rank);
        qualityOR.append(sortedORI);
    }
    qualityOR.setMaxScore(maxScore);
    DUMPVAL(qualityOR);
    mQualityResults = qualityOR;
}

void ObjectGrouper::assignFrontalQuality()
{
    TRACEQFI << groupedResults();
    ObjectResults groupedOR = groupedResults();
    ObjectResults qualityOR(type());
    AEXPECTEQ(type().value(), groupedResults().type().value());
    AEXPECT(groupedOR.type().isFaceFrontal());

    QMultiMap<int, ObjectResults::Item> sortedAreaItemMap;
    for (auto ori : groupedOR.itemList())
        sortedAreaItemMap.insert( - ori.resultRect().rect().area(), ori);

    QMultiMap<qreal, ObjectResults::Item> sortedDistanceItemsMap;
    int nItems = sortedAreaItemMap.count();
    int areaIndex = nItems;
    for (ObjectResultItem ori : sortedAreaItemMap)
    {
        qreal itemDistance
                = frontalResultDistance(ori, groupedOR.maxScore(), Rational(--areaIndex, nItems));
        ori.setQualityDistance(itemDistance);
        sortedDistanceItemsMap.insert(ori.distance(), ori);
    }
    DUMPVAL(sortedDistanceItemsMap);

    int rank = 0;
    for (ObjectResultItem ori : sortedDistanceItemsMap)
    {
        AEXPECTEQ(type().value(), ori.type().value());
        ori.setRank(++rank);
        if (ori.quality() < 500)
            qualityOR.appendOrphan(ori.resultRect());
        else
            qualityOR.append(ori);
    }
    qualityOR.setMaxScore(groupedOR.maxScore());
    DUMPVAL(qualityOR);
    mQualityResults = qualityOR;
}

bool ObjectGrouper::canCombine(const SCRect itemRect, const SCRect listRect)
{
    TRACEQFI << itemRect << listRect << combineMethod();
    switch (combineMethod())
    {
    case GrouperMethods::CombineContains:   return canCombineContains(itemRect, listRect);
    case GrouperMethods::CombineOverlap:    return canCombineOverlap(itemRect, listRect);
    default:    WARN << "Invalid Combine Method" << combineMethod().name();
                                            Q_FALLTHROUGH();
    case GrouperMethods::NoCombine:         return false;
    }
}

bool ObjectGrouper::canCombineContains(const SCRect itemRect, const SCRect listRect)
{
    return itemRect.contains(listRect);
}

bool ObjectGrouper::canCombineOverlap(const SCRect itemRect, const SCRect listRect)
{
    static const PerMille overlapThreshold = PerMille(Rational::Term(300));
    bool result;
    Rational olr = itemRect.overlapRatio(listRect);
    result = olr > overlapThreshold;
    TRACEQFI << "itemRect" << itemRect << "listRect" << listRect
             << "intersected" << itemRect.toRect().intersected(listRect.toRect())
             << "olr" << olr << "overlapThreshold" << overlapThreshold << result;
    return result;
}

qreal ObjectGrouper::frontalResultDistance(const ObjectResults::Item ori, const int maxScore, const Rational areaFraction)
{
    /* Score, AreaFraction, WidthRatio */
    int score = qBound(1, ori.resultRect().score(), maxScore);
    int frameWidth = detector()->detectMat().width();
    int faceWidth = ori.resultRect().rect().width();
    AEXPECTNE(0, score); AEXPECTNE(0, frameWidth); AEXPECTNE(0, faceWidth);

    Rational scoreFactor(score, maxScore);
    Rational faceFrameRatio(faceWidth, frameWidth);
    qreal expectedWidthRatio = faceFrameRatio.toReal(1.0) - 0.2;

    mFrontalWA.zeroValues();
    AEXPECT(mFrontalWA.setValue(FrontalScore,       1.0 - scoreFactor.toReal()));
    AEXPECT(mFrontalWA.setValue(FrontalAreaFactor,  1.0 - areaFraction.toReal()));
    AEXPECT(mFrontalWA.setValue(FrontalWidthRatio,  expectedWidthRatio * expectedWidthRatio));
    qreal result = mFrontalWA.calculate();
    TRACEQFI << "result" << result << "ori" << ori << "score" << score  << "scoreFactor" << scoreFactor
             << "areaFraction" << areaFraction << "faceFrameRatio" << faceFrameRatio
             << "expectedWidthRatio" << expectedWidthRatio
             << "expectedWidthRatio2" << expectedWidthRatio  * expectedWidthRatio
             << "Quality" << Quality(result).quality();
    return result;
}

qreal ObjectGrouper::eyeResultDistance(const ObjectResults::Item &ori,  const int maxScore,
                                       const FaceTypeRect frect)
{
    TRACEQFI << ori << frect;
    AEXPECTNOT(ori.resultRect().isNull());
    AEXPECTNOT(frect.isNull());
    AEXPECTNOT(ori.isIncludedEmpty());
    WEXPECTNE(0, ori.resultRect().score());
    int score = qBound(1, ori.resultRect().score(), maxScore);
    FaceGeometry fgeom(frect);
    EyeLine exel = fgeom.eyeLine();
    QQLine lexel = exel.lineToLeft(ori.resultRect().rect().center());
    QQLine rexel = exel.lineToRight(ori.resultRect().rect().center());
    qreal exfrFaceWidth = fgeom.fullFace().width();
    Rational exelEyeWidth = exel.expectedEyeWidth();
    SCRect eyeRect = ori.resultRect().rect();
    qreal eyeWidthF = qreal(eyeRect.width());

    Rational scoreFactor(score, maxScore);
    Rational lexelR(lexel.length(0), qRound(exelEyeWidth));
    Rational rexelR(rexel.length(0), qRound(exelEyeWidth));
    qreal exelF = qMin(lexelR.toReal(), rexelR.toReal());
    qreal lineF = eyeWidthF - (qreal(exelEyeWidth) / 3.0);
    qreal faceF = eyeWidthF - (qreal(exfrFaceWidth) / 5.0);

    /* Score, ExpectedEyeLine, EyeROI, LEyeROI, REyeROI, EyeLineRatio, EyeFaceRatio */
    mEyeWA.zeroValues();
    TRACE << "Refactor in progress";
    mEyeWA.setValue(EyeScore,   1.0 - scoreFactor.toReal());
    mEyeWA.setValue(EyeExEL,    exelF);
    mEyeWA.setValue(EyeROI,     qAbs(lineF));
    qreal result = mEyeWA.calculate();
    TRACEQFI << "score" << score  << "scoreFactor" << scoreFactor << "Quality" << Quality(result).quality()
             << "eyeRect" << eyeRect << "EyeLine" << exel << "exelEyeWidth" << exelEyeWidth
             << "eyeWidthF" << eyeWidthF << "lexelR" << lexelR << "rexelR" << rexelR << "lineF" << lineF << "faceF" << faceF;
    return result;
}

/* -------------------------- private static --------------------------- */

Rational ObjectGrouper::eyeDistanceFactor(const SCRect expected, const SCRect actual)
{
    Rational result(0);
    Rational overlap = expected.overlapRatio(actual);
    qreal centerDistance = QQLine(expected.center(),
                                  actual.center()).length(0.0);
    TRACEQFI << expected << actual << overlap << centerDistance;
    if (qFuzzyIsNull(centerDistance)) return result;                    /* /=======\ */
    if (overlap.isZero())
        result = Rational(expected.width(),
                          expected.width() + sqrt(centerDistance));
    else
        result = Rational(expected.width(), qRound(centerDistance));
    DUMPVAL(result);
    return result;
}

Rational ObjectGrouper::eyeDistanceFactor(const Rational expectedWidth, const Rational actualWidth, const Rational inflection)
{
    TRACEQFI << expectedWidth << actualWidth << inflection;
    EXPECT(expectedWidth.isValid()); EXPECT(actualWidth.isValid()); EXPECT(inflection.isValid());
    Rational result;
    Rational deltaWidth = actualWidth.delta(expectedWidth);
    EXPECT(deltaWidth.isValid());
    if (deltaWidth.isZero()) return Rational(0, 1);                     /* /=======\ */
    Rational distanceRatio(deltaWidth, inflection);
    EXPECT(distanceRatio.isValid());
    qreal inflectionF = inflection.toReal();
    AEXPECTNOT(qIsNull(inflectionF));
    TRACE << deltaWidth << distanceRatio << inflectionF;
    if (deltaWidth.toReal() > 1.0)
        result = Rational(Rational::Term(qRound(sqrt(deltaWidth.toReal()) / inflectionF)),
                          Rational::Term(qRound(inflectionF)));
    else
        result = Rational(inflection, deltaWidth);
    DUMPVAL(result);
    EXPECT(result.isValid());
    return result;
}
