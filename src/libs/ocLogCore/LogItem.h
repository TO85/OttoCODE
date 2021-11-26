//! @file LogItem.h in {torc repo}./src/lib/ocLogCore
#pragma once
#include "ocLogCore.h"

#include <QSharedDataPointer>

class LogItemData;

class OCLOGCORE_EXPORT LogItem
{
public:
    LogItem();
    LogItem(const LogItem &);
    LogItem &operator=(const LogItem &);
    ~LogItem();

private:
    QSharedDataPointer<LogItemData> data;
};

