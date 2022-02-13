#include "LogItem.h"

#include <FunctionInfo>

#include "LogLevel.h"

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
    Uid & uid() const;
    Uid & uid(const Uid ui) const;
    QWORD logLevel() const;
    QWORD logLevel(QWORD newLogLevel);
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

QWORD LogItem::level() const
{
    return data ? data->logLevel() : 0;
}

QWORD LogItem::level(const QWORD lvl)
{
    return data ? data->logLevel(lvl) : 0;
}

SQWORD LogItemData::utcMsec() const
{
    return dmUtcMsec;
}

void LogItemData::utcMsec(SQWORD newUtcMsec)
{
    dmUtcMsec = newUtcMsec;
}

QWORD LogItemData::logLevel() const
{
    return dmLogLevel;
}

QWORD LogItemData::logLevel(QWORD newLogLevel)
{
    return dmLogLevel = newLogLevel;
}

const FunctionInfo &LogItemData::functionInfo() const
{
    return dmFunctionInfo;
}

void LogItemData::functionInfo(const FunctionInfo &newFunctionInfo)
{
    dmFunctionInfo = newFunctionInfo;
}

const Uid & LogItemData::uid() const
{
    return dmLogItemUid;
}

void LogItemData::uid(const Uid &newUid)
{
    dmLogItemUid = newUid;
}
