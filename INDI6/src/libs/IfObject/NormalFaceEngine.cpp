#include "NormalFaceEngine.h"

#include <eirXfr/Debug.h>

#include "NormalFaceEntry.h"

NormalFaceEngine::NormalFaceEngine(QObject *parent)
    : QObject(parent)
{
    setObjectName("NormalFaceEngine");
    TRACEQFI << QOBJNAME(this) << QOBJNAME(parent);
}

NormalFaceEntry *NormalFaceEngine::entry(const Uid uid)
{
    AEXPECT(mUidFaceEntryHash.contains(uid));
    return mUidFaceEntryHash.value(uid);
}

ImageObject *NormalFaceEngine::frameImageObject(const Uid uid)
{
    AEXPECT(mImageObjectHash.contains(uid));
    return mImageObjectHash.value(uid);
}

QQImage NormalFaceEngine::frameImage(const Uid uid)
{
    AEXPECT(mImageObjectHash.contains(uid));
    return *mImageObjectHash.value(uid);
}

void NormalFaceEngine::add(NormalFaceEntry *pEntry)
{
    TRACEQFI << *pEntry << mUidFaceEntryHash.count();
    mUidFaceEntryHash.insert(pEntry->uid(), pEntry);
}

Uid NormalFaceEngine::newFaceEntry(const Uid frameImageUid, const ObjectResultItem &aFaceResultItem, const ObjectResults &aEyeResults)
{
    TRACEQFI << frameImageUid << aFaceResultItem << aEyeResults;
    NormalFaceEntry tEntry(this);
    Uid result = tEntry.uid();
    tEntry.set(frameImageUid, aFaceResultItem, aEyeResults);
    add(&tEntry);
    TRACE << result.trace();
    return result;
}

void NormalFaceEngine::start(const Uid entryUid)
{
    NormalFaceEntry *pEntry = entry(entryUid);
    if (pEntry) pEntry->start();
}

void NormalFaceEngine::process(const Uid entryUid)
{
    NormalFaceEntry *pEntry = entry(entryUid);
    if (pEntry) pEntry->process();
}

const QSettings::SettingsMap &NormalFaceEngine::config() const
{
    return mConfig;
}

void NormalFaceEngine::setConfig(const QSettings::SettingsMap &newConfig)
{
    mConfig = newConfig;
}

