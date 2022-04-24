#pragma once
#include "ocExe.h"

#include <QProcessEnvironment>

#include <KeySegList>
#include <QQDir>

class OCEXE_EXPORT SysProcessEnv : public QProcessEnvironment
{
public:
    SysProcessEnv();

public:
    int keyCount() const;
    bool isValidKeyIndex(const int ix) const;
    KeySeg key(const int ix) const;
    KeySegList keyList() const;
    QString value(const int ix) const;
    int pathCount() const;
    bool isValidPathIndex(const int ix) const;
    QQDir pathDir(const int ix) const;
    QQDir::List pathDirList() const;

private:
    const QProcessEnvironment cmProcEnv = QProcessEnvironment::systemEnvironment();
    KeySegList mKeyList;
    QQDir::List mPathDirList;
};

//extern OCEXE_EXPORT SysProcessEnv *gspSysProcessEnv;
