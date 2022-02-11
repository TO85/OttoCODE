#pragma once

#include <QSharedDataPointer>
class LogItemData;

#include <Uid>

class LogLevel;

class LogItem
{
public:
    LogItem(const QWORD level, char * qFuncInfo);
    LogItem();
    LogItem(const LogItem &);
    LogItem &operator=(const LogItem &);
    ~LogItem();

public:

private:
    QSharedDataPointer<LogItemData> data;
};

