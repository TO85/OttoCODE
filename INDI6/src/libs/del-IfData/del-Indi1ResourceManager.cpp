#include "Indi1ResourceManager.h"

#include <eirXml/DomFileManager.h>
#include <IfData/Indi1MainData.h>
#include <IfData/InputIndi1BitMask.h>
#include <IfData/LayerIndi1MaskedFloatVector.h>
#include <IfData/MainDataParser.h>
#include <IfData/OutputIndi1BitMask.h>
#include <IfData/ResourceData.h>


Indi1ResourceManager::Indi1ResourceManager(QObject *parent)
    : QObject(parent)
{
    setObjectName("Indi1ResourceManager");
    TRACEQFI << QOBJNAME(parent) <<QOBJNAME(this);
    DomStatus::Item hello(QtInfoMsg, "Indi1ResourceManager c'tor");
    mStatus.append(hello);
}

void Indi1ResourceManager::setBaseDir(const QDir &newBaseDir)
{
    TRACEQFI << newBaseDir;
    mBaseDir = newBaseDir;
    fileManager()->setBaseDir(mBaseDir);
}



DomStatus Indi1ResourceManager::loadResourses()
{
    TRACEFN;
    DomStatus result;
    result.info("Starting Indi1ResourceManager::loadResourses()");


    /*
    DomStatus mainDataLoad = loadMainData(fileInfo(MainData));
    result.append(mainDataLoad);

    DomStatus readMasksDocStatus = readMaskFile(fileInfo(BitMasks));
    DomStatus inputMaskLoad = loadInputMask();
    DomStatus outputMaskLoad = loadOutputMask();
    result.append(readMasksDocStatus);
    result.append(inputMaskLoad);
    result.append(outputMaskLoad);

    DomStatus meanFaceLoad = loadMeanFace(fileInfo(MeanFace));
    result.append(meanFaceLoad);

    DomStatus weightMaskLoad = loadWeightMask(fileInfo(WeightMask));
    result.append(weightMaskLoad);

    DomStatus readLayersStatus = readLayersDoc(fileInfo(FaceLayers));
    DomStatus faceLayersLoad = loadFaceLayers();
    result.append(readLayersStatus);
    result.append(faceLayersLoad);
    */
    return result;
}

/* -------------------------- public slots ---------------------------- */

void Indi1ResourceManager::configure(const QVariantMap &aConfig)
{
    TRACEQFI << aConfig << mConfig;
    WANTDO(something);
}

void Indi1ResourceManager::initialize()
{
    TRACEQFI << mConfig;
    TODO(appendDomStatus);
    TODO(emit);
}

void Indi1ResourceManager::readFilesData()
{
    fileManager()->readFilesData();
}

void Indi1ResourceManager::readFileData(const MultiName aKey)
{
    fileManager()->readFileData(aKey);
}

void Indi1ResourceManager::setDocumentsBytes()
{
    fileManager()->setDocumentsBytes();
}

void Indi1ResourceManager::setDocumentBytes(const MultiName aKey)
{
    fileManager()->setDocumentBytes(aKey);
}

/* -------------------------- private slots ---------------------------- */

void Indi1ResourceManager::initializeBaseDir()
{
    TRACEQFI << mConfig;
    TODO(emit);
}

void Indi1ResourceManager::initializeFileSet()
{
}

/* -------------------------- private parsers ---------------------------- */

DomStatus Indi1ResourceManager::parseMainData(const QQDomElement &aMainDataDE)
{
}

DomStatus Indi1ResourceManager::parseInputBitMask(const QQDomElement &aMaskDE)
{
    TRACEQFI << aMaskDE;
    DomStatus result;

    result.dump();
    return result;
}

