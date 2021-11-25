#include "IfS6Console.h"

#include <QtCore/QDateTime>
#include <QtCore/QMutableListIterator>
#include <QtCore/QMultiMap>
#include <QtCore/QMapIterator>
#include <QtCore/QTimer>

#include <opencv2/opencv.hpp>

#include <eirExe/Console.h>
#include <eirExe/ImageSupport.h>
#include <eirOpenCV/cvHighGui.h>
#include <eirOpenCV/cvQString.h>
#include <eirOpenCV/cvQStringList.h>
#include <eirType/QQSize.h>
#include <eirType/SCRectF.h>
#include <eirType/Success.h>
#include <eirXfr/Debug.h>
#include <IfData/ResourceBitMask.h>
#include <IfData/ResourceValues.h>
#include <IfGeometry/EyeGeometry.h>
#include <IfGeometry/FaceTypeRect.h>
#include <IfMarker/DirectMarkedFrameMarker.h>
#include <IfObject/NormalizedFaceImage.h>
#include <IfObject/ObjectDetector.h>

IfS6Console::IfS6Console(QCoreApplication *coreApp)
    : Console(coreApp)
{
    setObjectName("IfS6Console");
    QTimer::singleShot(500, this, &IfS6Console::hello);
}

void IfS6Console::hello()
{
    TRACEQFI << QOBJNAME(this) << qApp->arguments();
    writeLine("@->Hello from IfS6Console: " + QDateTime::currentDateTime().toString());
    QTimer::singleShot(100, this, &IfS6Console::configure );
}

void IfS6Console::configure()
{
    TRACEQFI << QOBJNAME(this);
    mpSettings = new CommandLineSettings(this);
    TSTALLOC(mpSettings);
    TRACE << QOBJNAME(mpSettings);
    settings()->set(qApp->arguments().mid(1));
#if 1
    settings()->setFallback("/Resources/ObjectDetection/BaseDir", "/media/toor/Aerie/INDIface/bin/detectors");
    settings()->setFallback("/Resources/ObjectDetection/FaceFrontalFull/CascadeXmlFile",
                         "v4/haarcascade_frontalface_alt.xml");
    settings()->setFallback("/Resources/ObjectDetection/EyeEither/CascadeXmlFile",
                         "v4/haarcascade_eye.xml");
#endif
#ifndef EIRC_NO_INDI1DATA
    settings()->setFallback("/Resources/INDIface6/BaseDir", "../data/Face1");
    settings()->setFallback("/Resources/INDIface6/MaxLayerLoad", 320);
#endif
    writeLine(":::Arguments");
    writeLines(qApp->arguments(), "...");
    writeLine(":::Settings");
    writeLine("   Temporary Directory: "+QDir::tempPath());
    writeLine("   Settings File: " + settings()->tempFileName());
    writeLines(settings()->keyValueStringList(), "...");
    TODO(more);
    QTimer::singleShot(100, this, &IfS6Console::setup);
}

void IfS6Console::setup()
{
    TRACEQFI << QOBJNAME(this);
    setupOutputDirs();
    if (setupInputDir())
        QTimer::singleShot(100, this, &IfS6Console::loadCascades);
    else
        QTimer::singleShot(100, this, &IfS6Console::finish);
}

void IfS6Console::loadCascades()
{
    TRACEQFI << QOBJNAME(this);
    // WANTDO refactor to private pieces
    writeLine("---OpenCV version " + cvQString(cv::getVersionString()));
    bool tShowCvBuild = settings()->value("/Resources/OpenCV/ShowCvBuild", false).toBool();
    if (tShowCvBuild)
    {
        writeLine("   >>>>>>>> Begin cv::getBuildInformation <<<<<<<<", false);
        writeLines(cvQStringList(cv::getBuildInformation()), "  >");
        writeLine("   >>>>>>>>  End  cv::getBuildInformation <<<<<<<<");
    }

    Map objdetConfig = settings()->keyValueMap("/Resources/ObjectDetection");

    // NEEDDO Full/Tight from settings()
    ObjectDetector * pFaceDetector = loadCascade(ObjectType::FaceFrontalFull, objdetConfig);
    if (nullptr != pFaceDetector && pFaceDetector->isLoadValid()) mpFaceOD = pFaceDetector;

    // NEEDDO Left/Right/Either from settings()
    ObjectDetector * pEyeDetector = loadCascade(ObjectType::EyeEither, objdetConfig);
    if (nullptr != pEyeDetector && pEyeDetector->isLoadValid()) mpEyeOD = pEyeDetector;

    if (nullptr == mpFaceOD || nullptr == mpEyeOD)
    {
        QTimer::singleShot(100, this, &IfS6Console::finish);
        return;                                                         /* /====\ */
    }

    AEXPECT(mpFaceOD->type().isFaceFrontal());
    AEXPECT(mpFaceOD->finder()->cascade()->type().isFaceFrontal());
    AEXPECT(mpFaceOD->isCascadeLoaded());
    AEXPECT(mpEyeOD->type().isEye());
    AEXPECT(mpEyeOD->finder()->cascade()->type().isEye());
    AEXPECT(mpEyeOD->isCascadeLoaded());
    QTimer::singleShot(100, this, &IfS6Console::loadResourceData);
}

void IfS6Console::loadResourceData()
{
    TRACEQFI << QOBJNAME(this);
    settings()->beginGroup("/Resources/INDIface6");
    const QQString baseDirName = settings()->value("BaseDir").toString();
    const unsigned maxLayerLoad = settings()->value("MaxLayerLoad").toUInt();
    settings()->endGroup();
    TRACE << baseDirName << maxLayerLoad;

    writeLine("---Initializing INDIface " + IfM->version().toString());
    IfM->initialize(baseDirName, maxLayerLoad);
    writeLines(IfM->resource()->filePathNameList(), "   ");
    IfM->loadResources();
    writeLines(IfM->resourceValues().baseData().toInfoStrings(), "   "); // WANTDO from signal
    DUMPVAL(IfM->resourceValues().baseData().normalSize());
    DUMPVAL(IfM->resourceValues().baseData().normalEyeLine());
    EXPECTNOT(IfM->resourceValues().baseData().normalSize().isEmpty());
    EXPECTNOT(IfM->resourceValues().baseData().normalEyeLine().isEmpty());
    if ( ! IfM->resourceValues().baseData().normalSize().isEmpty()
            && ! IfM->resourceValues().baseData().normalEyeLine().isEmpty())
    {
        mNormFaceImage.setNormalGeometry(IfM->resourceValues().baseData().normalSize(),
                                         IfM->resourceValues().baseData().normalEyeLine());
    }
    QTimer::singleShot(100, this, &IfS6Console::start);
}

void IfS6Console::start()
{
    TRACEQFI << QOBJNAME(this);
    writeLines(mpFaceOD->cascadeStatus(), "   ");
    writeLines(mpEyeOD->cascadeStatus(), "   ");
    writeLine("===Opening Input Directory: " + mInputDir.path());
    QQStringList nameFilters = gsImageSupport->supportedReaderDirNameFilters();
    writeLine("   Available Image Formats: " + nameFilters.join("; "));
    nameFilters.intersect(QStringList() << "*.jpg" << "*.png");
    writeLine("   Supported Image Formats: " + nameFilters.join("; "));

    // nameFilters << "*.jpg"; // add for testing without JPEG plugin
    mInputFiles = mInputDir.entryInfoList(nameFilters);
    DUMP << mInputFiles;
    WEXPECTNOT(mInputFiles.isEmpty());
    mFrameIndex = -1;
    if (mInputFiles.isEmpty())
    {
        errorLine(QQString("***%1 contains no supported image files")
                  .formatMessage(mInputDir.absolutePath()));
        QTimer::singleShot(100, this, &IfS6Console::finish);
    }
    else
    {
        writeLine(QQString("---%1 supported image files in %2")
                  .formatMessage(mInputFiles.count(), mInputDir.path()));
        QTimer::singleShot(100, this, &IfS6Console::nextFrame);
    }
}

void IfS6Console::readInputImage()
{
    TRACEQFI << QOBJNAME(this);
    Success success;
    const QQFileInfo inputFileInfo = mInputFiles.value(mFrameIndex);
    write(QQString("===Reading: #%1 %2 ")
          .formatMessage(mFrameIndex + 1, inputFileInfo.absoluteFilePath()));
    success.expect(inputFileInfo.exists());
    success.expect(inputFileInfo.isReadable());
    const QQImage inputImage(inputFileInfo);
    TRACE << inputFileInfo << inputImage;
    success.expectNot(inputImage.isNull());
    success.validate();
    writeLine(success ? QString("%1x%2").arg(inputImage.width()).arg(inputImage.height())
                      : "ERROR!");
    if (success)
    {
        frame().setName(inputFileInfo.completeBaseName());
        frame().setFileInfo(inputFileInfo);
        frame().setInputImage(inputImage);
        frame().setInputImageSize(inputImage.size());
        QTimer::singleShot(100, this, &IfS6Console::detectFaces);
    }
    else
    {
        QTimer::singleShot(100, this, &IfS6Console::nextFrame);
    }
}

void IfS6Console::detectFaces()
{
    const unsigned minQuality = settings()->value("/Frame/ObjectDetection/Grouping/MinQuality", 500).toUInt();
    const signed minWidth = settings()->value("/Frame/ObjectDetection/Grouping/MinWidth", 48).toInt();
    TRACEQFI << QOBJNAME(this) << minQuality << minWidth;
    WANTDO(mFaceParms.calculate()); // WANTDO
    QQImage inputFrameImage = frame().getInputImage();
    EXPECT(inputFrameImage.notNull());
    if (inputFrameImage.isNull())
        return QTimer::singleShot(100, this, &IfS6Console::nextFrame);      /* /====\ */
    AEXPECT(mpFaceOD->type().isFaceFrontal());
    AEXPECT(mpFaceOD->setImage(inputFrameImage));

    int detectedFaces = mpFaceOD->detect(Configuration());
    ObjectResults faceObjectResults = mpFaceOD->results();
    DUMPVAL(faceObjectResults);
    int keptFaces = 0, ignoredFaces = 0;
    ObjectResultItem::List ORIList = faceObjectResults.itemList();
    QMutableListIterator<ObjectResultItem> mutableItem(ORIList);
    while (mutableItem.hasNext())
    {
        ObjectResultItem faceORI = mutableItem.next();
        DUMPVAL(faceORI);
        if (faceORI.quality() >= minQuality && faceORI.resultRect().rect().width() >= minWidth)
        {
            TRACE << "Keeping:" << faceORI;
            ++keptFaces;
        }
        else
        {
            TRACE << "Ignored:" << faceORI;
            faceObjectResults.appendOrphan(faceORI.includedResults().list());
            mutableItem.remove();
            ++ignoredFaces;
        }
    }
    faceObjectResults.setItems(ORIList);
    frame().setFaceResults(faceObjectResults);
    frame().setFaceCount(keptFaces);
    AEXPECTEQ(keptFaces, faceObjectResults.itemCount());
    writeLine(QString("   %1 face candidates found, %2 kept, %3 discarded")
              .arg(detectedFaces).arg(keptFaces).arg(ignoredFaces));
    if (0 == detectedFaces)
        QTimer::singleShot(100, this, &IfS6Console::writeNoFaceFrame);
    else
        QTimer::singleShot(100, this, &IfS6Console::createFaceImages);
}

void IfS6Console::createFaceImages()
{
    TRACEQFI << QOBJNAME(this);
    const ObjectResults frameOR = frame().getFaceResults();
    const QQImage inputFrameImage = frame().getInputImage();
    const int nFaces = frame().getFaceCount();
    mFaceVector.resize(nFaces);
    int faceIndex = 0;
    for (ObjectResultItem &faceORI : frameOR.itemList())
    {
        const DetectRect facedDR = faceORI.resultRect();
        const SCRect faceRect = facedDR.rect();
        const SCRect overRect = faceRect.scaled(1.250);
        TRACE << faceIndex << "facedDR" << facedDR
              << "faceORI" << faceORI
              << "faceRect" << faceRect
              << "overScaledRect" << overRect;

        const QQImage cropFaceImage = inputFrameImage.copy(faceRect);
        DUMPVAL(cropFaceImage);
        AEXPECTNOT(cropFaceImage.isNull());
        const QQImage overCropFaceImage = inputFrameImage.copy(overRect);
        DUMPVAL(overCropFaceImage);
        AEXPECTNOT(overCropFaceImage.isNull());

        face(faceIndex).setFaceResultItem(faceORI);
        face(faceIndex).setCroppedFaceImage(cropFaceImage);
        ++faceIndex;
    }
    QTimer::singleShot(100, this, &IfS6Console::detectEyes);
}

void IfS6Console::detectEyes()
{
    TRACEQFI << QOBJNAME(this) << mpEyeOD->type();
    AEXPECT(mpEyeOD->type().isEye());
    WANTDO(mEyeParms.calculate());
    EXPECT(mpEyeOD->setImageFrom(mpFaceOD));
    const int nFaces = frame().getFaceCount();
    const ObjectResults frameOR = frame().getFaceResults();
    AEXPECTEQ(nFaces, frameOR.itemCount());
    EXPECTNE(0, nFaces);
    int faceIndex = 0;
    for (ObjectResultItem faceORI : frameOR.itemList())
    {
        const SCRect faceRect(faceORI.resultRect().rect());
        AEXPECTNOT(faceRect.isNull());
        mpEyeOD->setEyeROI(faceRect);
        const int eyeCount = mpEyeOD->detectRegion(faceRect, Configuration());
        face(faceIndex).setEyeROI(mpEyeOD->eyeROI());
        face(faceIndex).setDetectFaceImage(mpEyeOD->regionDetectImage());
        TRACE << faceORI << faceRect << eyeCount;
        write("   Eyes: " + QString::number(eyeCount) + " - ");
        if (eyeCount > 1)
        {
            ObjectResults eyeOR = mpEyeOD->results();
            DUMPVAL(eyeOR);
            face(faceIndex).setRawEyeResults(eyeOR);
        }
        ++faceIndex;
    }
    writeLine("<", true);
    QTimer::singleShot(100, this, &IfS6Console::writeMarkedFrame);
}

void IfS6Console::writeNoFaceFrame()
{
    TRACEQFI << QOBJNAME(this);
    const QQImage frameImage = frame().getInputImage();
    QQFileInfo qfi(mNoFaceFrameOutputDir, frame().getName()+".png");
    DUMPVAL(qfi);
    // TODO: Mark Orphan Faces (or move orphan-only to MarkedFrame`
    if (frameImage.save(qfi.absoluteFilePath()))
        writeLine("   No Face: "+qfi.absoluteFilePath()+" written");
    else
        errorLine("***No Face: "+qfi.absoluteFilePath()+" FAILED!");
    QTimer::singleShot(100, this, &IfS6Console::nextFrame);
}

void IfS6Console::writeMarkedFrame()
{
    TRACEQFI << QOBJNAME(this);
    const ObjectResults faceOR = frame().getFaceResults();
    const QQImage frameImage = frame().getInputImage();
    DirectMarkedFrameMarker marker(frameImage);
    marker.markFaceResults(mFrame, mFaceVector);
    const QQFileInfo qfi(mMarkedFrameOutputDir, frame().getName()+".png");
    if (marker.markedImage().save(qfi.absoluteFilePath()))
        writeLine("   "+qfi.absoluteFilePath()+" written");
    else
        ERROR << marker.markedImage() << qfi << "Write Failed";
    QTimer::singleShot(100, this, &IfS6Console::writeEyeMarkedFaces);
}

void IfS6Console::writeEyeMarkedFaces()
{
    TRACEQFI << QOBJNAME(this);
    const int nFaces = frame().getFaceCount();
    for (int faceIndex = 0; faceIndex < nFaces; ++faceIndex)
        writeEyeMarkedFace(faceIndex);
    QTimer::singleShot(100, this, &IfS6Console::writeNormalFaces);
}

void IfS6Console::writeNormalFaces()
{
    TRACEQFI << QOBJNAME(this);
    int nFaces = frame().getFaceCount();
    for (int faceIndex = 0; faceIndex < nFaces; ++faceIndex)
    {
        writeNormalFace(faceIndex);
        writeGenerateFace(faceIndex);
    }
    QTimer::singleShot(100, this, &IfS6Console::nextFrame);
}

void IfS6Console::nextFrame()
{
    TRACEQFI << QOBJNAME(this);
    frame().reset();
    mFaceVector.clear();
    AEXPECTEQ(0, frame().getFaceCount());
    ++mFrameIndex;
    if (mFrameIndex < mInputFiles.count())
        QTimer::singleShot(500, this, &IfS6Console::readInputImage);
    else
        QTimer::singleShot(500, this, &IfS6Console::finish);
}

void IfS6Console::finish()
{
    TRACEQFI << QOBJNAME(this);

    WANTDO(it);
    QTimer::singleShot(500, qApp, &QCoreApplication::quit);
}

/* ----------------------------------- private ------------------------------------ */

int IfS6Console::faceSizeScale(const int faceIndex, const int minWidth)
{
    TRACEQFI << faceIndex << minWidth;
    int faceWidth = face(faceIndex).getFaceResultItem().resultRect().rect().size().width();
    Rational widthScale(faceWidth, faceWidth);
    if (faceWidth < minWidth)
    {
        qreal sf = qreal(minWidth) / qreal(faceWidth);
        int si = int(sf + 1.0);
        widthScale.setNumerator(faceWidth * si);
        TRACE << faceWidth << sf << si << widthScale;
    }
    int result = widthScale.round(0);
    TRACE << result;
    return result;
}

bool IfS6Console::setupInputDir()
{
    TRACEFN;
    Success success;
    const QQString tInputDirName = settings()->value("/Input/Dir", "../in").toString();
    QQDir tInputDir(QQDir::current());
    WEXPECT(tInputDir.exists(tInputDirName));
    WEXPECT(tInputDir.exists());
    WEXPECT(tInputDir.isReadable());
    WEXPECT(tInputDir.notNull());
    success.expect(tInputDir.exists(tInputDirName));
    success.expect(tInputDir.cd(tInputDirName));
    success.expect(tInputDir.exists());
    success.expect(tInputDir.isReadable());
    success.expect(tInputDir.notNull());
    success.validate();
    if (success)
    {
        writeLine(QQString("---Input Directory: %1 + %2\n--> %3 %4").formatMessage(
                      QQDir::current().path(), tInputDirName,
                      tInputDir.absolutePath(), tInputDir.attributes()));
        mInputDir = tInputDir;
    }
    else
    {
        errorLine("***Input Directory Invalid: " + tInputDir.absolutePath());
    }
    return success;
}

void IfS6Console::setupOutputDirs()
{
    TRACEFN;

    QQString tBaseOutputDirName = settings()->value("/Output/BaseDir",
            "~/INDIface/INDIout/console/@").toString();
    if (tBaseOutputDirName.contains('@'))
    {
        QString timeStamp = QDateTime::currentDateTime().toString("DyyyyMMdd-Thhmm");
        tBaseOutputDirName.replace('@', timeStamp);
    }
    QDir tBaseOutputDir = QQDir::current();
    EXPECT(mBaseOutputDir.mkpath(tBaseOutputDirName));
    EXPECT(mBaseOutputDir.cd(tBaseOutputDirName));
    EXPECT(mBaseOutputDir.exists());
    if (tBaseOutputDir.exists())
        mBaseOutputDir = tBaseOutputDir;

    mMarkedFrameOutputDir = mBaseOutputDir;
    EXPECT(mMarkedFrameOutputDir.mkpath("MarkedFrame"));
    EXPECT(mMarkedFrameOutputDir.cd("MarkedFrame"));
    EXPECT(mMarkedFrameOutputDir.exists());
    EXPECT(mBaseOutputDir.exists("MarkedFrame"));

    mNoFaceFrameOutputDir = mBaseOutputDir;
    EXPECT(mNoFaceFrameOutputDir.mkpath("NoFaceFrame"));
    EXPECT(mNoFaceFrameOutputDir.cd("NoFaceFrame"));
    EXPECT(mNoFaceFrameOutputDir.exists());
    EXPECT(mBaseOutputDir.exists("NoFaceFrame"));

    mMarkedFaceOutputDir = mBaseOutputDir;
    EXPECT(mMarkedFaceOutputDir.mkpath("MarkedFace"));
    EXPECT(mMarkedFaceOutputDir.cd("MarkedFace"));
    EXPECT(mMarkedFaceOutputDir.exists());
    EXPECT(mBaseOutputDir.exists("MarkedFace"));
#if 1
    mNormalFaceOutputDir = mBaseOutputDir;
    AEXPECT(mNormalFaceOutputDir.mkpath("Face"));
    EXPECT(mNormalFaceOutputDir.cd("Face"));
    AEXPECT(mNormalFaceOutputDir.exists());
    AEXPECT(mBaseOutputDir.exists("Face"));
#endif
}

ObjectDetector *IfS6Console::loadCascade(const ObjectType aType, const Map aConfigMap)
{
    TRACEQFI << aType.name();
    ObjectDetector * result = nullptr;
    const QQString tBaseDirName = aConfigMap.value("BaseDir").toString();
    const Key tCascadeFileNameKey(aType.name(), "CascadeXmlFile");
    const QQString tCascadeFileName = aConfigMap.value(tCascadeFileNameKey).toString();
    const QQFileInfo xmlFileInfo(QQDir(tBaseDirName), tCascadeFileName);
    write(QQString("---Loading %1 cascade: %2 >").formatMessage(aType.name(),
                        xmlFileInfo.absoluteFilePath()), true);
    TRACE << xmlFileInfo;
    WEXPECT(xmlFileInfo.isFile()); WEXPECT(xmlFileInfo.exists()); WEXPECT(xmlFileInfo.isReadable());
    if (xmlFileInfo.isReadable() && xmlFileInfo.isFile())
    {
        ObjectDetector * pDetector = new ObjectDetector(aType, this);
        EXPECT(pDetector->initialize());
        pDetector->loadCascade(xmlFileInfo);
        if (pDetector->isCascadeLoaded())
        {
            QQSize tCoreSize = pDetector->finder()->cascade()->coreSize();
            writeLine(tCoreSize.toString(), true);
            writeLines(pDetector->cascadeStatus());
            result = pDetector;
        }
        else
        {
            ERROR << "Cascade Load Failed:" << aType.name() << xmlFileInfo;
            writeLine("FAILED!", true);
        }
    }
    return result;
}

void IfS6Console::writeEyeMarkedFace(const int faceIndex)
{
    const ObjectResultItem faceORI = face(faceIndex).getFaceResultItem();
    const DetectRect faceDR = faceORI.resultRect();
    const SCRect faceRect = faceDR.rect();
    const QQImage faceImage = face(faceIndex).getDetectFaceImage();
    const EyeROI eyeROI = face(faceIndex).getEyeROI();
    const SCRect leyeROI = eyeROI.left();
    const SCRect reyeROI = eyeROI.right();
    const ObjectResults eyeOR = face(faceIndex).getRawEyeResults();
    QString faceId = QString("#%4FQ%5W%3X%1Y%2")
            .arg(faceRect.center().x(), 4, 10, QChar('0')) // 1
            .arg(faceRect.center().y(), 4, 10, QChar('0')) // 2
            .arg(faceRect.size().width(), 4, 10, QChar('0')) //3
            .arg(faceORI.rank(), 2, 10, QChar('0')) //4
            .arg(faceORI.quality(), 3, 10, QChar('0')); //5
    TRACEQFI << faceIndex << faceRect << faceImage << leyeROI << reyeROI << eyeOR << faceId;

    DirectMarkedFrameMarker eyeMarker(faceImage);
    EXPECT(eyeMarker.isInputValid());
    eyeMarker.markEyeResults(frame(), face(faceIndex));
    EXPECT(eyeMarker.isValid());
    const QQImage markedFaceImage = eyeMarker.markedImage();
    AEXPECTNOT(markedFaceImage.isNull());
    face(faceIndex).setEyeMarkedFaceImage(markedFaceImage);

    write("   ", false);
    for (auto &eyeORI : eyeOR.itemList())
        { QString eyeId = eyeID(eyeORI); write(eyeId + " ", false); faceId += eyeId; }
    writeLine("", true);
    const QQFileInfo qfi(mMarkedFaceOutputDir, frame().getName()+faceId+".png");
    TRACEQFI << faceIndex << markedFaceImage << eyeOR << faceId << qfi;
    if (markedFaceImage.save(qfi.absoluteFilePath()))
        writeLine(QString("---#%4.%5 %1 eye%3 %2 written")
                  .arg(eyeOR.itemCount())
                  .arg(qfi.absoluteFilePath(),
                       (1 == eyeOR.itemCount()) ? ", " : "s, ")
                  .arg(mFrameIndex + 1).arg(faceIndex + 1));
    else
        errorLine(QQString("***%1 eye%2 Failed: %3")
                  .formatMessage(eyeOR.itemCount(),
                                 (1 == eyeOR.itemCount()) ? ", " : "s, ",
                                 qfi.absoluteFilePath()));

    if (eyeOR.itemCount() > 1)
    {
        write("   <-", false);
        foreach (ObjectResults::Item eyeORI, eyeOR.itemList())
        {
            SCRect eyeRect = eyeORI.resultRect().rect();
            write(QString(" #%1: %7EQ%2 (%3) %4@%5x%6 -")
                  .arg(eyeORI.rank()) // %1
                  .arg(eyeORI.quality(), 3, 10, QChar('0')) // %2
                  .arg(eyeORI.distance(), 5, 'f', 3) // %3
                  .arg(eyeRect.width()) // %4
                  .arg(eyeRect.center().x()) // %5
                  .arg(eyeRect.center().y()) // %6
                  .arg(eyeORI.type().eyeChar())); // %7
        }
        writeLine(">", true);
    }
}

void IfS6Console::writeNormalFace(const int faceIndex)
{
    const FaceData face = mFaceVector[faceIndex];
    TRACEQFI << faceIndex << face;
    const ObjectResultItem faceORI = face.getFaceResultItem();
    const SCRect faceRect = faceORI.resultRect().rect();
    const ObjectResults eyeOR = face.getRawEyeResults();
    const QQImage inputFrameImage = frame().getInputImage();
    const QQImage cropFaceImage = face.getCroppedFaceImage();
    const DetectRectMap eyeDRM = eyeOR.itemResults();
    const DetectRectList eyeDRLbyScore = eyeDRM.list(true);

    EyeLine eyeLine = EyeROI::parseEyeLine(eyeDRLbyScore);
    DUMPVAL(eyeLine);
    if (eyeLine.isNull()) return;                                       /* /========\ */

    QQImage tNormImage = mNormFaceImage.set(inputFrameImage, faceRect, eyeLine);
    DUMPVAL(tNormImage);
    AEXPECT(tNormImage.notNull());
    QFileInfo qfi(mNormalFaceOutputDir, frame().getName()+faceID(faceORI)+"-Normal.png");
    TRACEQFI << faceIndex << tNormImage << eyeOR << faceID(faceORI) << qfi;
    if (tNormImage.save(qfi.absoluteFilePath()))
    {
        writeLine(QString("   Normalized %1 %2 written")
                  .arg(/*1*/QQLine(eyeLine).toDebugString())
                  .arg(/*2*/qfi.absoluteFilePath()));
    }
    else
    {
        writeLine(QString("***Normalized %1 %2 FAILED!")
                  .arg(/*1*/eyeLine.toDebugString())
                  .arg(/*2*/qfi.absoluteFilePath()));
        ERROR << tNormImage << qfi << "Write Failed";
    }
    mFaceVector[faceIndex].setNormalizedFaceImage(tNormImage);
}

void IfS6Console::writeGenerateFace(const int faceIndex)
{
#if 0
    const FaceData face = mFaceVector[faceIndex];
    TRACEQFI << faceIndex << face;
    const ObjectResultItem faceORI = face.getFaceResultItem();
    const SCRect faceRect = faceORI.resultRect().rect();
    const ObjectResults eyeOR = face.getRawEyeResults();
    const QQImage inputFrameImage = frame().getInputImage();
    const QQImage cropFaceImage = face.getCroppedFaceImage();
    const QQImage normFaceImage = face.getNormalizedFaceImage();
    const DetectRectMap eyeDRM = eyeOR.itemResults();
    const DetectRectList eyeDRLbyScore = eyeDRM.list(true);
    const ResourceBitMask outputBitMask = IfM->resourceValues().outputBitMask();
    DUMPVAL(outputBitMask);
    EXPECT(outputBitMask.notEmpty());
    const QQBitArray outputMaskMatrix(outputBitMask.bits(), normFaceImage.size());
    DUMPVAL(outputMaskMatrix);

    const QQImage genFaceImage = mNormFaceImage.masked(outputMaskMatrix);

    QFileInfo qfi(mNormalFaceOutputDir, frame().getName()+faceID(faceORI)+"-Generate.png");
    TRACEQFI << faceIndex << genFaceImage << qfi;
    if (genFaceImage.save(qfi.absoluteFilePath()))
    {
        writeLine(QString("   Generated %1 written")
                  .arg(/*1*/qfi.absoluteFilePath()));
        writeLines(outputMaskMatrix.toStrings('+', '-', 8), "   ");
    }
    else
    {
        writeLine(QString("***Generated %1 FAILED!")
                  .arg(/*1*/qfi.absoluteFilePath()));
        ERROR << genFaceImage << qfi << "Write Failed";
    }
    mFaceVector[faceIndex].setGeneratedFaceImage(genFaceImage);
#endif
}

QString IfS6Console::faceID(const ObjectResults::Item &ori)
{
    SCRect facerc = ori.resultRect().rect();
    QString result = QString("+R%4FQ%5X%1Y%2W%3")
            .arg(facerc.center().x(), 4, 10, QChar('0'))
            .arg(facerc.center().y(), 4, 10, QChar('0'))
            .arg(facerc.size().width(), 4, 10, QChar('0'))
            .arg(ori.rank(), 2, 10, QChar('0'))
            .arg(ori.quality(), 3, 10, QChar('0'));
    return result;
}

QString IfS6Console::eyeID(const ObjectResults::Item &ori)
{
    SCRect eyeRect = ori.resultRect().rect();
    QString result = QString("+#%1%7EQ%2(%3)W%4X%5Y%6")
          .arg(ori.rank(), 2, 10, QChar('0')) // %1
          .arg(ori.quality(), 3, 10, QChar('0')) // %2
          .arg(ori.distance(), 5, 'f', 3) // %3
          .arg(eyeRect.width(), 3, 10, QChar('0')) // %4
          .arg(eyeRect.center().x(), 4, 10, QChar('0')) // %5
          .arg(eyeRect.center().y(), 4, 10, QChar('0')) // %6
          .arg(ori.type().eyeChar()); // %7
    return result;
}
