#include "LogItem.h"

#include <FunctionInfo>

class LogItemData : public QSharedData
{
public:
    Uid uid;
    SQWORD currentUtcMsec=0;
    QWORD logLevel=0;
    FunctionInfo functionInfo;
};

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
