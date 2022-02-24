#pragma once

#include "ocLog_global.h"

#include <TypeDefs>

class OCLOG_EXPORT ocLog
{
public:
    ocLog();
    static void info();
    static void staticCtor();
    static void quickTest();
};

Q_GLOBAL_STATIC(ocLog, gpLog);
