#include "LogItem.h"

#include <QDateTime>

#include "../ocBase/Uid.h"

#include "LogLevel.h"

class LogItemData : public QSharedData
{
public:
    Uid             LogContextUid;
    LogLevel        Level;
    QDateTime       Timestamp;


};

LogItem::LogItem() : data(new LogItemData)
{

}

LogItem::LogItem(const LogItem &rhs) : data(rhs.data)
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
