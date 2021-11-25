//! @file LogItem.h in {torc repo}./src/lib/toLogCore
#pragma once
#include "toLogCore.h"

#include <QSharedDataPointer>

class LogItemData;

class TOLOGCORE_EXPORT LogItem
{
public:
    LogItem();
    LogItem(const LogItem &);
    LogItem &operator=(const LogItem &);
    ~LogItem();

private:
    QSharedDataPointer<LogItemData> data;
};

