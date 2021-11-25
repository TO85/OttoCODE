#include "StatusMessage.h"

#include <eirXfr/Debug.h>


StatusMessage::StatusMessage(const QtMsgType qmt, QQString &msg, unsigned code)
    : mType(qmt)
    , mMessage(msg)
    , mCode(code)
    , mSet(true)
{
    TRACEQFI << mType << mMessage << mCode;
}

QQString StatusMessage::typeName() const
{
    switch (mType)
    {
    case QtDebugMsg:    return "-Debug";
    case QtInfoMsg:     return "-Info ";
    case QtWarningMsg:  return ">Warn ";
    case QtCriticalMsg: return "*Crit ";
    case QtFatalMsg:    return "#Fatal";
    default:            return "?Unkno";
    }
}

void StatusMessage::clear()
{
    TRACEQFI << mType << mMessage << mCode;
    mType = QtMsgType::QtDebugMsg, mMessage.clear(), mCode = 0, mSet.unset();
}

void StatusMessage::set(const QtMsgType qmt, QQString &msg, unsigned code, bool force)
{
    if (greater(qmt) || force)
        mType = qmt, mMessage = msg, mCode = code, mSet.set();
    TRACEQFI << mType << mMessage << mCode << force;
}

bool StatusMessage::greater(const QtMsgType qmt) const
{
    const int value[] = { 0, 2, 3, 4, 1 };
    return value[qmt] > value[mType];
}

