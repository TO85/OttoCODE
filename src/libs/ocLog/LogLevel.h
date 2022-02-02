#pragma once
#include "ocLog.h"

#include <Key>

#include "Log.h"

class OCLOG_EXPORT LogLevel
{
public:
    LogLevel() {;}

private:
    QWORD nValue=0;
    Key mKey;
    Log::Severity mSeverity=Log::$nullSeverity;
};

