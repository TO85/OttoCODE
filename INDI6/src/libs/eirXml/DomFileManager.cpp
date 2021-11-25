#include "DomFileManager.h"

#include <eirType/MultiNameList.h>

#include "DomFile.h"

DomFileManager::DomFileManager(QObject *parent)
    : QObject(parent)
{
    setObjectName("DomFileManager");
}

DomFileManager::DomFileManager(const QQDir &aBaseDir, QObject *parent)
    : QObject(parent)
    , mBaseDir(aBaseDir)
{
    setObjectName("DomFileManager:"+aBaseDir.dirName());
    TRACEQFI << aBaseDir << QOBJNAME(parent) << QOBJNAME(this);
}

DomFileManager::~DomFileManager()
{
    clear();
}

QQFileInfo DomFileManager::fileInfo(const MultiName &aKey)
{
    return entry(aKey)->fileInfo();
}

QQStringList DomFileManager::filePathNameList() const
{
    QQStringList result;
    for (DomFile *pDF : mKeyFileMap)
        result.append(pDF->fileInfo().absoluteFilePath());
    return result;
}

bool DomFileManager::contains(const MultiName aKey) const
{
    bool result = mKeyFileMap.contains(aKey);
    if ( ! result) ERROR << Q_FUNC_INFO << aKey();
    return result;
}

bool DomFileManager::isValidIndex(const int index) const
{
    return index >= 0 && index < filePathNameList().count();
}

MultiName DomFileManager::key(const int index)
{
    return isValidIndex(index) ? keyList()[index] : MultiName();
}

DomFile *DomFileManager::entry(const MultiName &aKey)
{
    //TRACEQFI << aKey() << contains(aKey);
    AEXPECT(contains(aKey));
    return mKeyFileMap[aKey];
}

DomFile *DomFileManager::entry(const int index)
{
    return entry(key(index));
}

QQDomElement DomFileManager::childElement(const MultiName aKey, const int ix)
{
    DomFile *pFile = entry(aKey);
    return (ix >=0 && ix < pFile->childElementCount())
            ? pFile->childElement(ix)
            : QQDomElement();

}

QQStringList DomFileManager::toInfoStrings(const int index, const int level)
{
    QQStringList result;
    NEEDDO(it)
#if 0 // NEEDDO

    result << "BaseDir" + mBaseDir.path();
    for ( MultiName tKey : mKeyFileMap.keys() )
    {
        DomFile * pDF = mKeyFileMap.value(tKey);
        if (expand)
            result << pDF->toDebugStrings();
        else
            result << tKey + ": " + pDF->toDebugString();
    }
    result << "<DomFileManager}";
#endif
    return result;
}

void DomFileManager::clear()
{
    for (DomFile * pDF : mKeyFileMap.values())
    {
        pDF->clear();
        pDF->deleteLater();
    }
    mKeyFileMap.clear();
    mKeyList.clear();
}

void DomFileManager::addFile(const MultiName &aKey, const QQFileInfo aFileInfo)
{
    TRACEQFI << aKey() << aFileInfo;
    DomFile * tDomFile = new DomFile(aFileInfo, this);
    AEXPECTPTR(tDomFile);
    tDomFile->setKey(aKey);
    mKeyFileMap.insert(aKey, tDomFile);
    mKeyList.append(aKey);
}

void DomFileManager::addFile(const MultiName &aKey, const QQString aFileName)
{
    TRACEQFI << aKey() << aFileName;
    addFile(aKey, QQFileInfo(mBaseDir, aFileName));
}

void DomFileManager::readAllFileBytes()
{
    TRACEQFI << QOBJNAME(this);
    for (auto tKey : keys()) readFileBytes(tKey);
    dump();
    // TODO(emit);
}

void DomFileManager::setAllDocumentBytes()
{
    TRACEQFI << QOBJNAME(this);
    for (auto tKey : keys()) setDocumentBytes(tKey);
    dump();
    // TODO(emit);
}

void DomFileManager::loadAllChildElements()
{
    TRACEQFI << QOBJNAME(this);
    for (auto tKey : keys()) loadChildElements(tKey);
    dump();
}

void DomFileManager::readFileBytes(const MultiName aKey)
{
    TRACEQFI << QOBJNAME(this);
    // TODO(slots&DomStatus);
    const DomFile *tFilePtr = entry(aKey);
    const QQFileInfo tFileInfo = tFilePtr->fileInfo();
    QFile * tFile = new QFile(tFileInfo.absoluteFilePath(), this);
    AEXPECTPTR(tFile);
    WEXPECT(tFile->open(QIODevice::Text | QIODevice::ReadOnly));
    WEXPECT(tFile->isReadable() && tFile->isOpen());
    QByteArray tBytes = tFile->readAll();
    WEXPECTNOT(tBytes.isEmpty());
    entry(aKey)->setBytes(tBytes);
    entry(aKey)->dump();
    // TODO(emit);
}

void DomFileManager::setDocumentBytes(const MultiName aKey)
{
    TRACEQFI << aKey() << QOBJNAME(this);
    //TODO(slots&DomStatus);
    DomFile *tFilePtr = entry(aKey);
    const QQByteArray tBytes = tFilePtr->bytes();
    QQDomDocument tDoc;
    WEXPECT(tDoc.setContent(tBytes));
    WEXPECT(tDoc.notNull() && tDoc.isDocument());
    entry(aKey)->setDocument(tDoc);
    entry(aKey)->dump();
    //TODO(emit);
}

void DomFileManager::loadChildElements(const MultiName aKey)
{
    TRACEQFI << aKey() << QOBJNAME(this);
    DomFile *tFilePtr = entry(aKey);
    tFilePtr->loadChildElements();
}

QQStringList DomFileManager::toDebugStrings(const MultiName &aKey,
                                            const bool expand) const
{
    QQStringList result;
    const MultiNameList tKeyList
            = aKey.isEmpty() ? mKeyFileMap.keys() : MultiNameList() << aKey;

    result << "{DomFileManager:>";
    result << "BaseDir" + mBaseDir.path();
    for ( MultiName tKey : mKeyFileMap.keys() )
    {
        DomFile * pDF = mKeyFileMap.value(tKey);
        if (expand)
            result << pDF->toDebugStrings();
        else
            result << tKey + ": " + pDF->toDebugString();
    }
    result << "<DomFileManager}";
    return result;
}

void DomFileManager::dump(const MultiName &aKey,
                          const bool expand) const
{
    for (QQString s : toDebugStrings(aKey, expand)())
        DUMP << s;
}
