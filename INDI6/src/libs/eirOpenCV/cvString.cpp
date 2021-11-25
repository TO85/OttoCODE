#include "cvString.h"

#include <eirXfr/Debug.h>

cvString::cvString(const QString &qs)
{
    std::string stdString = qs.toStdString();
    cvString result(stdString);
    TRACEQFI << qs << QString::fromStdString(stdString) << stdString.size() << result << result.size();
    it() = result;
    DUMPVAL(it());
}

QString cvString::toString() const
{
    return QString::fromStdString(it());
}

QQString cvString::toDebugString() const
{
    return QQString("{cvString: >" + QString::fromStdString(it()) + "<}");
}

QDebug operator << (QDebug dbg, const cvString &cvs)
{
    dbg << cvs.toDebugString(); return dbg;
}
