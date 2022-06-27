#include "QQDir.h"

QQString QQDir::lastPath() const
{
    const QQString tPath = path();
    return tPath.isEmpty() ? QQString() : path().split('/').last();
}

QDir QQDir::toQDir() const
{
    return (QDir)it();
}

QVariant QQDir::toVariant() const
{
    QVariant result;
    result.setValue(toQDir());
    return result;
}

bool QQDir::isNull() const
{
    return QDir::currentPath() == path();
}

QQString QQDir::attributes() const
{
    QString result = isAbsolute() ? "Absolute" : "Relative";
    result += exists() ? "Exists" : "NOTexists";
    result += isEmpty() ? "Empty" : "NotEmpty";
    result += isReadable() ? "Readable" : "NotReadable";
    result += isRoot() ? "Root" : "NotRoot";
    return result;
}

QQString QQDir::toDebugString() const
{
    if (isNull())
        return "{QQDir: null}";
    else
        return QString("{QQDir: >%1 %2<}").arg(path(), attributes());
}


bool operator <  (const QQDir &lhs, const QQDir &rhs)
{
    return lhs.absolutePath() < rhs.absolutePath();
}

bool operator == (const QQDir &lhs, const QQDir &rhs)
{
    return lhs.absolutePath() < rhs.absolutePath();
}

/* ------------------- extern ----------------------- */

QDebug operator<<(QDebug dbg, const QQDir & dir)
{
    dbg << dir.toDebugString();
    return dbg;
}
