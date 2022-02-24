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
    QString dmQFuncInfoAnteParen;
    QString dmQFuncInfoTwixParen;
    QString dmQFuncInfoPostParen;
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

void FunctionInfo::set(const QString &qs)
{
    qDebug() << Q_FUNC_INFO << qs;
    Q_ASSERT(data);
    data->dmQFuncInfo = qs;
    process();
}

void FunctionInfo::process()
{
    Q_ASSERT(data);
    const QString qfiString = data->QFuncInfo();
    const int openParen  = qfiString.indexOf('(');
    const int closeParen = qfiString.lastIndexOf(')');
    if ((openParen < 1) || (closeParen < openParen)) return;
    qDebug() << qfiString << qfiString.left(openParen)
             << qfiString.mid(openParen, closeParen-openParen)
             << qfiString.mid(closeParen);
    data->dmQFuncInfoAnteParen = qfiString.left(openParen);
    data->dmQFuncInfoTwixParen = qfiString.mid(openParen, closeParen-openParen);
    data->dmQFuncInfoPostParen = qfiString.mid(closeParen);


}

void FunctionInfo::processAnteParen(const QString &qs)
{
    qDebug() << Q_FUNC_INFO << qs;
    const int lastColonPair = qs.lastIndexOf("::");
    const int lastSpaceAnteParen = qs.lastIndexOf(' ');
    data->dmClassName = qs.mid(lastSpaceAnteParen+1, lastColonPair-lastSpaceAnteParen);
    data->dmFunctionName = qs.mid(lastColonPair+2);
    qDebug() << data->dmClassName << data->dmFunctionName;
}

void FunctionInfo::processTwixParen(const QString &qs)
{
    qDebug() << Q_FUNC_INFO << qs;

}

void FunctionInfo::processPostParen(const QString &qs)
{
    qDebug() << Q_FUNC_INFO << qs;

}

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
