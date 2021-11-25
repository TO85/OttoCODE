#pragma once
#include "eirOpenCV.h"

#include <QtCore/QFileInfo>
#include <QtCore/QList>
#include <QtCore/QRect>
#include <QtCore/QVariantMap>
#include <QtCore/QSize>
#include <QtGui/QImage>

//#include "D:\lang\OpenCV4\opencv\build\include/opencv2/opencv.hpp"
#include "/usr/local/include/opencv4/opencv2/opencv.hpp"
#include <opencv2/opencv.hpp>
#include <opencv2/objdetect/objdetect.hpp>

#include <eirType/DetectRectMap.h>
#include <eirType/MultiName.h>
#include <eirType/ObjectType.h>
#include <eirType/QQFileInfo.h>
#include <eirType/SCRect.h>
#include <eirType/SCRectList.h>

#include "cvException.h"
#include "cvMat.h"
#include "cvSize.h"
#include "cvString.h"

class EIROPENCV_EXPORT cvCascade
{
public:
    class Parameters
    {
    public:
        Parameters() {;}
        Parameters(const QVariantMap config) : mConfig(config) {;}
        void configure(const QVariantMap config) { mConfig = config; }
        void calculate(const QSize aFrameSize, QSize aCoreSize);

        qreal factor() const { return mFactor; }
        unsigned neighbors() const { return mNeighbors; }
        int flags() const { return mFlags; }
        cvSize minSize() const { return mMinSize; }
        cvSize maxSize() const { return mMaxSize; }

    private:
        QVariantMap config() const { return mConfig; }


    public: // debug
        QString toDebugString() const { return toDebugString(*this); }

    public: // static
        static QString toDebugString(const Parameters &parms);

    private:
        qreal mFactor = 1.070;
        unsigned mNeighbors = 3;
        int mFlags = 0;
        cvSize mMinSize;
        cvSize mMaxSize;
        QVariantMap mConfig;
    };

public:

public:
    cvCascade(const ObjectType otype) : cmType(otype) {;}


    ObjectType type() const { return cmType; }
    QString typeName() const { return type().name(); }
    QSize coreSize() const { return mCoreSize; }
    cvMat greyInputMat() const { return mGreyInputMat; }
    QImage greyDetectImage() const { return mGreyInputImage; }
    SCRectList resultRects() const { return mRectResults; }
    DetectRectMap scoredResults() const { return mScoredResults; }

    bool notLoaded() const;
    bool isLoaded() const;
    int cascadeVersion() const { return mCascade.isOldFormatCascade() ? 2 : 4; }
    int cascadeType() const
    { return mCascade.getFeatureType(); } // HAAR or LBP (Local Binary Patterns)
    QStringList statusStrings() const;
    bool isException() const { return exception().isNull(); }
    cvException exception() const { return mException; }
    cvException &exception() { return mException; }

    bool initialize();
    bool loadXml(const QQFileInfo &xmlfi);
    bool loadXml(const cvString &cvXmlFileName);
    void unload();
    void clear();
    int findScoredRects(const cvMat &inputMat, const SCRect &detectRect, const Parameters &parms);
    int findRects(const cvMat &inputMat, const Parameters &parms);
    int findAllRects(const cvMat &inputMat, const Parameters &parms);

private:
    DetectRectMap parseResults(const SCRect detectRect, std::vector<cv::Rect> rectVector,
                               std::vector<int> intVector=std::vector<int>());

private:
    const ObjectType cmType;                    // set in ctor()
    BasicName mCascadeName;                     // set in loadXml
    QQFileInfo mCascadeFileInfo;                // ..
    cv::CascadeClassifier mCascade;             // ..
    QQSize mCoreSize;                           // ..
    cvException mException;                     // ..
    cvMat mGreyInputMat;                        // set in findRects
    QImage mGreyInputImage;                     // ..
    std::vector<int> mIntStdVector;             // ..
    std::vector<cv::Rect> mCvRectStdVector;     // ..
    SCRectList mRectResults;                    // ..
    DetectRectMap mScoredResults;               // ..
};

typedef cvCascade::Parameters cvCascadeParms;
extern EIROPENCV_EXPORT QDebug operator<<(QDebug dbg, const cvCascade::Parameters &parms);

