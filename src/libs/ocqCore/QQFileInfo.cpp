#include "QQFileInfo.h"


QQFileInfo::QQFileInfo(const QQString &fileName)
    : QFileInfo(fileName)
{

}

QQFileInfo::QQFileInfo(const QQDir &dir, const QQString &fileName)
    : QFileInfo(dir, fileName)
{

}

bool operator == (const QQFileInfo &lfi, const QQFileInfo &rfi)
{
    return lfi.absoluteFilePath() == rfi.absoluteFilePath();
}

bool operator <  (const QQFileInfo &lfi, const QQFileInfo &rfi)
{
    return lfi.absoluteFilePath() <  rfi.absoluteFilePath();
}

#if 0
#include "QQFileInfo.h"

#include <QtCore/QProcess>

#include <eirXfr/Debug.h>

#include "QQDir.h"
#include "QQStringList.h"

EIRTYPE_EXPORT QQFileInfo nullFileInfo = QQFileInfo(QProcess::nullDevice());

QQFileInfo::QQFileInfo(const QQDir &pathDir, const QQString &fileName)
    : QFileInfo(pathDir, fileName) {;}

QQFileInfo::QQFileInfo(const QDir &dir, const QQString &fileName)
    : QFileInfo(dir, fileName) {;}

bool QQFileInfo::tryIsFile(const QIODevice::OpenMode mode) const
{
    bool canOpenFile = tryIsFile(absoluteFilePath(), mode);
    return canOpenFile;
}

bool QQFileInfo::QQFileInfo::tryHasDir() const
{
    QQString absolutePath = dir().absolutePath();
    bool canCdDir = tryIsDir(absolutePath);
    return canCdDir;
}

void QQFileInfo::setFile(const QQString &aFileName)
{
    QQFileInfo newFI(dir(), aFileName);
    swap(newFI);
}

void QQFileInfo::setBaseFileName(const QQString &aBaseName)
{
    const QQString cSuffix = suffix();
    const QQString cNewName = aBaseName + "." + cSuffix;
    setFile(cNewName);
    TRACEQFI << aBaseName << it();
}

void QQFileInfo::setSuffix(const QQString &aSuffix)
{
    QQString tFileName = completeBaseName() + "." + aSuffix;
    setFile(tFileName);
    TRACEQFI << fileName() << aSuffix << it();
}

void QQFileInfo::setDir(const QQDir &aDir)
{
    QQFileInfo newFI(aDir, fileName());
    TRACEQFI << aDir << it() << newFI;
    swap(newFI);
}

void QQFileInfo::appendFileName(const QQString &s, const QQString &glue)
{
    QQString tBaseName = completeBaseName();
    tBaseName += glue + s;
    setBaseFileName(tBaseName);
    TRACEQFI << completeBaseName() << tBaseName << it();
}

void QQFileInfo::nullify()
{
    setFile(QQString());
}

bool QQFileInfo::isNull() const
{
    return fileName().isEmpty();
}

QQDir QQFileInfo::dir() const
{
    return QQDir(QFileInfo::dir());
}

QQString QQFileInfo::attributes() const
{
    if (isNull()) return "isNull ";
    QQStringList result;
    if (exists())           result << "Exists";
    if (isRoot())           result << "Root";
    if (isRelative())       result << "Relative";
    if (isAbsolute())       result << "Absolute";
    if (tryHasDir())        result << "HasDir";
    if (tryIsDir())         result << "Dir";
    if (tryIsFile())        result << "File";
    if (isReadable())       result << "Readable";
    if (isWritable())       result << "Writable";
    if (isExecutable())     result << "Executable";
    return result.join(",");
}

QQString QQFileInfo::allAttributes() const
{
    if (isNull()) return "isNull ";
    QQStringList result;
    result << ((exists())           ? "Exists"          : "notExists");
    result << ((isRoot())           ? "isRoot"          : "notRoot");
    result << ((isRelative())       ? "isRelative"      : "notRelative");
    result << ((isAbsolute())       ? "isAbsolute"      : "notAbsolute");
    result << ((tryHasDir())        ? "tryHasDir"       : "notHasDir");
    result << ((tryIsDir())         ? "tryIsDir"        : "notIsDir");
    result << ((tryIsFile())        ? "tryIsFile"       : "notIsFile");
    result << ((isReadable())       ? "isReadable"      : "notReadable");
    result << ((isWritable())       ? "isWritable"      : "notWritable");
    result << ((isExecutable())     ? "isExecutable"    : "notExecutable");
    return result.join(",");
}

bool QQFileInfo::isSuffix(const QQString &aOther) const
{
    return aOther.equals(suffix());
}

/* ----------------------- static public --------------------------------- */

bool QQFileInfo::tryIsFile(const QQString &filePathName,
                           const QIODevice::OpenMode mode)
{
    QFile file(filePathName);
    bool canOpenFile = file.open(QIODevice::ExistingOnly | mode);
    return canOpenFile;
}

bool QQFileInfo::tryIsDir(const QQString &pathName)
{
    QDir tryDir;
    bool canCdDir = tryDir.cd(pathName);
    return canCdDir && ! tryIsFile(pathName);
}

/* ------------------------- debug ------------------------ */

QStringList QQFileInfo::toDebugStrings() const
{
    if (isNull())
        return QStringList() << "{QQFileInfo: null}";                   /* /====\ */
    QStringList result;
    result << QQString("{QQFileInfo:> Dir=[%1] FileName=[%2]")
            .arg(dir().path(), fileName());
    result << QQString("   %1 @%2}")
            .arg(allAttributes(), fileTime(QFile::FileModificationTime).toString());
    result << QString("   Abs: [%1]").arg(absoluteFilePath());
    result << "   <QQFileInfo}";
    return result;
}

/* ------------------------- non-member ------------------------ */

QDebug operator << (QDebug dbg, const QQFileInfo &fi)
{
    for (QString s : fi.toDebugStrings())
        dbg << s << Qt::endl;
    return dbg;
}


#endif
