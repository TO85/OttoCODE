#include "ocLog.h"

#include <KeySeg>

#include "Log.h"

ocLog::ocLog()
{
    staticCtor();
    quickTest();
}

void ocLog::info()
{
}

void ocLog::staticCtor()
{

}

void ocLog::quickTest()
{
    Q_ASSERT(Log::Severity::Expect == Log::severityValue("Expect"));
    Q_ASSERT(KeySeg("Expect") == Log::severityKey(Log::Expect));
}
