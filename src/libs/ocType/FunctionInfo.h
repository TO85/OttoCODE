#pragma once
#include "ocType.h"

#include <QSharedDataPointer>

class FunctionInfoData;

class OCTYPE_EXPORT FunctionInfo
{
public:
    FunctionInfo();
    FunctionInfo(const char * psz, const QString & funcFile=QString(), const int funcLine=0);
    FunctionInfo(const QString & qs);
    FunctionInfo(const FunctionInfo &);
    FunctionInfo &operator=(const FunctionInfo &);
    ~FunctionInfo();

public:
    const QString &QFuncInfo() const;
    const QString &ClassName() const;
    const QString &FunctionName() const;
    const QStringList &ArgNames() const;


private:
    void set(const char * psz) { set(QString(psz)); }
    void set(const QString & qs);
    void process();
    void qFuncInfo(const QString &qFnI);
    void className(const QString &clsName);
    void functionName(const QString &fnName);
    void argumentNames(const QStringList &argNames);
    void funcFileName(const QString &fnfiName);
    void funcFileLine(const int &fnfiLine);

protected:

private:
    QSharedDataPointer<FunctionInfoData> data;
};

