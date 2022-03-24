#include "FunctionInfo.h"

#include <QStringList>

#include <Millisecond>
#include <QQFileInfo>
#include <QQString>
#include <Uid>

#include "internal/FunctionInfoData.h"


FunctionInfo::FunctionInfo() : data(new FunctionInfoData) {;}
FunctionInfo::FunctionInfo(const char *psz, const QString &funcFile, const int funcLine)
    : data(new FunctionInfoData) { funcFileName(funcFile), funcFileLine(funcLine); set(psz); }
FunctionInfo::FunctionInfo(const QString &qs) : data(new FunctionInfoData) { set(qs); }
FunctionInfo::FunctionInfo(const FunctionInfo &rhs) : data{rhs.data} {;}
FunctionInfo::~FunctionInfo() {;}
FunctionInfo &FunctionInfo::operator=(const FunctionInfo &rhs)
{
    if (this != &rhs)
        data.operator=(rhs.data);
    return *this;
}

void FunctionInfo::set(const QString &qs)
{
    qDebug() << Q_FUNC_INFO << qs;
    Q_ASSERT(data);
    data->dmQFuncInfo = qs;
}

void FunctionInfo::process()
{
    Q_ASSERT(data);
    data->process();
}

void FunctionInfo::funcFileName(const QString &fnfiName)
{
    Q_ASSERT(data);
    data->dmFuncFileInfo = QQFileInfo(fnfiName);
}

void FunctionInfo::funcFileLine(const int &fnfiLine)
{
    Q_ASSERT(data);
    data->dmFuncFileLine = fnfiLine;
}


