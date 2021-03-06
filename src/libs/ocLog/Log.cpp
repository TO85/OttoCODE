#include "Log.h"

#include <QCoreApplication>
#include <QMetaEnum>
#include <QMetaObject>

#include <KeySeg>
#include <ObjectHelper>

Log::Log() {;}

#if 1

KeySeg Log::severityKey(const Severity value)
{
    return enumName<Log::Severity>(value);
}

Log::Severity Log::severityValue(const char * key)
{
    return enumValue<Log::Severity>(key);
}

#else
KeySeg Log::severityKey(const Severity value) const
{
    const QMetaObject logMetaObject = staticMetaObject;
    const int severityIndex = logMetaObject.indexOfEnumerator("Severity");
    if (severityIndex < 0) return KeySeg();                            /* /====\ */
    QMetaEnum severityMetaEnum = logMetaObject.enumerator(severityIndex);
    return KeySeg(severityMetaEnum.valueToKey(value));
}

Log::Severity Log::severityValue(const KeySeg &key) const
{
    const QMetaObject logMetaObject = staticMetaObject;
    const int severityIndex = logMetaObject.indexOfEnumerator("Severity");
    if (severityIndex < 0) return $nullSeverity;                            /* /====\ */
    QMetaEnum severityMetaEnum = logMetaObject.enumerator(severityIndex);
    return Severity(severityMetaEnum.keyToValue(key.toQString().toLocal8Bit()));
}
#endif

QtMsgType Log::severityMsgType(const Severity value)
{
    switch (value)
    {
    case Detail:        return QtInfoMsg;
    case Dump:          return QtDebugMsg;
    case Trace:         return QtDebugMsg;
    case Info:          return QtInfoMsg;
    case Progress:      return QtInfoMsg;
    case Warning:       return QtWarningMsg;
    case WExpect:       return QtWarningMsg;
    case Severe:        return QtWarningMsg;
    case Expect:        return QtWarningMsg;
    case Critical:      return QtCriticalMsg;
    case Assert:        return QtCriticalMsg;
    case System:        return QtSystemMsg;
    case Nuclear:       return QtSystemMsg;
    default:            return QtMsgType(-1);
    }
}


