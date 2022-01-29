#include "LogItem.h"

class LogItemData : public QSharedData
{
public:

};

LogItem::LogItem()
    : data(new LogItemData)
    , mUid(true)
{

}

LogItem::LogItem(const LogItem &rhs)
    : data{rhs.data}
    , mUid(rhs.uid())
{

}

LogItem &LogItem::operator=(const LogItem &rhs)
{
    if (this != &rhs)
        data.operator=(rhs.data), mUid = rhs.uid();
    return *this;
}

LogItem::~LogItem()
{

}
