#include "QQStringStdList.h"

#include <QtDebug>

#include <eirXfr/Debug.h>

QQStringStdList::QQStringStdList() {;}

QQStringStdList &QQStringStdList::operator =(const QQStringList &other)
{
    TRACEQFI << other;
    clear();
    for (QQString qqs : other) append(qqs);
    return *this;
}

QQString QQStringStdList::takeFirst()
{
    TRACEFN;
    iterator it = begin();
    QQString entry = *it;
    erase(it);
    return entry;
}

void QQStringStdList::clear()
{
    TRACEFN;
    std::list<QQString>::clear();
}

void QQStringStdList::append(const QQString &entry)
{
    TRACEQFI << entry;
    emplace_back(entry);
}

void QQStringStdList::prepend(const QQStringList &other)
{
    TRACEQFI << other;
    for (QQString entry : other) emplace_front(entry);
}

bool QQStringStdList::removeOne(const QQString &entry)
{
    TRACEQFI << entry;
    for (iterator it = begin(); it != end(); ++it)
        if (*it == entry)
        {
            erase(it);
            return true;
        }
    return false;
}

QQStringList QQStringStdList::toStringList() const
{
    TRACEFN;
    QQStringList qqsl;
    for (auto& entry: *this) qqsl << entry;
    return qqsl;
}

QString QQStringStdList::toDebugString() const
{
    QString dbgstr(QString::number(size()));
    for (auto& entry: *this)
        dbgstr.append(QString(" ,<%1>").arg(entry.string()));
    return dbgstr;
}

QDebug operator<<(QDebug dbg, const QQStringStdList &list)
{
    dbg << list.toDebugString();
    return dbg;
}
