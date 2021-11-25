#pragma once
#include "eirExe.h"

#include <eirType/Boolean.h>
#include <eirType/QQString.h>

class StatusMessage
{
public:
    StatusMessage() = default;
    StatusMessage(const QtMsgType qmt, QQString &msg, unsigned code=0);
    StatusMessage(const StatusMessage &other) = default;
    ~StatusMessage() = default;
    StatusMessage &operator = (const StatusMessage &other) = default;

public:
    bool isSet() const { return mSet; }
    QtMsgType type() const { return mType; }
    QQString typeName() const;
    QQString message() const { return mMessage; }
    unsigned code() const { return mCode; }

public:
    void clear();

protected:
    void set(const QtMsgType qmt, QQString &msg, unsigned code=0, bool force=false);

private:
    bool greater(const QtMsgType qmt) const;

private:
    QtMsgType mType=QtMsgType::QtDebugMsg;
    QQString mMessage;
    unsigned mCode=0;
    Boolean mSet;
};

