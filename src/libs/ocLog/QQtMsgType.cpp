#include "QQtMsgType.h"

#include <eirXfr/Debug.h>

/* --------------------- static ------------------------- */

bool QQtMsgType::isValid() const
{
    Severity sev = severity();
    return sev > $null && sev < $past;
}

bool QQtMsgType::greater(const QQtMsgType other)
{
    QQtMsgType::Severity itSeverity = severity(it());
    QQtMsgType::Severity otherSeverity = severity(other);
    bool result = itSeverity > otherSeverity;
    //TRACEQFI << other << int(itSeverity) << int(otherSeverity) << result;
    return result;
}

QQtMsgType::Severity QQtMsgType::severity(const QQtMsgType aQMT)
{
    Severity result=$null;
    switch (aQMT())
    {
    case QtDebugMsg:        result = Trace;     break;
    case QtInfoMsg:         result = Info;      break;
    case QtWarningMsg:      result = Warn;      break;
    case QtCriticalMsg:     result = Error;     break;
    case QtFatalMsg:        result = Assert;    break;
    default:                result = $null;     break;
    }
    return result;
}

QQString QQtMsgType::severityName(const QQtMsgType aQMT)
{
    QQString result("{unknown}");
    switch (severity(aQMT))
    {
    case Info:              result = "Info";    break;
    case Trace:             result = "Trace";   break;
    case Warn:              result = "Warn";    break;
    case Error:             result = "Error";   break;
    case Assert:            result = "Assert";  break;
    case $null:             result = "$null";   break;
    default:                /* Leave unknown */ break;
    }
    return result;
}

QQChar QQtMsgType::prefix(const QQtMsgType aQMT)
{
    QQChar result('?');
    switch (aQMT())
    {
    case QtDebugMsg:        result = '>';     break;
    case QtInfoMsg:         result = '-';     break;
    case QtWarningMsg:      result = '*';     break;
    case QtCriticalMsg:     result = '#';     break;
    case QtFatalMsg:        result = '$';     break;
    default:    /* Leave '?' */               break;
    }
    return result;
}

QQString QQtMsgType::name(const QQtMsgType aQMT)
{
    QQString result = prefix(aQMT);
    switch (aQMT())
    {
    case QtDebugMsg:        result.append("Trace");     break;
    case QtInfoMsg:         result.append("Info ");     break;
    case QtWarningMsg:      result.append("Warn ");     break;
    case QtCriticalMsg:     result.append("Error");     break;
    case QtFatalMsg:        result.append("Fatal");     break;
    default:                result.append("$null");     break;
    }
    return result;
}


QQString QQtMsgType::toInfoString() const
{
    return QQString("%1 (%2)");
}

QQString QQtMsgType::toDebugString() const
{
    return QQString("{QQtMsgType: %1%2 (%3) Severity=%4 (%5) }")
            .arg(prefix()).arg(name()).arg(value())
            .arg(severityName()).arg(severity());
}

QDebug operator << (QDebug dbg, const QQtMsgType mt)
{
    dbg << mt.toDebugString(); return dbg;
}
