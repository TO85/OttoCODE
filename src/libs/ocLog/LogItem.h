#pragma once

#include <QSharedDataPointer>

#include <Uid>

class LogItemData;

class LogItem
{
public:
    LogItem();
    LogItem(const LogItem &);
    LogItem &operator=(const LogItem &);
    ~LogItem();
    Uid uid() const { return mUid; }

private:
    QSharedDataPointer<LogItemData> data;
    Uid mUid;
};

