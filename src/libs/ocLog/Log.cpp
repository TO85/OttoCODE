#include "Log.h"

#include <QCoreApplication>
#include <QMetaEnum>
#include <QMetaObject>

#include <KeyItem>

Log::Log() : QObject{qApp} {;}

KeyItem Log::severityKey(const Severity value) const
{
    const QMetaObject logMetaObject = staticMetaObject;
    const int severityIndex = logMetaObject.indexOfEnumerator("Severity");
    if (severityIndex < 0) return KeyItem();                            /* /====\ */
    QMetaEnum severityMetaEnum = logMetaObject.enumerator(severityIndex);
    return KeyItem(severityMetaEnum.valueToKey(value));
}

Log::Severity Log::severityValue(const KeyItem &key) const
{
    const QMetaObject logMetaObject = staticMetaObject;
    const int severityIndex = logMetaObject.indexOfEnumerator("Severity");
    if (severityIndex < 0) return $nullSeverity;                            /* /====\ */
    QMetaEnum severityMetaEnum = logMetaObject.enumerator(severityIndex);
    return Severity(severityMetaEnum.keyToValue(key.toQString().toLocal8Bit()));
}

QtMsgType Log::severityMsgType(const Severity value) const
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


