#include "QQDir.h"

bool QQDir::isNull() const
{
    return it() == nullDir();
}

QString QQDir::lastPath() const
{
    const QString tPath = path();
    return tPath.isEmpty() ? QString() : tPath.split('/').last();
}

QString QQDir::attributes() const
{
    QString result = isAbsolute() ? "Absolute" : "Relative";
    result += exists() ? "Exists" : "NOTexists";
    result += isEmpty() ? "Empty" : "NotEmpty";
    result += isReadable() ? "Readable" : "NotReadable";
    result += isRoot() ? "Root" : "NotRoot";
    return result;
}

QDir QQDir::smNullDir = QQDir("/nul");

bool operator <  (const QQDir &lhs, const QQDir &rhs)
{
    return lhs.absolutePath() < rhs.absolutePath();
}

bool operator == (const QQDir &lhs, const QQDir &rhs)
{
    return lhs.absolutePath() < rhs.absolutePath();
}
