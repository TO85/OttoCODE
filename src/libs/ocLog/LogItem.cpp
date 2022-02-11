#include "LogItem.h"

#include <FunctionInfo>

class LogItemData : public QSharedData
{
public:
    Uid dmLogItemUid;
    Uid dmLogChannelUid;
    SQWORD dmUtcMsec=0;
    QWORD dmLogLevel=0;
    FunctionInfo dmFunctionInfo;


    const Uid &logItemUid() const;
    void logItemUid(const Uid &newUid);
    SQWORD utcMsec() const;
    void utcMsec(SQWORD newCurrentUtcMsec);
    QWORD logLevel() const;
    void logLevel(QWORD newLogLevel);
    const FunctionInfo &functionInfo() const;
    void functionInfo(const FunctionInfo &newFunctionInfo);
};

LogItem::LogItem(const QWORD aLevel, char *aQFuncInfo)
{
    level(aLevel);
    qFuncInfo(aQFuncInfo);
}

LogItem::LogItem()
    : data(new LogItemData)
{

}

LogItem::LogItem(const LogItem &rhs)
    : data{rhs.data}
{

}

LogItem &LogItem::operator=(const LogItem &rhs)
{
    if (this != &rhs)
        data.operator=(rhs.data);
    return *this;
}

LogItem::~LogItem()
{

}

SQWORD LogItemData::getCurrentUtcMsec() const
{
    return currentUtcMsec;
}

void LogItemData::currentUtcMsec(SQWORD newCurrentUtcMsec)
{
    currentUtcMsec = newCurrentUtcMsec;
}

QWORD LogItemData::getLogLevel() const
{
    return logLevel;
}

void LogItemData::logLevel(QWORD newLogLevel)
{
    logLevel = newLogLevel;
}

const FunctionInfo &LogItemData::getFunctionInfo() const
{
    return functionInfo;
}

void LogItemData::functionInfo(const FunctionInfo &newFunctionInfo)
{
    functionInfo = newFunctionInfo;
}

const Uid &LogItemData::getUid() const
{
    return uid;
}

void LogItemData::uid(const Uid &newUid)
{
    uid = newUid;
}
