#pragma once
#include "If1Resource.h"

#include <QObject>

#include "BaseDocument.h"

class IF1RESOURCE_EXPORT Resource1Loader : public QObject
{
    Q_OBJECT
public:
    explicit Resource1Loader(QObject *parent = nullptr);

public:
    DomStatus status() const { return mStatus; }

public:
    DomStatus initialize(const QQDir &aBaseDir, const QQString &aMainFileName);
    DomStatus load(const int maxLayers);
    DomStatus addDocument(const BasicName &aDocumentName, const QQFileInfo &aDocumentFileInfo);
    DomStatus addDocument(const QQFileInfo &aDocumentFileInfo);

signals:

private:
    DomStatus &status() { return mStatus; }
    Resource1Loader &it() { return *this; }


private:
    DomStatus mStatus;
    QMap<BasicName, BaseDocument *> mNameDocumentMap;

};

