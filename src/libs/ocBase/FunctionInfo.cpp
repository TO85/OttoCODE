#include "FunctionInfo.h"

#include <QFileInfo>
#include <QString>
#include <QStringList>

#include <Millisecond>
#include <Uid>

class FunctionInfoData : public QSharedData
{
public:
    Uid uid;
    Millisecond msec;
    Uid processUid;
    QFileInfo exeFilePath;
    QString qFuncInfo;
    QString className;
    QString functionName;
    QStringList argNames;
    // TODO more
};

FunctionInfo::FunctionInfo() : data(new FunctionInfoData)
{

}

FunctionInfo::FunctionInfo(const FunctionInfo &rhs)
    : data{rhs.data}
{

}

FunctionInfo &FunctionInfo::operator=(const FunctionInfo &rhs)
{
    if (this != &rhs)
        data.operator=(rhs.data);
    return *this;
}

FunctionInfo::~FunctionInfo()
{

}
