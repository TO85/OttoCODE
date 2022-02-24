#pragma once
#include "ocLog.h"

#include <QSharedDataPointer>
class LogItemData;

#include <QList>

#include <Uid>

class LogLevel;
class FunctionInfo;

class OCLOG_EXPORT LogItem
{
public:
    typedef QList<LogItem> List;

public:
    LogItem(const QWORD level, char * qFuncInfo);
    LogItem();
    LogItem(const LogItem &);
    LogItem &operator=(const LogItem &);
    ~LogItem();
    void ctor();

public:
    QWORD level() const;
    QWORD level(const QWORD lvl);
    FunctionInfo qFuncInfo() const;
    FunctionInfo qFuncInfo(const char * qfi);

private:
    QSharedDataPointer<LogItemData> data;
};

