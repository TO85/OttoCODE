// file: {EIRC2 Repo}./src/libs/eirExe/CommandLine.h
#pragma once
#include "eirExe.h"

#include <QObject>

#include <QCommandLineParser>
#include <QCommandLineOption>
#include <QDir>
#include <QFileInfoList>
//#include <QStateMachine>
class QCommandLineParser;

#include <eirType/MultiName.h>
#include <eirType/Sortable.h>
#include <eirType/QQFileInfo.h>
#include <eirType/QQFileInfoList.h>
#include <eirType/QQString.h>
#include <eirType/QQStringList.h>
#include <eirType/QQStringStdList.h>

#include "AppSupport.h"

#include "Settings.h"

#include "../../version.h"

#include "SupporterInterface.h"


class EIREXE_EXPORT CommandLine : public QObject, public SupporterInterface
{
    Q_OBJECT
public:
    struct ExpandDirResult
    {
        QQDir dir;
        QQString firstFileName;
        int fileCount;
    };
    typedef QList<ExpandDirResult> ExpandDirResultList;

public:
    explicit CommandLine(QObject *parent = nullptr);
    ExpandDirResultList expandDirResults() const;
    int positionalArgumentSize() const;
    QQStringList positionalArgumentList() const;
    QQString firstPositionalArgument() const;
    QQString takePositionalArgument();
    int positionalArgumentsTaken() const;
    const QQStringList exeArguments(bool withNumbers=false) const;
    const QQFileInfo exeFileInfo() const;

public slots:
    void process();
    void dump();
    void dumpPositionalArgs() const;

signals:
    void constructed(void);
    void info(const QString what, const QString why);
    void warning(const QString what, const QString why);

protected slots:
    void extractDirectiveArguments();
    void stripSettings(const MultiName &prefix=MultiName(), const QChar &trigger=QChar('/'));
    void expandDirectories(const int recurseDepth=-1);

protected:
    void expandFileArguments(const QChar trigger=QChar('@'));
    void parseQtOptions();
    void parseSettingArgument(const QQString &arg, const MultiName &prefix=MultiName());
    QQStringList readTxtFileArguments(const QQFileInfo &argFileInfo);


protected:
    virtual StatusMessage doInitialize()    { return StatusMessage(); }
    virtual StatusMessage doPrepare()       { return StatusMessage(); }
    virtual StatusMessage doOptions()       { return StatusMessage(); }
    virtual StatusMessage doSettings()      { return StatusMessage(); }
    virtual StatusMessage doFinalize()      { return StatusMessage(); }
    virtual StatusMessage doStart()         { return StatusMessage(); }
    virtual StatusMessage doShutdown()      { return StatusMessage(); }


private slots:

private:
    const QQStringList cmExeArgumentList;
    QQFileInfo mExeFileInfo;
    QQStringList mRemainingArgumentList;
    ExpandDirResultList mExpandDirResultList;
    QQStringList mPositionalArgumentList;
    int mPositionalArgumentsTaken=0;
    Settings mSettings;
};
