#include "FunctionInfo.h"

#include <QFileInfo>
#include <QString>
#include <QStringList>

#include <Millisecond>
#include <Uid>

class FunctionInfoData : public QSharedData
{
public:
    QString dmQFuncInfo;
    QString dmClassName;
    QString dmFunctionName;
    QStringList dmArgNames;
    // TODO more
    const QString &QFuncInfo() const;
    void QFuncInfo(const QString &newDmQFuncInfo);
    const QString &ClassName() const;
    void ClassName(const QString &newDmClassName);
    const QString &FunctionName() const;
    void FunctionName(const QString &newDmFunctionName);
    const QStringList &ArgNames() const;
    void ArgNames(const QStringList &newDmArgNames);
};

FunctionInfo::FunctionInfo() : data(new FunctionInfoData) {;}
FunctionInfo::FunctionInfo(const char *psz) : data(new FunctionInfoData) { set(psz); }
FunctionInfo::FunctionInfo(const QString &qs) : data(new FunctionInfoData) { set(qs); }
FunctionInfo::FunctionInfo(const FunctionInfo &rhs) : data{rhs.data} {;}
FunctionInfo::~FunctionInfo() {;}

FunctionInfo &FunctionInfo::operator=(const FunctionInfo &rhs)
{
    if (this != &rhs)
        data.operator=(rhs.data);
    return *this;
}

const QString &FunctionInfoData::QFuncInfo() const
{
    return dmQFuncInfo;
}

void FunctionInfoData::QFuncInfo(const QString &newDmQFuncInfo)
{
    dmQFuncInfo = newDmQFuncInfo;
}

const QString &FunctionInfoData::ClassName() const
{
    return dmClassName;
}

void FunctionInfoData::ClassName(const QString &newDmClassName)
{
    dmClassName = newDmClassName;
}

const QString &FunctionInfoData::FunctionName() const
{
    return dmFunctionName;
}

void FunctionInfoData::FunctionName(const QString &newDmFunctionName)
{
    dmFunctionName = newDmFunctionName;
}

const QStringList &FunctionInfoData::ArgNames() const
{
    return dmArgNames;
}

void FunctionInfoData::ArgNames(const QStringList &newDmArgNames)
{
    dmArgNames = newDmArgNames;
}
