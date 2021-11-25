#pragma once
#include "eirXml.h"

#include <QtCore/QObject>

#include <QtCore/QMap>

#include <eirType/MultiName.h>
#include <eirType/MultiNameList.h>
#include <eirType/QQDir.h>
#include <eirType/QQFileInfo.h>
#include <eirType/QQString.h>
#include <eirType/QQStringList.h>

class DomFile;

class EIRXML_EXPORT DomFileManager : public QObject
{
    Q_OBJECT
public:
    explicit DomFileManager(QObject *parent = nullptr);
    explicit DomFileManager(const QQDir &aBaseDir, QObject *parent = nullptr);
    ~DomFileManager();

public:
    QQFileInfo fileInfo(const MultiName &aKey);
    QQStringList filePathNameList() const;
    bool contains(const MultiName aKey) const;
    bool isValidIndex(const int index) const;
    MultiName key(const int index);
    DomFile *entry(const MultiName &aKey);
    DomFile *entry(const int index);
    int fileCount() const { return mKeyFileMap.count(); }
    MultiNameList keys() const { return mKeyFileMap.keys(); }
    MultiNameList keyList() const { return mKeyList; }
    QQDir baseDir() const { return mBaseDir; }
    QQDomElement childElement(const MultiName aKey, const int ix);
    virtual QQStringList toInfoStrings(const int index, const int level=3);

public slots:
    void clear();
    void setBaseDir(const QQDir &aBaseDir) { mBaseDir = aBaseDir; }
    void addFile(const QQFileInfo aFileInfo) {MUSTUSE(aFileInfo);}
    void addFiles(const QQFileInfoList aFileInfoList) {MUSTUSE(aFileInfoList);}
    void addFile(const QQString aFileName) {MUSTUSE(aFileName);}
    void addFile(const MultiName &aKey, const QQFileInfo aFileInfo);
    void addFile(const MultiName &aKey, const QQString aFileName);

    void readAllFileBytes();
    void setAllDocumentBytes();
    void loadAllChildElements();
    void readFileBytes(const MultiName aKey);
    void setDocumentBytes(const MultiName aKey);
    void loadChildElements(const MultiName aKey);

public: // debug
    QQStringList toDebugStrings(const MultiName &aKey=MultiName(),
                                const bool expand=false) const;
    void dump(const MultiName &aKey=MultiName(),
              const bool expand=false) const;

private:
    QQDir mBaseDir;
    MultiNameList mKeyList;
    QMap<MultiName, DomFile *> mKeyFileMap;
};

