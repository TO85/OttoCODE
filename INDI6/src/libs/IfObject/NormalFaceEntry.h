#pragma once

#include <QtCore/QObject>

#include <QtDebug>
#include <QtCore/QSettings>
#include <QtGui/QImage>

#include <eirBase/Uid.h>
#include <eirGui/QQImage.h>

#include "ObjectResults.h"
class NormalFaceEngine;
class NormalFaceEntryData;

class NormalFaceEntry : public QObject
{
    Q_OBJECT
public:
    explicit NormalFaceEntry(NormalFaceEngine *parent);
    NormalFaceEntry(const QSettings::SettingsMap &config, NormalFaceEngine *parent);
    NormalFaceEntry(const NormalFaceEntry &other);
    NormalFaceEntry &operator=(const NormalFaceEntry &other);
    ~NormalFaceEntry();

public: // getters
    Uid uid() const { return cmFaceEntryUuid; }
    const Uid &frameImageUid() const;
    const QQImage frameImage() const;
    const ObjectResultItem &faceResultItem() const;
    const ObjectResults &eyeResults() const;

public slots:
    void set(const Uid aFrameImageUid,
             const ObjectResultItem &aFaceResultItem,
             const ObjectResults &aEyeResults);
    void start() {MUSTDO(it);} // MUSTDO
    void process();

public: // static
    static const QQImage &frameImage(const Uid faceEntryUid);


private: // setters
    void setFrameImageUid(const Uid &newFrameImageUid);
    void setFaceResultItem(const ObjectResultItem &newFaceResultItem);
    void setEyeResults(const ObjectResults &newEyeResults);

private:
    NormalFaceEngine *mpEngine=nullptr;
    const Uid cmFaceEntryUuid=Uid(true);

signals:


private:
    QSharedDataPointer<NormalFaceEntryData> data;
};

extern IFOBJECT_EXPORT QDebug operator << (QDebug dbg, const NormalFaceEntry &fe);
