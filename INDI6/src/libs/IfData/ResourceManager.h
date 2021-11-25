#pragma once
#include "IfData.h"

#include <QObject>
#include <eirXml/DomFileManager.h>

#include <eirType/MultiName.h>
#include <eirType/MultiNameList.h>
#include <eirType/QQVariant.h>
#include <eirType/QQVector.h>

#include "ResourceValues.h"
//class ResourceSet;

class IFDATA_EXPORT ResourceManager : public DomFileManager
{
    Q_OBJECT
public:
    typedef QQVector<qreal> FloatVector;

public:
    explicit ResourceManager(QObject *parent = nullptr);

public:
    const int &maxLoadLayers() const;
    void setMaxLoadLayers(const int &newMaxLoadLayers);

public: // accessors
    ResourceValues values() const { return mResourceValues; }
    ResourceValues &values() { return mResourceValues; }
    bool isLoadValid() const { NEEDDO(it); return true; /* NEEDDO */ }
    QQFileInfo baseFileInfo() const;
    virtual QQStringList toInfoStrings(const int index, const int level=1);

public: // commands
    bool process();
    void addAllFiles();

public slots:
    void start();


private slots:
    void readAllFiles();
    void setAllDocuments();
    void loadAllElements();
    void parseAllData();
    void clearFiles();
    void finish();

private slots:
    void addFile(const int &index);
    void readFile(const MultiName &aKey);
    void setDocument(const MultiName &aKey);
    void loadElements(const MultiName &aKey);

private slots:
    void parseBaseData();
    void parseBitMask();
    void parseMeanFace();
    void parseWeightMask();
    void parseFaceLayers();

public: // static
    static const MultiNameList keyNameList() { return csmKeyList; }
    static int keyNameCount() { return csmKeyList.count(); }
    static const MultiName key(const int index);
    static int indexOfKey(const MultiName &aKey);

public:


signals:
    void started();
    void allFilesAdded();
    void allFilesRead();
    void allDocumentsSet();
    void allElementsLoaded();
    void allDataParsed();
    void finished();

    void fileAdded(const MultiName &aKey);
    void fileRead(const MultiName &aKey);
    void documentSet(const MultiName &aKey);
    void elementsLoaded(const MultiName &aKey);
    void dataParsed(const MultiName &aKey);

private:
    ResourceValues mResourceValues;
    int mMaxLoadLayers=320;
    const static MultiNameList csmKeyList;
};

