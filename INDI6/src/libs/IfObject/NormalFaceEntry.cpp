#include "NormalFaceEntry.h"

#include <eirGui/QQTransform.h>
#include <eirXfr/Debug.h>

#include "NormalFaceEngine.h"
#include "ObjectResults.h"

class NormalFaceEntryData : public QSharedData
{
public:
    enum Mode { $null=0, Fast, Slow, $size};

public:
    const QSettings::SettingsMap &config() const { return mConfig; }
    void setConfig(const QSettings::SettingsMap &newConfig) { mConfig = newConfig; }
    void process(const Mode aMode=Fast,
                 const QSettings::SettingsMap &localConfig=QSettings::SettingsMap());

private: // slot calls
    void overCrop() {MUSTDO(it);} // MUSTDO
    void rotate() {MUSTDO(it);} // MUSTDO
    void centerEyes() {MUSTDO(it);} // MUSTDO
    void scale() {MUSTDO(it);} // MUSTDO
    void translate() {MUSTDO(it);} // MUSTDO
    void size() {MUSTDO(it);} // MUSTDO

public:
    Uid FrameImageUid;
    QSettings::SettingsMap mConfig;
    ObjectResultItem FaceResultItem;
    ObjectResults EyeResults;
    EyeLine::List EyeLineList;
    QQSize NormalSize;
    EyeLine NormalEyeLine;
    Mode NormalMode;
    QQImage NormalImage;

private:
    QQTransform Transform;
    QQImage OverCropImage;
    QQImage RotateImage;
    QQImage CenterEyesImage;
    QQImage ScaleImage;
    QQImage TranslateImage;
    QQImage SizedImage;
};

NormalFaceEntry::NormalFaceEntry(NormalFaceEngine *parent)
    : QObject(parent)
    , mpEngine(parent)
    , data(new NormalFaceEntryData)
{
    TRACEQFI << QOBJNAME(mpEngine);
}

NormalFaceEntry::NormalFaceEntry(const NormalFaceEntry &other)
    : QObject(other.parent())
    , data(other.data)
{

}

NormalFaceEntry &NormalFaceEntry::operator=(const NormalFaceEntry &other)
{
    if (this != &other)
        data.operator=(other.data);
    return *this;
}

NormalFaceEntry::~NormalFaceEntry()
{

}

void NormalFaceEntry::set(const Uid aFrameImageUid,
                          const ObjectResultItem &aFaceResultItem,
                          const ObjectResults &aEyeResults)
{
    TRACEQFI << aFrameImageUid << aFaceResultItem
             << aEyeResults << uid().trace();
    setFrameImageUid(aFrameImageUid),
    setFaceResultItem(aFaceResultItem),
            setEyeResults(aEyeResults);
}

void NormalFaceEntry::process()
{
    MUSTDO(it); // MUSTDO
}

const Uid &NormalFaceEntry::frameImageUid() const
{
    static Uid nullUid;
    return data ? data->FrameImageUid : nullUid;
}

const QQImage NormalFaceEntry::frameImage() const
{
    static QQImage nullImage;
    return data ? mpEngine->frameImage(frameImageUid()) : nullImage;
}

const ObjectResultItem &NormalFaceEntry::faceResultItem() const
{
    static ObjectResultItem nullORI;
    return data ? data->FaceResultItem : nullORI;
}

const ObjectResults &NormalFaceEntry::eyeResults() const
{
    static ObjectResults nullOR;
    return data ? data->EyeResults : nullOR;
}

void NormalFaceEntry::setFrameImageUid(const Uid &newFrameImageUid)
{
    if (data) data->FrameImageUid = newFrameImageUid;
}

void NormalFaceEntry::setFaceResultItem(const ObjectResultItem &newFaceResultItem)
{
    if (data) data->FaceResultItem = newFaceResultItem;
}

void NormalFaceEntry::setEyeResults(const ObjectResults &newEyeResults)
{
    if (data) data->EyeResults = newEyeResults;
}

/* ----------------------- non-member --------------------- */

QDebug operator << (QDebug dbg, const NormalFaceEntry &fe)
{
    dbg << "{NormalFaceEntry:>" << fe.uid().trace() << Qt::endl
        << fe.frameImage() << Qt::endl
        << fe.faceResultItem() << Qt::endl
        << fe.eyeResults() << Qt::endl;
    return dbg;
}
