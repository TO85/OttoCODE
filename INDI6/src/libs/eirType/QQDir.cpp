#include "QQDir.h"

#include <QtCore/QCoreApplication>
#include <QtCore/QTemporaryFile>

#include <eirXfr/Debug.h>

#include "QQFileInfo.h"
#include "QQFileInfoList.h"
#include "QQStringList.h"

 const QQString QQDir::csmNulDirName("/.nul");
 const QQDir QQDir::csmNulDir(csmNulDirName);

 bool QQDir::notEmpty(Filters filters) const
 {
     return ! QDir::isEmpty(filters);
 }

 bool QQDir::canCD(const QQString aDirName) const
 {
     QQDir tDir = it();
     bool result = tDir.cd(aDirName);
     TRACEQFI << aDirName << it() << result;
     return result;
 }

 bool QQDir::tryCreate() const
 {
     QTemporaryFile tTempFile(path()+"/XXXXXX.tmp");
     return tTempFile.open();
 }

 QQString QQDir::attributes(const bool verbose) const
 {
     if (isNull())
         return "{null}";
     QQStringList result;
     if (exists())                                          result << "Exists";
     if (notExists() && verbose)                            result << "NOTexists";
     if (notRoot())                                         result << "notRoot";
     if (isRoot() && verbose)                               result << "ISroot";
     if (isReadable())                                      result << "IsReadable";
     if (notReadable() && verbose)                          result << "NOTreadable";
     if (tryCreate())                                       result << "TryCreate";
     if (notCreate() && verbose)                            result << "ISroot";
     if (isAbsolute())                                      result << "IsAbsolute";
     if (notAbsolute() && verbose)                          result << "NOTAbsolute";
     if (isRelative())                                      result << "IsRelative";
     if (notRelative() && verbose)                          result << "NOTRelative";
     if (notEmpty())                                        result << "NotEmpty";
     if (isEmpty() && verbose)                              result << "ISempty";
     return result.join(",");
}

 /* ------------------------- static -------------------------- */

QQDir QQDir::exe()
{
 QQString tArg0 = qApp->arguments().first();
 QQFileInfo tFI(tArg0);
 return tFI.dir();
}

 /* ------------------------- debug -------------------------- */

QQString QQDir::toDebugString() const
{
 return QQString("%1 %2 %3").formatMessage(path(),
            exists() ? "Exists" : "NOTexists",
            isEmpty() ? "ISempty" : "NotEmpty");
}

QQStringList QQDir::toDebugStrings(const int level) const
{
    QQStringList result;
    if (level == 0)
        result << toDebugString();
    if (level >= 1)
    {
        result << QQString("{QQDir: Path=>%1<").formatMessage(path());
        if (notAbsolute())
            result << QQString("Abs=>%1<").formatMessage(absolutePath());
    }
    if (level == 1)
        result << attributes(false);
    if (level >= 2)
    {
        result << attributes(true);
        const QQFileInfoList tFileInfos = entryInfoList(QDir::Files);
        const QQFileInfoList tDirsInfos = entryInfoList(QDir::Dirs | QDir::NoDotAndDotDot);
        result << QQString("%1 Directories").formatMessage(tDirsInfos.count());
        if (level >= 3)
            for ( QQFileInfo fi : tDirsInfos )
                result << fi.fileName();
        result << QQString("%1 Files").formatMessage(tFileInfos.count());
        if (level >= 3)
            for ( QQFileInfo fi : tFileInfos )
                result << fi.fileName();
    }
    result << QQString("<QQDir}");
    return result;
}

 /* ------------------------- non-member -------------------------- */

 QDebug operator << (QDebug dbg, const QQDir &dir)
 {
#if 0
     dbg << dir.toDebugString(); return dbg;
#else
     for ( QQString s : dir.toDebugStrings(2)() )
         dbg << s;
     return dbg;
#endif
 }
