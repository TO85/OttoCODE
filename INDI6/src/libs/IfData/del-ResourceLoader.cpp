#include "del-ResourceLoader.h"

#include <eirXfr/Debug.h>

ResourceLoader::ResourceLoader(QObject *parent)
    : QObject(parent)
{;}

ResourceLoader::ResourceLoader(const QQString &aBaseDirName, QObject *parent)
    : QObject(parent)
{
    setBaseDir(aBaseDirName);
}

bool ResourceLoader::setBaseDir(const QQString &aBaseDirName)
{
    TRACEQFI << aBaseDirName;
    QQDir tDir(QDir::current());
    bool result = tDir.cd(aBaseDirName);
    result &= tDir.exists() && tDir.isReadable();
    if (result) mBaseDir = tDir;
    return result;
}

