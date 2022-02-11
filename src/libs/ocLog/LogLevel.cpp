#include "LogLevel.h"

LogLevel::LogLevel(const Value value, const Key &key, const Log::Severity severity)
    : mValue(value), mKey(key), mSeverity(severity) {;}

/* -------------------- sub-class Set ---------------------- */

LogLevel::Set::Set()
{
    if (isNull()) initialize();
}

bool LogLevel::Set::isNull() const
{
    return mValueMap.isEmpty() || mKeyMap.isEmpty();
}

void LogLevel::Set::initialize()
{
    initializeBaseLevels();
    // TODO more
}

void LogLevel::Set::initializeBaseLevels()
{
    // TODO it
}

