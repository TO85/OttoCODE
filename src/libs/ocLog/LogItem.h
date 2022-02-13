#pragma once

#include <QSharedDataPointer>
class LogItemData;

#include <Uid>

class LogLevel;
class FunctionInfo;

class LogItem
{
public:
    LogItem(const QWORD level, char * qFuncInfo);
    LogItem();
    LogItem(const LogItem &);
    LogItem &operator=(const LogItem &);
    ~LogItem();

public:
    QWORD level() const;
    QWORD level(const QWORD lvl);
    FunctionInfo qFuncInfo() const;
    FunctionInfo qFuncInfo(const char * fni);

private:
    QSharedDataPointer<LogItemData> data;
};

