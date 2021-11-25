#include "BaseVolatileSettings.h"

#include <QCoreApplication>

#include <eirType/Success.h>
#include <eirXfr/Debug.h>

BaseVolatileSettings::BaseVolatileSettings(QObject *parent)
    : QObject(parent)
{
    setObjectName("BaseVolatileSettings");
    TRACEQFI << QOBJNAME(parent) << QOBJNAME(this);
    Success success;
    QQFileInfo tTempFilePattern(QQDir::temp(), QCoreApplication::applicationName() + "-XXXXXX.ini");
    mpTempFile = new QTemporaryFile(tTempFilePattern.absoluteFilePath(), this);
    success.expectNot(nullptr == qobject_cast<QTemporaryFile*>(mpTempFile));
    if (success) success.expect(mpTempFile->open());
    if (success) mFileInfo.setFile(*mpTempFile);
    success.expect(mFileInfo.exists());
    success.expect(mFileInfo.isReadable());
    success.expect(mFileInfo.isWritable());
    if (success) EMIT(opened(mFileInfo));
    if (success) mpSettings = new QSettings(mFileInfo.absoluteFilePath(), QSettings::IniFormat, this);
    success.expectNot(nullptr == qobject_cast<QSettings*>(mpSettings));
    success.expect(mpSettings->isWritable());
    success.expect(isEmpty());
    if (success) EMIT(constructed(mpSettings));
}

int BaseVolatileSettings::count() const
{
    int result = 0;
    if (nullptr == mpSettings) return result;                           /* /====\ */
    QSettings * pSettings = mpSettings;
    QStringList tKeys = pSettings->allKeys();
    result = tKeys.count();
    return result;
}

Value BaseVolatileSettings::value(const Key &key, const Value &defValue)
{
    return settings().value(key, defValue);
}

PairList BaseVolatileSettings::extractPairs(const Key &aGroupKey)
{
    TRACEQFI << aGroupKey.toString();
    PairList result;
    if (aGroupKey.notEmpty())   settings().beginGroup(aGroupKey);
    for (Key key : settings().allKeys())
        result << Pair(key, settings().value(key));
    if (aGroupKey.notEmpty())   settings().endGroup();
    return result;
}

QQStringList BaseVolatileSettings::keyValueStringList(const Key &aGroupKey)
{
    QQStringList result;
    for (Pair pair : extractPairs(aGroupKey))
        result << keyValueString(pair);
    TRACEQFI << aGroupKey() << result;
    return result;
}

Map BaseVolatileSettings::keyValueMap(const Key &aGroupKey)
{
    TRACEQFI << aGroupKey.toString();
    Map result;
    for (Pair pair : extractPairs(aGroupKey))
        result.insert(pair.first, pair.second);
    return result;
}

QQString BaseVolatileSettings::tempFileName() const
{
    return (nullptr == mpTempFile) ? QQString() : mpTempFile->fileName();
}

bool BaseVolatileSettings::contains(const Key &aKey) const
{
    return settings().contains(aKey());
}

void BaseVolatileSettings::setValue(const Key &key, const Value &aValue)
{
    settings().setValue(key, aValue);
}

void BaseVolatileSettings::setFallback(const Key &key, const Value &aValue)
{
    if (missing(key)) setValue(key, aValue);
}

void BaseVolatileSettings::beginGroup(const Key &aGroupKey)
{
    settings().beginGroup(aGroupKey);
}

void BaseVolatileSettings::endGroup()
{
    settings().endGroup();
}

/* ------------------------- static ---------------------------- */

QQString BaseVolatileSettings::keyValueString(const Pair &aPair)
{
    return QQString("{%1=<%2>}").formatMessage(aPair.first(), aPair.second.toString());
}


