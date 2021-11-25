//! @file LogLevel.h in {torc repo}./src/lib/toLogCore
#pragma once
#include "toLogCore.h"


class TOLOGCORE_EXPORT LogLevel
{
public:
    LogLevel();
    quint64 toUnsigned() const { return u64; }
    operator quint64 () const { return toUnsigned(); }

private:
    union
    {
        quint64     u64;
        quint64     Severity        : 8,
                    Subject         : 24,
                    Sequence        : 28,
                    SeverityDetail  : 4;
    };
};

