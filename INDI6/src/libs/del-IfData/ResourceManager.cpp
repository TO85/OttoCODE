#include "ResourceManager.h"

#include "MainDataParser.h"

const QQString ResourceManager::scmDocType = QQString("INDIfaceData");
const QQString ResourceManager::scmDataTag = QQString("INDIFaceData"); // NOTE: INDIF.., not INDIf..
const QQString ResourceManager::scmInputBitMaskTag = QQString("INDI-EigenFaceGenerator-BitMask");
const QQString ResourceManager::scmOutputBitMaskTag = QQString("INDI-EigenFaceGenerator-OutputMask");
const QQString ResourceManager::scmMeanFaceTag = QQString("INDI-EigenFaceGenerator-MeanFace");
const QQString ResourceManager::scmWeightMaskTag = QQString("INDI-EigenFaceGenerator-WeightMask");
const QQString ResourceManager::scmFaceLayersTag = QQString("INDI-EigenFaceGenerator-EigenFaceLayer");

ResourceManager::ResourceManager(QObject *parent)
    : QObject(parent)
    , mpFileManager(new DomFileManager(this))
{
    setObjectName("ResourceManager");
    TRACEQFI << QOBJNAME(parent) << QOBJNAME(this);
}

DomStatus ResourceManager::loadResourses()
{
    MUSTRTN(DomStatus());
}

void ResourceManager::initialize()
{
    TRACEQFI << QOBJNAME(this);
    status().clear();
    initializeBaseDir();
    initializeFileSet();
    fileManager()->readFilesData();
    fileManager()->setDocumentsBytes();
    TODO(EMIT);
}

void ResourceManager::initializeBaseDir()
{
    DomStatus result;
    QDir tBaseDir("../data/Face1"); WANTDO(fromConfig);
    result.expect("Base Dir exists(%1)", tBaseDir.exists(), QtInfoMsg, QtCriticalMsg);
    result.expect("Base Dir readable(%1)", tBaseDir.isReadable(), QtInfoMsg, QtCriticalMsg);
    if (result.type().notError())
        fileManager()->setBaseDir(tBaseDir);
    result.dump();
    status().append(result);
}

void ResourceManager::initializeFileSet()
{
    TRACEQFI << QOBJNAME(this);
    TODO(DomStatus);
    fileManager()->clear();
    fileManager()->addFile("MainFace", "Face1.xml");
    fileManager()->addFile("BitMasks", "BitMask.xml");
    fileManager()->addFile("MeanFace", "MeanFace.xml");
    fileManager()->addFile("WeightMask", "WeightMask.xml");
    fileManager()->addFile("FaceLayers", "FaceLayers.xml");
    fileManager()->dump();
    TODO(emit);
}

DomStatus ResourceManager::parseMainData(const QQDomElement &aMainDataDE)
{
    TRACEQFI << aMainDataDE;
    DomStatus result;
    MainDataParser tMainParser;
    result.append(tMainParser.load(aMainDataDE));
    mData.set(tMainParser.mainData());
    result.dump();
    return result;
}
