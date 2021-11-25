/* @file: NormalFaceEngine.h in {INDI6 repo}./src/libs/IfObject */
#pragma once
#include "IfObject.h"

#include <QtCore/QObject>

#include <QtDebug>
#include <QtCore/QMetaType>
#include <QtCore/QSettings>
#include <QtGui/QImage>

#include <eirBase/Uid.h>
#include <eirGui/ImageObject.h>
#include <eirGui/QQImage.h>

#include "ObjectResults.h"
class NormalFaceEntry;

class IFOBJECT_EXPORT NormalFaceEngine : public QObject
{
    Q_OBJECT
public:
    explicit NormalFaceEngine(QObject *parent = nullptr);
    NormalFaceEntry *entry(const Uid uid);
    ImageObject *frameImageObject(const Uid uid);
    QQImage frameImage(const Uid uid);
    Uid add(const QQImage &aFrameImage);
    Uid newFaceEntry(const Uid frameImageUid,
                     const ObjectResultItem &aFaceResultItem,
                     const ObjectResults &aEyeResults);
    const QSettings::SettingsMap &config() const;
    void setConfig(const QSettings::SettingsMap &newConfig);

public slots:
    void start(const Uid entryUid);
    void process(const Uid entryUid);

private:
    void add(NormalFaceEntry *pEntry);

signals:

private:
    QSettings::SettingsMap mConfig;
    ImageObject::Hash mImageObjectHash;
    QHash<Uid, NormalFaceEntry *> mUidFaceEntryHash;
};

