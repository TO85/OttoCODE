#include "ResourceManager.h"

#include <eirXfr/Debug.h>
#include <eirXml/DomFile.h>
#include <eirXml/QQDomElement.h>

#include "ResourceBaseData.h"
#include "ResourceBitMask.h"
#include "ResourceFloatVector.h"
#include "ResourceValues.h"

const MultiNameList ResourceManager::csmKeyList
    = MultiNameList() << "Face1" << "BitMask" << "FaceLayers"
                      << "MeanFace" << "WeightMask";


ResourceManager::ResourceManager(QObject *parent)
    : DomFileManager(parent)
{
    setObjectName("ResourceManager");
    TRACEQFI << QOBJNAME(parent) << QOBJNAME(this);
}

const int &ResourceManager::maxLoadLayers() const
{
    return mMaxLoadLayers;
}

void ResourceManager::setMaxLoadLayers(const int &newMaxLoadLayers)
{
    mMaxLoadLayers = newMaxLoadLayers;
}

QQFileInfo ResourceManager::baseFileInfo() const
{
    return QQFileInfo(baseDir(), keyNameList().first()+".xml");
}

QQStringList ResourceManager::toInfoStrings(const int index, const int level)
{
    QQStringList result = DomFileManager::toInfoStrings(index, level);
    MUSTDO(bySetMember); // MUSTDO
}

void ResourceManager::start()
{
    TRACEQFI << QOBJNAME(this);
    connect(this, &ResourceManager::started, this, &ResourceManager::addAllFiles);
    connect(this, &ResourceManager::allFilesAdded, this, &ResourceManager::readAllFiles);
    connect(this, &ResourceManager::allFilesRead, this, &ResourceManager::setAllDocuments);
    connect(this, &ResourceManager::allDocumentsSet, this, &ResourceManager::loadAllElements);
    connect(this, &ResourceManager::allElementsLoaded, this, &ResourceManager::parseAllData);
    connect(this, &ResourceManager::allDataParsed, this, &ResourceManager::finish);
    EMIT(started());
}

bool ResourceManager::process()
{
    TRACEQFI << QOBJNAME(this);
    readAllFiles();
    setAllDocuments();
    loadAllElements();
    parseAllData();
    finish();
    return isLoadValid();
}

void ResourceManager::clearFiles()
{
    TRACEQFI << QOBJNAME(this);
    DomFileManager::clear();
}

void ResourceManager::addAllFiles()
{
    TRACEQFI << QOBJNAME(this);
    for (int ix = 0; ix < keyNameList().count(); ++ix)
        addFile(ix);
    // NEEDDO ?
    DUMP << toDebugStrings();
    EMIT(allFilesAdded());
}

void ResourceManager::readAllFiles()
{
    TRACEQFI << QOBJNAME(this);
    for (auto aKey : DomFileManager::keys())
        readFile(aKey);
    // NEEDDO ?
    EMIT(allFilesRead());
}

void ResourceManager::setAllDocuments()
{
    TRACEQFI << QOBJNAME(this);
    for (auto aKey : DomFileManager::keys())
        setDocument(aKey);
    // NEEDDO ?
    EMIT(allDocumentsSet());
}

void ResourceManager::loadAllElements()
{
    TRACEQFI << QOBJNAME(this);
    for (auto aKey : DomFileManager::keys())
        loadElements(aKey);
    // NEEDDO ?
    EMIT(allElementsLoaded());
}

void ResourceManager::parseAllData()
{
    TRACEQFI << QOBJNAME(this) << DomFileManager::toDebugStrings();
    parseBaseData();
    parseBitMask();
    parseMeanFace();
    parseWeightMask();
    parseFaceLayers();
    EMIT(allDataParsed());
}

void ResourceManager::finish()
{
    TRACEQFI << QOBJNAME(this);
    // TODO: more?
    EMIT(finished());
}

void ResourceManager::addFile(const int &index)
{
    MultiName tFileKey = key(index);
    QQString tFileName = key(index) + ".xml";
    QQFileInfo qfi(baseDir(), tFileName.string(QQString::Squeeze));
    TRACEQFI << index << qfi;
    DomFileManager::addFile(tFileKey, qfi);
    EMIT(fileAdded(tFileKey));
}

void ResourceManager::readFile(const MultiName &aKey)
{
    TRACEQFI << aKey();
    DomFileManager::readFileBytes(aKey);
    EMIT(fileRead(aKey));
}

void ResourceManager::setDocument(const MultiName &aKey)
{
    TRACEQFI << aKey();
    DomFileManager::setDocumentBytes(aKey);
    EMIT(documentSet(aKey));
}

void ResourceManager::loadElements(const MultiName &aKey)
{
    TRACEQFI << aKey();
    DomFileManager::loadChildElements(aKey);
    EMIT(elementsLoaded(aKey));
}

void ResourceManager::parseBaseData()
{
    TRACEQFI << 0 << key(0)();
    DomFile *pDF = entry("Face1");
    QQDomElement tDE = pDF->rootElement();
    ResourceBaseData tRBD(tDE);
    DUMPVAL(tRBD.toInfoStrings(3));
    AEXPECT(tRBD.isValid());
    values().setResourceBaseData(tRBD);
    EMIT(dataParsed(key(0)));
}

void ResourceManager::parseBitMask()
{
    TRACEQFI << 1 << key(1)();
    DomFile *pDF = entry("BitMask");
    pDF->dump();
    QQDomElement tRootDE = pDF->rootElement();
    tRootDE.dump();
    QQDomElement tInputDE = tRootDE.childElement("INDI-EigenFaceGenerator-BitMask");
    tInputDE.dump();
    QQDomElement tOutputDE = tRootDE.childElement("INDI-EigenFaceGenerator-OutputMask");
    tOutputDE.dump();
    ResourceBitMask tInputMask(ResourceType::InputMask, tInputDE);
    ResourceBitMask tOutputMask(ResourceType::OutputMask, tOutputDE);
    values().setResourceBitMask(ResourceType::InputMask, tInputMask);
    values().setResourceBitMask(ResourceType::OutputMask, tOutputMask);
    NEEDDO(more); // NEEDDO(more)
    EMIT(dataParsed(key(1)));
}

void ResourceManager::parseMeanFace()
{
    TRACEQFI << 2 << key(2)();
    NEEDDO(parseMeanFace); // NEEDDO(parseMeanFace)
    EMIT(dataParsed(key(2)));
}

void ResourceManager::parseWeightMask()
{
    TRACEQFI << 3 << key(3)();
    NEEDDO(parseWeightMask); // NEEDDO(parseWeightMask)
    EMIT(dataParsed(key(3)));
}

void ResourceManager::parseFaceLayers()
{
    TRACEQFI << 4 << key(4)();
    NEEDDO(parseFaceLayers); // NEEDDO(parseFaceLayers)
    EMIT(dataParsed(key(4)));
}

/* ----------------------- static ------------------------- */

const MultiName ResourceManager::key(const int index)
{
    return keyNameList()[index];
}

int ResourceManager::indexOfKey(const MultiName &aKey)
{
    for (int ix = 0; ix < keyNameCount(); ++ix)
        if (aKey.compare(key(ix)))
            return ix;
    return -1;
}


