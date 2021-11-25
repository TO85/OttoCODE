#pragma once

#include <QObject>
#include <eirExe/Console.h>

#include <QDir>
#include <QFileInfo>
#include <QFileInfoList>
#include <QImage>
#include <QList>
#include <QRect>

#include <eirData/CommandLineSettings.h>
#include <eirGui/QQImage.h>
#include <eirOpenCV/cvMat.h>
#include <eirType/QQList.h>
#include <eirType/DetectRectList.h>
#include <eirXml/DomStatus.h>
#include <IfManager/INDIfaceManager.h>
#include <IfObject/NormalizedFaceImage.h>
#include <IfObject/ObjectDetector.h>
#include <IfObject/ObjectResults.h>
#include <IfObject/FaceData.h>
#include <IfObject/FrameData.h>


class IfS6Console : public Console
{
    Q_OBJECT
public:

public:
    explicit IfS6Console(QCoreApplication *coreApp);

public slots:
    void hello();
    void configure();
    void loadCascades();
    void loadResourceData();
    void setup();
    void start();
    void readInputImage();
    void detectFaces();
    void createFaceImages();
    void detectEyes();
    void writeNoFaceFrame();
    void writeMarkedFrame();
    void writeEyeMarkedFaces();
    void writeNormalFaces();
    void nextFrame();
    void finish();

signals:

private:
    CommandLineSettings *settings() { return mpSettings; }
    FrameData frame() const { return mFrame; }
    FrameData &frame() { return mFrame; }
    FaceData face(const int faceIndex) const { return mFaceVector[faceIndex]; }
    FaceData &face(const int faceIndex) { return mFaceVector[faceIndex]; }
    FaceData::Vector faces() const { return mFaceVector; }
    FaceData::Vector &faces() { return mFaceVector; }

private:
    int faceSizeScale(const int faceIndex, const int minWidth);
    bool setupInputDir();
    void setupOutputDirs();
    ObjectDetector *loadCascade(const ObjectType aType, const Map aConfigMap);
    void writeEyeMarkedFace(const int faceIndex);
    void writeNormalFace(const int faceIndex);
    void writeGenerateFace(const int faceIndex);
    QString faceID(const ObjectResults::Item &ori);
    QString eyeID(const ObjectResults::Item &ori);

private:
    ObjectDetector *mpFaceOD=nullptr;
    ObjectDetector *mpEyeOD=nullptr;
    CommandLineSettings *mpSettings=nullptr;
    FrameData mFrame;
    FaceData::Vector mFaceVector;
    NormalizedFaceImage mNormFaceImage;
    QQDir mBaseCascadeDir;
    QQString mFaceCascadeFilename;
    QQString mEyeCascadeFilename;
    QQDir mInputDir;
    QQDir mBaseOutputDir;
    QQDir mMarkedFrameOutputDir;
    QQDir mNoFaceFrameOutputDir;
    QQDir mMarkedFaceOutputDir;
    QQDir mNormalFaceOutputDir;
    QQFileInfoList mInputFiles;
    int mFrameIndex=0;
};

