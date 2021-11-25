#pragma once

#include <QtCore/QDir>
#include <QtCore/QFileInfo>

#if 0
#include <opencv2/opencv.hpp>
#include <opencv2/core/mat.hpp>
#include <opencv2/core/types.hpp>
#include <opencv2/objdetect.hpp>
#endif

#include <eirOpenCV/cvCascade.h>
#include <eirOpenCV/cvMat.h>
//#include <eirPatRec/PatRecCatalog.h>
//#include <eirPatRec/PatternRecognition.h>
//#include <eirType/PatternType.h>
#include <eirOpenCV/CascadeFindParameters.h>
#include <eirOpenCV/cvCascade.h>
#include <eirVar/VariableMap.h>

#include <QImage>

class ProcessFrame : public VariableMap
{
public:
    explicit ProcessFrame(const VariableMap &initMap=VariableMap(),
                          const VariableMap &configMap=VariableMap());

    void initialize(const VariableMap &initMap=VariableMap());
    void configure(const VariableMap &configMap=VariableMap());
    bool load(const QString &filePathName);
    bool load(const QDir &dir, const QString &fileName);
    bool load();
    void process(const QImage &frameImage, const VariableMap &imageConfigMap);

private:
    VariableMap mInitMap;
    VariableMap mConfigMap;
    QDir mCascadeDir;
    QFileInfo mFaceCascadeFileInfo;
    QFileInfo mEyeCascadeFileInfo;
    cvCascade mFaceClassifier;
    cvCascade mEyeClassifier;
    QImage mFrameImage;
    cvMat mFrameMat;
    CascadeFindParameters mParameters;

//    PatRecCatalog *mpPatRecCatalog=nullptr;
  //  PatternRecognition *mpFrontalPatRec=nullptr;
};

