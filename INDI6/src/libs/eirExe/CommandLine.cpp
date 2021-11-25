// file: {EIRC2 repo}/./src/libs/eirExe/CommandLine.cpp
#include "CommandLine.h"

#include <QCoreApplication>
#include <QDir>
#include <QTimer>

//#include <APP>
#include <eirXfr/Debug.h>
#include <eirType/QQFileInfo.h>
#include <eirType/QQFileInfoList.h>
#include <eirType/QQString.h>

#include "AppSettings.h"

CommandLine::CommandLine(QObject *parent)
    : QObject(parent)
    , cmExeArgumentList(QCoreApplication::arguments())
{
    TRACEFN
    setObjectName("CommandLine");
    EMIT(constructed());
}


CommandLine::ExpandDirResultList CommandLine::expandDirResults() const
{
    return mExpandDirResultList;
}

int CommandLine::positionalArgumentSize() const
{
    return positionalArgumentList().size();
}

QQStringList CommandLine::positionalArgumentList() const
{
    return mPositionalArgumentList;
}

QQString CommandLine::firstPositionalArgument() const
{
    return positionalArgumentSize()
            ? mPositionalArgumentList.first() : QQString();
}

QQString CommandLine::takePositionalArgument()
{
    TRACEQFI << firstPositionalArgument();
    if (positionalArgumentSize())
        ++mPositionalArgumentsTaken;
    return positionalArgumentSize()
            ? mPositionalArgumentList.takeFirst() : QString();
}

int CommandLine::positionalArgumentsTaken() const
{
    TRACEQFI << mPositionalArgumentsTaken;
    return mPositionalArgumentsTaken;
}

const QQStringList CommandLine::exeArguments(bool withNumbers) const
{
    QQStringList argList = cmExeArgumentList;
    if (withNumbers)
        for (int x = 0; x < argList.size(); ++x)
            argList[x].prepend(QString("%1. ").arg(x,3));
    return argList;
}

const QQFileInfo CommandLine::exeFileInfo() const
{
    return mExeFileInfo;
}

void CommandLine::process()
{
    TRACEQFI << "ExeArgs:" << cmExeArgumentList;
    mRemainingArgumentList = cmExeArgumentList;
    mExeFileInfo = QQFileInfo(QQString(mRemainingArgumentList.takeFirst()));

    parseQtOptions();
    extractDirectiveArguments();
    expandFileArguments();
    stripSettings();
    TRACE << "Settings:";
//    DUMP << STG->toDebugStringList();
    TRACE << "Post Settings:" << mRemainingArgumentList;
    expandDirectories();
    TRACE << "Remaining:" << mRemainingArgumentList;
    mPositionalArgumentList = mRemainingArgumentList;
    TRACE << "PosArgs:" << mPositionalArgumentList;
    dump();
} // process()

void CommandLine::expandDirectories(const int recurseDepth)
{
    TRACEQFI << "recurseDepth:" << recurseDepth;
    dumpPositionalArgs();
    WANTUSE(recurseDepth)
    WARN << "Only recurseDepth=1 for  now";

    QQStringList expandedArgs, ignoredArgs;
    while (mRemainingArgumentList.notEmpty())
    {
        QQString argIn = mRemainingArgumentList.takeFirst();
        if (QQFileInfo::tryIsFile(argIn))
        {
            expandedArgs << argIn;
            EMIT(info(argIn, "File Continued"));
        }
        else if (QQFileInfo::tryIsDir(argIn))
        {
            EMIT(info(argIn, "Expanding Directory"));
            QQDir dir(argIn);
            QQStringList fileNames = dir.entryList(QDir::Files, QDir::NoSort);
            DUMP << fileNames;
            if ( ! fileNames.isEmpty())
            {
                ExpandDirResult edr;
                edr.dir = dir;
                edr.firstFileName = fileNames.first();
                edr.fileCount = fileNames.count();
                mExpandDirResultList << edr;
            }
            foreach (QQString fileName, fileNames)
            {
                QQFileInfo fi(dir, fileName);
                expandedArgs << fi.absoluteFilePath();
                EMIT(info(fi.absoluteFilePath(), "File Expanded"));
            }
        }
        else
        {
            ignoredArgs << argIn;
            WARN << argIn << "not file or dir";
            EMIT(warning(argIn, "Not Recognized"));
        }
    }
    mRemainingArgumentList = ignoredArgs;
    mPositionalArgumentList = expandedArgs;
    TRACEQFI << expandedArgs.size() << "Output Files:";
    dumpPositionalArgs();
}

void CommandLine::dump()
{
    DUMP << ">>>CommandLine:";
    DUMP << "===exeArgumentList:";
    foreach (QString exeArg, cmExeArgumentList)
        DUMP << "  " << exeArg;
    DUMP << "---exeFileInfo:" << mExeFileInfo;
    DUMP << "---positionalArgumentList:";
    dumpPositionalArgs();
    DUMP << "---Settings:";
}


void CommandLine::expandFileArguments(const QChar trigger)
{
    TRACEQFI << trigger;
    QQStringList workingArgList;
    foreach (QQString arg, mRemainingArgumentList)
    {
        if (arg.startsWith(trigger))
        {
            QQFileInfo argFileInfo(arg.mid(1));
            TRACE << "Expanding" << argFileInfo.absoluteFilePath() << argFileInfo.attributes();
            WEXPECT(argFileInfo.exists());
            WEXPECT(argFileInfo.isReadable());
            WEXPECT(argFileInfo.isFile());
            if (argFileInfo.tryIsFile())
            {
                EMIT(info(argFileInfo.absoluteFilePath(), "Processing"));
                QQStringList expanded = readTxtFileArguments(argFileInfo);
                TRACE << expanded;
                workingArgList << expanded;
            }
            else
            {
                EMIT(warning(argFileInfo.absoluteFilePath(), "Not Readable"));
            }
        }
        else
        {
            EMIT(info(arg, "Continued"));
            workingArgList << arg;
        }
    }
    mRemainingArgumentList = workingArgList;
}

void CommandLine::extractDirectiveArguments()
{
    TRACEFN;
    TODO(it)
}

void CommandLine::parseQtOptions()
{
    TRACEFN;
    QCommandLineParser parser;
    NEEDDO(Extract from parser)
}

void CommandLine::stripSettings(const MultiName &prefix, const QChar &trigger)
{
    TRACEQFI << prefix() << trigger;
    QQStringList remainingArgs;
    while (mRemainingArgumentList.notEmpty())
    {
        QQString arg = mRemainingArgumentList.takeFirst();
        if (arg.startsWith(trigger))
            parseSettingArgument(arg, prefix);
        else
            remainingArgs << arg;
    }
    mRemainingArgumentList = remainingArgs;
}

void CommandLine::parseSettingArgument(const QQString &arg,
                                      const MultiName &prefix)
{
    TRACEQFI << arg << prefix();
    QQStringList qsl = arg.split(QQChar('='));
    MultiName key = qsl.first().mid(1);
    key.prepend(prefix);
    Settings::Valu valu = (qsl.count() > 1) ? qsl[1] : "true";
    TRACE << key() << "=" << valu;
    mSettings.set(key, valu);
    EMIT(info(QString("%1={%2}").arg(key).arg(valu), "Added"));
}

QQStringList CommandLine::readTxtFileArguments(const QQFileInfo &argFileInfo)
{
    TRACEQFI << argFileInfo.absoluteFilePath() << argFileInfo.attributes();
    QQStringList workingArgs;
    QFile file(argFileInfo.absoluteFilePath(), this);
    EXPECT(file.open(QIODevice::ReadOnly | QIODevice::Text));
    WEXPECT(file.isReadable());

    while ( ! file.atEnd())
    {
        QByteArray fileLine = file.readLine().simplified();
        TRACE << "fileLine: {>" << fileLine << "<}";
        if (fileLine.isEmpty() || fileLine.startsWith('#'))
            continue;
        workingArgs << QQString(fileLine);
        EMIT(info(QQString(fileLine), "Expanded"));
    }
    TRACE << file.fileName() << "workingArgs" << workingArgs;
    return workingArgs;
}

void CommandLine::dumpPositionalArgs() const
{
    int nArgs = mPositionalArgumentList.size();
    DUMP << "eirExe : CommandLine PositionalArgs n=" << nArgs;
    for (int index=0; index < nArgs; ++index)
        DUMP << "  " << index << mPositionalArgumentList[index];
}

